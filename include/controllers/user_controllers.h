#ifndef NOTIFICATION_CONTROLLERS_H
#define NOTIFICATION_CONTROLLERS_H

#include <drogon/HttpSimpleController.h>

class NotificationStateController final : public drogon::HttpSimpleController<NotificationStateController> {
public:
    void asyncHandleHttpRequest(
            const drogon::HttpRequestPtr &req, std::function<void (const drogon::HttpResponsePtr&)> &&callback
    ) override;

    PATH_LIST_BEGIN
        PATH_ADD("/notifications", drogon::Post);
    PATH_LIST_END
};

#endif //NOTIFICATION_CONTROLLERS_H