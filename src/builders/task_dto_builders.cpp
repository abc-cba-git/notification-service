#include "../../include/builders/task_dto_builders.h"

std::unique_ptr<TaskAction> TaskActionBuilder::build() {
    if (userId.empty() || projectName.empty() || taskName.empty()) {
        throw std::runtime_error("Required fields are not set");
    }

    return std::make_unique<TaskAction>(std::move(userId), std::move(projectName), std::move(taskName));
}


TaskNameUpdateActionBuilder &TaskNameUpdateActionBuilder::setNewTaskName(std::string newTaskName) {
    if (newTaskName.empty()) {
        throw std::invalid_argument("New task name cannot be empty");
    }

    this->newTaskName = std::move(newTaskName);

    return *this;
}

std::unique_ptr<TaskNameUpdateAction> TaskNameUpdateActionBuilder::build() {
    if (userId.empty() || projectName.empty() || taskName.empty() || newTaskName.empty()) {
        throw std::runtime_error("Required fields are not set");
    }

    return std::make_unique<TaskNameUpdateAction>(
        std::move(userId), std::move(projectName), std::move(taskName), std::move(newTaskName)
    );
}


TaskDescriptionUpdateActionBuilder &TaskDescriptionUpdateActionBuilder::setNewTaskDescription(std::string newTaskDescription) {
    if (newTaskDescription.empty()) {
        throw std::invalid_argument("New task description cannot be empty");
    }

    this->newTaskDescription = std::move(newTaskDescription);

    return *this;
}

std::unique_ptr<TaskDescriptionUpdateAction> TaskDescriptionUpdateActionBuilder::build() {
    if (userId.empty() || projectName.empty() || taskName.empty() || newTaskDescription.empty()) {
        throw std::runtime_error("Required fields are not set");
    }

    return std::make_unique<TaskDescriptionUpdateAction>(
        std::move(userId), std::move(projectName), std::move(taskName), std::move(newTaskDescription)
    );
}


TaskPriorityUpdateActionBuilder &TaskPriorityUpdateActionBuilder::setNewTaskPriority(std::string newTaskPriority) {
    if (newTaskPriority.empty()) {
        throw std::invalid_argument("New task priority cannot be empty");
    }

    this->newTaskPriority = std::move(newTaskPriority);

    return *this;
}

std::unique_ptr<TaskPriorityUpdateAction> TaskPriorityUpdateActionBuilder::build() {
    if (userId.empty() || projectName.empty() || taskName.empty() || newTaskPriority.empty()) {
        throw std::runtime_error("Required fields are not set");
    }

    return std::make_unique<TaskPriorityUpdateAction>(
        std::move(userId), std::move(projectName), std::move(taskName), std::move(newTaskPriority)
    );
}


TaskStatusUpdateActionBuilder &TaskStatusUpdateActionBuilder::setNewTaskStatus(std::string newTaskStatus) {
    if (newTaskStatus.empty()) {
        throw std::invalid_argument("New task status cannot be empty");
    }

    this->newTaskStatus = std::move(newTaskStatus);

    return *this;
}

std::unique_ptr<TaskStatusUpdateAction> TaskStatusUpdateActionBuilder::build() {
    if (userId.empty() || projectName.empty() || taskName.empty() || newTaskStatus.empty()) {
        throw std::runtime_error("Required fields are not set");
    }

    return std::make_unique<TaskStatusUpdateAction>(
        std::move(userId), std::move(projectName), std::move(taskName), std::move(newTaskStatus)
    );
}


TaskAssigneeUpdateActionBuilder &TaskAssigneeUpdateActionBuilder::setNewTaskAssigneeName(
    std::string newTaskAssigneeName
) {
    if (newTaskAssigneeName.empty()) {
        throw std::invalid_argument("New task assignee name cannot be empty");
    }

    this->newTaskAssigneeName = std::move(newTaskAssigneeName);

    return *this;
}

std::unique_ptr<TaskAssigneeUpdateAction> TaskAssigneeUpdateActionBuilder::build() {
    if (userId.empty() || projectName.empty() || taskName.empty() || newTaskAssigneeName.empty()) {
        throw std::runtime_error("Required fields are not set");
    }

    return std::make_unique<TaskAssigneeUpdateAction>(
        std::move(userId), std::move(projectName), std::move(taskName), std::move(newTaskAssigneeName)
    );
}


TaskTagActionBuilder &TaskTagActionBuilder::setTagName(std::string tagName) {
    if (tagName.empty()) {
        throw std::invalid_argument("Tag name cannot be empty");
    }

    this->tagName = std::move(tagName);

    return *this;
}

std::unique_ptr<TaskTagAction> TaskTagActionBuilder::build() {
    if (userId.empty() || projectName.empty() || taskName.empty() || tagName.empty()) {
        throw std::runtime_error("Required fields are not set");
    }

    return std::make_unique<TaskTagAction>(
        std::move(userId), std::move(projectName), std::move(taskName), std::move(tagName)
    );
}