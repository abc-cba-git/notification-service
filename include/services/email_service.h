#ifndef EMAIL_SERVICE_H
#define EMAIL_SERVICE_H

#include <string>

class EmailService {
    std::string email;
    std::string password;

public:
    EmailService(std::string email, std::string password);
    ~EmailService() = default;

    void sendMessage(const std::string &recipientEmail, const std::string &subject, const std::string &content) const;
};

#endif //EMAIL_SERVICE_H