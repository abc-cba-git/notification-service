#include "../../include/controllers/project_controllers.h"
#include "../../include/instance_holder.h"
#include "../../include/dto/project_dto.h"

void ProjectCreationController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = ProjectAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getProjectService()->notifyProjectCreation(
        action->getUserId(), action->getProjectName()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}

void ProjectDeletionController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = ProjectAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getProjectService()->notifyProjectDeletion(
        action->getUserId(), action->getProjectName()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}

void ProjectMemberInvitationController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = ProjectMemberAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getProjectService()->notifyProjectMemberInvitation(
        action->getUserId(), action->getProjectName(), action->getMemberName()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}

void ProjectMemberKickController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {

    const auto action = ProjectMemberAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getProjectService()->notifyProjectMemberKick(
        action->getUserId(), action->getProjectName(), action->getMemberName()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}