#include "../../include/controllers/user_controllers.h"

#include "../../include/instance_holder.h"
#include "../../include/dto/user_dto.h"

void NotificationStateController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto update = NotificationStateUpdate::fromJson(req->jsonObject());

    std::cout << update->getUserId() << ", " << std::to_string(static_cast<int>(update->getNotificationType())) << ", " << update->getState() << std::endl;

    InstanceHolder::getInstance()->getUserService()->setNotificationState(
        update->getUserId(), update->getNotificationType(), update->getState()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}