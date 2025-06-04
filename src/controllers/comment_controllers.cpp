#include "../../include/controllers/comment_controllers.h"

#include "../../include/instance_holder.h"
#include "../../include/dto/comment_dto.h"

void CommentCreationController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = CommentAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getCommentService()->notifyCommentCreation(
        action->getUserId(), action->getTaskName(), action->getCommentContent()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}

void CommentDeletionController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = CommentAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getCommentService()->notifyCommentDeletion(
        action->getUserId(), action->getTaskName(), action->getCommentContent()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}