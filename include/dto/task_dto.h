#ifndef TASK_DTO_H
#define TASK_DTO_H

#include <string>
#include <json/value.h>

class TaskAction {
    std::string userId;
    std::string projectName;
    std::string taskName;
public:
    TaskAction(std::string userId, std::string projectName, std::string taskName);
    ~TaskAction() = default;

    [[nodiscard]] std::string getUserId() const;
    [[nodiscard]] std::string getProjectName() const;
    [[nodiscard]] std::string getTaskName() const;

    static std::unique_ptr<TaskAction> fromJson(const std::shared_ptr<Json::Value>& json);
};

class TaskNameUpdateAction {
    std::string userId;
    std::string projectName;
    std::string taskName;
    std::string newTaskName;
public:
    TaskNameUpdateAction(std::string userId, std::string projectName, std::string taskName, std::string newTaskName);
    ~TaskNameUpdateAction() = default;

    [[nodiscard]] std::string getUserId() const;
    [[nodiscard]] std::string getProjectName() const;
    [[nodiscard]] std::string getTaskName() const;
    [[nodiscard]] std::string getNewTaskName() const;

    static std::unique_ptr<TaskNameUpdateAction> fromJson(const std::shared_ptr<Json::Value>& json);
};

class TaskDescriptionUpdateAction {
    std::string userId;
    std::string projectName;
    std::string taskName;
    std::string newTaskDescription;
public:
    TaskDescriptionUpdateAction(
        std::string userId, std::string projectName, std::string taskName, std::string newTaskDescription
    );
    ~TaskDescriptionUpdateAction() = default;

    [[nodiscard]] std::string getUserId() const;
    [[nodiscard]] std::string getProjectName() const;
    [[nodiscard]] std::string getTaskName() const;
    [[nodiscard]] std::string getNewTaskDescription() const;

    static std::unique_ptr<TaskDescriptionUpdateAction> fromJson(const std::shared_ptr<Json::Value>& json);
};

class TaskPriorityUpdateAction {
    std::string userId;
    std::string projectName;
    std::string taskName;
    std::string newTaskPriority;
public:
    TaskPriorityUpdateAction(
        std::string userId, std::string projectName, std::string taskName, std::string newTaskPriority
    );
    ~TaskPriorityUpdateAction() = default;

    [[nodiscard]] std::string getUserId() const;
    [[nodiscard]] std::string getProjectName() const;
    [[nodiscard]] std::string getTaskName() const;
    [[nodiscard]] std::string getNewTaskPriority() const;

    static std::unique_ptr<TaskPriorityUpdateAction> fromJson(const std::shared_ptr<Json::Value>& json);
};

class TaskStatusUpdateAction {
    std::string userId;
    std::string projectName;
    std::string taskName;
    std::string newTaskStatus;
public:
    TaskStatusUpdateAction(
        std::string userId, std::string projectName, std::string taskName, std::string newTaskStatus
    );
    ~TaskStatusUpdateAction() = default;

    [[nodiscard]] std::string getUserId() const;
    [[nodiscard]] std::string getProjectName() const;
    [[nodiscard]] std::string getTaskName() const;
    [[nodiscard]] std::string getNewTaskStatus() const;

    static std::unique_ptr<TaskStatusUpdateAction> fromJson(const std::shared_ptr<Json::Value>& json);
};

class TaskAssigneeUpdateAction {
    std::string userId;
    std::string projectName;
    std::string taskName;
    std::string newTaskAssigneeName;
public:
    TaskAssigneeUpdateAction(
        std::string userId, std::string projectName, std::string taskName, std::string newTaskAssigneeName
    );
    ~TaskAssigneeUpdateAction() = default;

    [[nodiscard]] std::string getUserId() const;
    [[nodiscard]] std::string getProjectName() const;
    [[nodiscard]] std::string getTaskName() const;
    [[nodiscard]] std::string getNewTaskAssigneeName() const;

    static std::unique_ptr<TaskAssigneeUpdateAction> fromJson(const std::shared_ptr<Json::Value>& json);
};

class TaskTagAction {
    std::string userId;
    std::string projectName;
    std::string taskName;
    std::string tagName;
public:
    TaskTagAction(
        std::string userId, std::string projectName, std::string taskName, std::string tagName
    );
    ~TaskTagAction() = default;

    [[nodiscard]] std::string getUserId() const;
    [[nodiscard]] std::string getProjectName() const;
    [[nodiscard]] std::string getTaskName() const;
    [[nodiscard]] std::string getTagName() const;

    static std::unique_ptr<TaskTagAction> fromJson(const std::shared_ptr<Json::Value>& json);
};

#endif //TASK_DTO_H