#include "../../include/services/user_service.h"

UserService::UserService(SQLite3Handler &sqlHandler) : sqlHandler(sqlHandler) {
    sqlHandler.update("CREATE TABLE IF NOT EXISTS `states`(`user_id` VARCHAR(36), `notification_type` TINYINT, `state` TINYINT);");
    sqlHandler.update("CREATE TABLE IF NOT EXISTS `destinations`(`user_id` VARCHAR(36), `notification_type` VARCHAR(32), `destination` VARCHAR(256));");
}

void UserService::setNotificationState(std::string userId, NotificationType notificationType, const bool state) const {
    sqlHandler.update("DELETE FROM `states` WHERE `user_id`=:user_id AND `notification_type`=:notification_type;", {
        {":user_id", userId},
        {":notification_type", std::to_string(static_cast<int>(notificationType))}
    });
    sqlHandler.update("INSERT INTO `states`(`user_id`, `notification_type`, `state`) VALUES(:user_id, :notification_type, :state);", {
        {":user_id", userId},
        {":notification_type", std::to_string(static_cast<int>(notificationType))},
        {":state", state ? "1" : "0"}
    });
}

bool UserService::getNotificationState(std::string userId, NotificationType notificationType) const {
    const auto result = sqlHandler.fetch("SELECT `state` FROM `states` WHERE `user_id`=:user_id AND `notification_type`=:notification_type LIMIT 1;", {
        {":user_id", userId},
        {":notification_type", std::to_string(static_cast<int>(notificationType))}
    });

    return !result.empty() && result.front().at("state") == "1";
}

std::unique_ptr<std::string> UserService::getNotificationDestination(
    std::string userId, NotificationType notificationType
) const {
    const auto result = sqlHandler.fetch("SELECT `destination` FROM `destinations` WHERE `user_id`=:user_id AND `notification_type`=:notification_type LIMIT 1;", {
        {":user_id", userId},
        {":notification_type", std::to_string(static_cast<int>(notificationType))}
    });

    return result.empty() ? nullptr : std::make_unique<std::string>(result.front().at("destination"));
}
