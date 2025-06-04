#ifndef TASK_DTO_BUILDERS_H
#define TASK_DTO_BUILDERS_H

#include <string>

#include "builder.h"
#include "../dto/task_dto.h"
#include "project_dto_builders.h"

template<typename Derived>
class TaskActionBuilderBase : public ProjectActionBuilderBase<Derived> {
protected:
    std::string taskName{};

public:
    TaskActionBuilderBase() = default;
    ~TaskActionBuilderBase() override = default;

    Derived& setTaskName(std::string taskName) {
        if (taskName.empty()) {
            throw std::invalid_argument("Task name cannot be empty");
        }

        this->taskName = std::move(taskName);

        return static_cast<Derived&>(*this);
    }
};

class TaskActionBuilder final : public Builder<TaskAction>, public TaskActionBuilderBase<TaskActionBuilder> {
public:
    TaskActionBuilder() = default;
    ~TaskActionBuilder() override = default;

    std::unique_ptr<TaskAction> build() override;
};

class TaskNameUpdateActionBuilder final : public Builder<TaskNameUpdateAction>,
                                          public TaskActionBuilderBase<TaskNameUpdateActionBuilder> {
    std::string newTaskName{};
public:
    TaskNameUpdateActionBuilder() = default;
    ~TaskNameUpdateActionBuilder() override = default;

    TaskNameUpdateActionBuilder& setNewTaskName(std::string newTaskName);
    std::unique_ptr<TaskNameUpdateAction> build() override;
};

class TaskDescriptionUpdateActionBuilder final : public Builder<TaskDescriptionUpdateAction>,
                                                 public TaskActionBuilderBase<TaskDescriptionUpdateActionBuilder> {
    std::string newTaskDescription{};
public:
    TaskDescriptionUpdateActionBuilder() = default;
    ~TaskDescriptionUpdateActionBuilder() override = default;

    TaskDescriptionUpdateActionBuilder& setNewTaskDescription(std::string newTaskDescription);
    std::unique_ptr<TaskDescriptionUpdateAction> build() override;
};

class TaskPriorityUpdateActionBuilder final : public Builder<TaskPriorityUpdateAction>,
                                              public TaskActionBuilderBase<TaskPriorityUpdateActionBuilder> {
    std::string newTaskPriority{};
public:
    TaskPriorityUpdateActionBuilder() = default;
    ~TaskPriorityUpdateActionBuilder() override = default;

    TaskPriorityUpdateActionBuilder& setNewTaskPriority(std::string newTaskPriority);
    std::unique_ptr<TaskPriorityUpdateAction> build() override;
};

class TaskStatusUpdateActionBuilder final : public Builder<TaskStatusUpdateAction>,
                                            public TaskActionBuilderBase<TaskStatusUpdateActionBuilder> {
    std::string newTaskStatus{};
public:
    TaskStatusUpdateActionBuilder() = default;
    ~TaskStatusUpdateActionBuilder() override = default;

    TaskStatusUpdateActionBuilder& setNewTaskStatus(std::string newTaskStatus);
    std::unique_ptr<TaskStatusUpdateAction> build() override;
};

class TaskAssigneeUpdateActionBuilder final : public Builder<TaskAssigneeUpdateAction>,
                                              public TaskActionBuilderBase<TaskAssigneeUpdateActionBuilder> {
    std::string newTaskAssigneeName{};
public:
    TaskAssigneeUpdateActionBuilder() = default;
    ~TaskAssigneeUpdateActionBuilder() override = default;

    TaskAssigneeUpdateActionBuilder& setNewTaskAssigneeName(std::string newTaskAssigneeName);
    std::unique_ptr<TaskAssigneeUpdateAction> build() override;
};

class TaskTagActionBuilder final : public Builder<TaskTagAction>, public TaskActionBuilderBase<TaskTagActionBuilder> {
    std::string tagName{};
public:
    TaskTagActionBuilder() = default;
    ~TaskTagActionBuilder() override = default;

    TaskTagActionBuilder& setTagName(std::string tagName);
    std::unique_ptr<TaskTagAction> build() override;
};

#endif //TASK_DTO_BUILDERS_H