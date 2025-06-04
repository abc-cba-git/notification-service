#include "../../include/controllers/task_controllers.h"
#include "../../include/instance_holder.h"
#include "../../include/dto/task_dto.h"

void TaskCreationController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = TaskAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getTaskService()->notifyTaskCreation(
        action->getUserId(), action->getProjectName(), action->getTaskName()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}

void TaskDeletionController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = TaskAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getTaskService()->notifyTaskDeletion(
        action->getUserId(), action->getProjectName(), action->getTaskName()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}

void TaskNameUpdateController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = TaskNameUpdateAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getTaskService()->notifyTaskNameUpdate(
        action->getUserId(), action->getProjectName(), action->getTaskName(), action->getNewTaskName()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}

void TaskDescriptionUpdateController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {

    const auto action = TaskDescriptionUpdateAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getTaskService()->notifyTaskNameUpdate(
        action->getUserId(), action->getProjectName(), action->getTaskName(), action->getNewTaskDescription()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}

void TaskPriorityUpdateController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = TaskPriorityUpdateAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getTaskService()->notifyTaskPriorityUpdate(
        action->getUserId(), action->getProjectName(), action->getTaskName(), action->getNewTaskPriority()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}

void TaskStatusUpdateController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = TaskStatusUpdateAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getTaskService()->notifyTaskStatusUpdate(
        action->getUserId(), action->getProjectName(), action->getTaskName(), action->getNewTaskStatus()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}

void TaskAssigneeUpdateController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = TaskAssigneeUpdateAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getTaskService()->notifyTaskNameUpdate(
        action->getUserId(), action->getProjectName(), action->getTaskName(), action->getNewTaskAssigneeName()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}

void TaskTagAdditionController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = TaskTagAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getTaskService()->notifyTaskTagAddition(
        action->getUserId(), action->getProjectName(), action->getTaskName(), action->getTagName()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}

void TaskTagDeletionController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback
) {
    const auto action = TaskTagAction::fromJson(req->jsonObject());

    InstanceHolder::getInstance()->getTaskService()->notifyTaskTagDeletion(
        action->getUserId(), action->getProjectName(), action->getTaskName(), action->getTagName()
    );

    callback(drogon::HttpResponse::newHttpResponse());
}