#include <stdexcept>

#include "../../include/builders/user_dto_builders.h"

NotificationStateUpdateBuilder& NotificationStateUpdateBuilder::setUserId(std::string userId) {
    if (userId.empty()) {
        throw std::invalid_argument("User ID cannot be empty");
    }

    this->userId = std::move(userId);

    return *this;
}

NotificationStateUpdateBuilder& NotificationStateUpdateBuilder::setNotificationType(
    const std::string& rawNotificationType
) {
    if (rawNotificationType.empty()) {
        throw std::invalid_argument("Notification type cannot be empty");
    }

    if (rawNotificationType == "EMAIL") {
        this->notificationType = NotificationType::EMAIL;
    } else {
        throw std::invalid_argument("invalid notification type: " + rawNotificationType);
    }

    return *this;
}

NotificationStateUpdateBuilder& NotificationStateUpdateBuilder::setState(bool state) {
    this->state = state;

    return *this;
}

std::unique_ptr<NotificationStateUpdate> NotificationStateUpdateBuilder::build() {
    if (userId.empty()) {
        throw std::runtime_error("Required fields are not set");
    }

    return std::make_unique<NotificationStateUpdate>(std::move(userId), notificationType, state);
}