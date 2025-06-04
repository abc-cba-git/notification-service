#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H

#include "email_service.h"
#include "user_service.h"

class NotificationService {
    UserService& userService;
    EmailService& emailService;
public:
    NotificationService(UserService& userService, EmailService& emailService);
    ~NotificationService() = default;

    void notify(std::string userId, const std::string &subject, const std::string &notification) const;
};

#endif //NOTIFICATION_SERVICE_H