#ifndef USER_DTO_BUILDERS_H
#define USER_DTO_BUILDERS_H

#include <string>

#include "builder.h"
#include "../dto/user_dto.h"

class NotificationStateUpdateBuilder final : public Builder<NotificationStateUpdate> {
    std::string userId{};
    NotificationType notificationType{};
    bool state{};
public:
    NotificationStateUpdateBuilder() = default;
    ~NotificationStateUpdateBuilder() override = default;

    NotificationStateUpdateBuilder& setUserId(std::string userId);
    NotificationStateUpdateBuilder& setNotificationType(const std::string &rawNotificationType);
    NotificationStateUpdateBuilder& setState(bool state);
    std::unique_ptr<NotificationStateUpdate> build() override;
};

#endif //USER_DTO_BUILDERS_H