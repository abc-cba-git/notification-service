#include "../../include/controllers/tag_controllers.h"
#include "../../include/instance_holder.h"
#include "../../include/dto/tag_dto.h"

void TagCreationController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = TagAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getTagService()->notifyTagCreation(
        action->getUserId(), action->getProjectName(), action->getTagName()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}

void TagDeletionController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = TagAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getTagService()->notifyTagDeletion(
        action->getUserId(), action->getProjectName(), action->getTagName()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}