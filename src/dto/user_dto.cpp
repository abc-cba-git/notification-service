#include "../../include/dto/user_dto.h"
#include "../../include/builders/user_dto_builders.h"

NotificationStateUpdate::NotificationStateUpdate(
    std::string userId, const NotificationType notificationType, const bool state
) : userId(std::move(userId)), notificationType(notificationType), state(state) {}

std::string NotificationStateUpdate::getUserId() const {
    return userId;
}

NotificationType NotificationStateUpdate::getNotificationType() const {
    return notificationType;
}

bool NotificationStateUpdate::getState() const {
    return state;
}

std::unique_ptr<NotificationStateUpdate> NotificationStateUpdate::fromJson(const std::shared_ptr<Json::Value>& json) {
    return NotificationStateUpdateBuilder()
        .setUserId(json.operator*()["user_id"].asString())
        .setNotificationType(json.operator*()["notification_type"].asString())
        .setState(json.operator*()["state"].asBool())
        .build();
}