#include "../../include/services/email_service.h"

#include <iostream>
#include <curl/curl.h>

EmailService::EmailService(
    std::string email, std::string password
) : email(std::move(email)), password(std::move(password)) {}

void EmailService::sendMessage(
    const std::string& recipientEmail, const std::string& subject, const std::string& content
) const {
    curl_global_init(CURL_GLOBAL_DEFAULT);

    CURL* curl = curl_easy_init();

    if (!curl) {
        throw std::runtime_error("Failed to initialize CURL");
    }

    curl_easy_setopt(curl, CURLOPT_URL, "smtps://smtp.yandex.ru:465");
    curl_easy_setopt(curl, CURLOPT_USERNAME, email.c_str());
    curl_easy_setopt(curl, CURLOPT_PASSWORD, password.c_str());
    curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
    curl_easy_setopt(curl, CURLOPT_LOGIN_OPTIONS, "AUTH=LOGIN");

    const std::string from_header = "<" + email + ">";

    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from_header.c_str());

    curl_slist* recipients = nullptr;
    const std::string to_header = "<" + recipientEmail + ">";

    recipients = curl_slist_append(recipients, to_header.c_str());

    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

    curl_mime* mime = curl_mime_init(curl);

    curl_mimepart *part = curl_mime_addpart(mime);

    curl_mime_data(part, content.c_str(), CURL_ZERO_TERMINATED);
    curl_mime_type(part, "text/plain; charset=utf-8");

    curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime);

    curl_slist* headers = nullptr;

    headers = curl_slist_append(headers, ("From: " + email).c_str());
    headers = curl_slist_append(headers, ("To: " + recipientEmail).c_str());
    headers = curl_slist_append(headers, ("Subject: " + subject).c_str());

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    const CURLcode result = curl_easy_perform(curl);

    curl_slist_free_all(recipients);
    curl_slist_free_all(headers);
    curl_mime_free(mime);
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    if (result != CURLE_OK) {
        throw std::runtime_error(std::string("curl_easy_perform() failed: ") + curl_easy_strerror(result));
    }
}