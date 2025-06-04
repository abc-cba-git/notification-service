#include "../../include/services/notification_service.h"

NotificationService::NotificationService(
    UserService& userService, EmailService& emailService
) : userService(userService), emailService(emailService) {}

void NotificationService::notify(
    std::string userId, const std::string& subject, const std::string& notification
) const {
    if (const std::unique_ptr<std::string> email = userService.getNotificationDestination(
        std::move(userId), NotificationType::EMAIL
    ); email != nullptr) {
        emailService.sendMessage(*email, subject, notification);
    }
}