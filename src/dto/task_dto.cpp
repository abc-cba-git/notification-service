#include "../../include/dto/task_dto.h"
#include "../../include/builders/task_dto_builders.h"

TaskAction::TaskAction(
    std::string userId, std::string projectName, std::string taskName
) : userId(std::move(userId)), projectName(std::move(projectName)), taskName(std::move(taskName)) {}

std::string TaskAction::getUserId() const {
    return userId;
}

std::string TaskAction::getProjectName() const {
    return projectName;
}

std::string TaskAction::getTaskName() const {
    return taskName;
}

std::unique_ptr<TaskAction> TaskAction::fromJson(const std::shared_ptr<Json::Value> &json) {
    return TaskActionBuilder()
        .setUserId(json.operator*()["user_id"].asString())
        .setProjectName(json.operator*()["project_name"].asString())
        .setTaskName(json.operator*()["task_name"].asString())
        .build();
}


TaskNameUpdateAction::TaskNameUpdateAction(
    std::string userId, std::string projectName, std::string taskName, std::string newTaskName
) : userId(std::move(userId)),
    projectName(std::move(projectName)),
    taskName(std::move(taskName)),
    newTaskName(std::move(newTaskName)) {}

std::string TaskNameUpdateAction::getUserId() const {
    return userId;
}

std::string TaskNameUpdateAction::getProjectName() const {
    return projectName;
}

std::string TaskNameUpdateAction::getTaskName() const {
    return taskName;
}

std::string TaskNameUpdateAction::getNewTaskName() const {
    return newTaskName;
}

std::unique_ptr<TaskNameUpdateAction> TaskNameUpdateAction::fromJson(const std::shared_ptr<Json::Value> &json) {
    return TaskNameUpdateActionBuilder()
        .setUserId(json.operator*()["user_id"].asString())
        .setProjectName(json.operator*()["project_name"].asString())
        .setTaskName(json.operator*()["task_name"].asString())
        .setNewTaskName(json.operator*()["new_task_name"].asString())
        .build();
}


TaskDescriptionUpdateAction::TaskDescriptionUpdateAction(
    std::string userId, std::string projectName, std::string taskName, std::string newTaskDescription
) : userId(std::move(userId)),
    projectName(std::move(projectName)),
    taskName(std::move(taskName)),
    newTaskDescription(std::move(newTaskDescription)) {}

std::string TaskDescriptionUpdateAction::getUserId() const {
    return userId;
}

std::string TaskDescriptionUpdateAction::getProjectName() const {
    return projectName;
}

std::string TaskDescriptionUpdateAction::getTaskName() const {
    return taskName;
}

std::string TaskDescriptionUpdateAction::getNewTaskDescription() const {
    return newTaskDescription;
}

std::unique_ptr<TaskDescriptionUpdateAction> TaskDescriptionUpdateAction::fromJson(
    const std::shared_ptr<Json::Value> &json
) {
    return TaskDescriptionUpdateActionBuilder()
        .setUserId(json.operator*()["user_id"].asString())
        .setProjectName(json.operator*()["project_name"].asString())
        .setTaskName(json.operator*()["task_name"].asString())
        .setNewTaskDescription(json.operator*()["new_task_description"].asString())
        .build();
}


TaskPriorityUpdateAction::TaskPriorityUpdateAction(
    std::string userId, std::string projectName, std::string taskName, std::string newTaskPriority
) : userId(std::move(userId)),
    projectName(std::move(projectName)),
    taskName(std::move(taskName)),
    newTaskPriority(std::move(newTaskPriority)) {}

std::string TaskPriorityUpdateAction::getUserId() const {
    return userId;
}

std::string TaskPriorityUpdateAction::getProjectName() const {
    return projectName;
}

std::string TaskPriorityUpdateAction::getTaskName() const {
    return taskName;
}

std::string TaskPriorityUpdateAction::getNewTaskPriority() const {
    return newTaskPriority;
}

std::unique_ptr<TaskPriorityUpdateAction> TaskPriorityUpdateAction::fromJson(const std::shared_ptr<Json::Value> &json) {
    return TaskPriorityUpdateActionBuilder()
        .setUserId(json.operator*()["user_id"].asString())
        .setProjectName(json.operator*()["project_name"].asString())
        .setTaskName(json.operator*()["task_name"].asString())
        .setNewTaskPriority(json.operator*()["new_task_priority"].asString())
        .build();
}


TaskStatusUpdateAction::TaskStatusUpdateAction(
    std::string userId, std::string projectName, std::string taskName, std::string newTaskStatus
) : userId(std::move(userId)),
    projectName(std::move(projectName)),
    taskName(std::move(taskName)),
    newTaskStatus(std::move(newTaskStatus)) {}

std::string TaskStatusUpdateAction::getUserId() const {
    return userId;
}

std::string TaskStatusUpdateAction::getProjectName() const {
    return projectName;
}

std::string TaskStatusUpdateAction::getTaskName() const {
    return taskName;
}

std::string TaskStatusUpdateAction::getNewTaskStatus() const {
    return newTaskStatus;
}

std::unique_ptr<TaskStatusUpdateAction> TaskStatusUpdateAction::fromJson(const std::shared_ptr<Json::Value> &json) {
    return TaskStatusUpdateActionBuilder()
        .setUserId(json.operator*()["user_id"].asString())
        .setProjectName(json.operator*()["project_name"].asString())
        .setTaskName(json.operator*()["task_name"].asString())
        .setNewTaskStatus(json.operator*()["new_task_status"].asString())
        .build();
}


TaskAssigneeUpdateAction::TaskAssigneeUpdateAction(
    std::string userId, std::string projectName, std::string taskName, std::string newTaskAssigneeName
) : userId(std::move(userId)),
    projectName(std::move(projectName)),
    taskName(std::move(taskName)),
    newTaskAssigneeName(std::move(newTaskAssigneeName)) {}

std::string TaskAssigneeUpdateAction::getUserId() const {
    return userId;
}

std::string TaskAssigneeUpdateAction::getProjectName() const {
    return projectName;
}

std::string TaskAssigneeUpdateAction::getTaskName() const {
    return taskName;
}

std::string TaskAssigneeUpdateAction::getNewTaskAssigneeName() const {
    return newTaskAssigneeName;
}

std::unique_ptr<TaskAssigneeUpdateAction> TaskAssigneeUpdateAction::fromJson(const std::shared_ptr<Json::Value> &json) {
    return TaskAssigneeUpdateActionBuilder()
        .setUserId(json.operator*()["user_id"].asString())
        .setProjectName(json.operator*()["project_name"].asString())
        .setTaskName(json.operator*()["task_name"].asString())
        .setNewTaskAssigneeName(json.operator*()["new_task_assignee_name"].asString())
        .build();
}


TaskTagAction::TaskTagAction(
    std::string userId, std::string projectName, std::string taskName, std::string tagName
) : userId(std::move(userId)),
    projectName(std::move(projectName)),
    taskName(std::move(taskName)),
    tagName(std::move(tagName)) {}

std::string TaskTagAction::getUserId() const {
    return userId;
}

std::string TaskTagAction::getProjectName() const {
    return projectName;
}

std::string TaskTagAction::getTaskName() const {
    return taskName;
}

std::string TaskTagAction::getTagName() const {
    return tagName;
}

std::unique_ptr<TaskTagAction> TaskTagAction::fromJson(const std::shared_ptr<Json::Value> &json) {
    return TaskTagActionBuilder()
        .setUserId(json.operator*()["user_id"].asString())
        .setProjectName(json.operator*()["project_name"].asString())
        .setTaskName(json.operator*()["task_name"].asString())
        .setTagName(json.operator*()["tag_name"].asString())
        .build();
}