#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include "../dto/user_dto.h"
#include "../sql/sqlite3_handler.h"

class UserService {
    SQLite3Handler& sqlHandler;
public:
    explicit UserService(SQLite3Handler& sqlHandler);
    ~UserService() = default;

    void setNotificationState(std::string userId, NotificationType notificationType, bool state) const;
    [[nodiscard]] bool getNotificationState(std::string userId, NotificationType notificationType) const;
    [[nodiscard]] std::unique_ptr<std::string> getNotificationDestination(
        std::string userId, NotificationType notificationType
    ) const;
};

#endif //USER_SERVICE_H