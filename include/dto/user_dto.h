#ifndef USER_DTO_H
#define USER_DTO_H

#include <string>
#include <json/value.h>

enum class NotificationType {
    EMAIL = 0
};

class NotificationStateUpdate {
    std::string userId;
    NotificationType notificationType;
    bool state;
public:
    NotificationStateUpdate(std::string userId, NotificationType notificationType, bool state);
    ~NotificationStateUpdate() = default;

    [[nodiscard]] std::string getUserId() const;
    [[nodiscard]] NotificationType getNotificationType() const;
    [[nodiscard]] bool getState() const;

    static std::unique_ptr<NotificationStateUpdate> fromJson(const std::shared_ptr<Json::Value>& json);
};

#endif //USER_DTO_H