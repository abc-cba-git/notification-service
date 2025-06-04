#include "../../include/services/task_service.h"

TaskService::TaskService(NotificationService &notificationService) : notificationService(notificationService) {}

void TaskService::notifyTaskCreation(std::string userId, std::string projectName, std::string taskName) const {
    notificationService.notify(
        std::move(userId), "Добавление задачи",
        std::format("Задач {} добавлена в проект {}", taskName, projectName)
    );
}
void TaskService::notifyTaskDeletion(std::string userId, std::string projectName, std::string taskName) const {
    notificationService.notify(
        std::move(userId), "Удаление задачи",
        std::format("Задач {} удалена из проекта {}", taskName, projectName)
    );
}

void TaskService::notifyTaskNameUpdate(
    std::string userId, std::string projectName, std::string taskName, std::string newTaskName
) const {
    notificationService.notify(
        std::move(userId), "Обновление имени задачи",
        std::format("Задача {} в проекте {} переименована в {}", taskName, projectName, newTaskName)
    );
}

void TaskService::notifyTaskDescriptionUpdate(
    std::string userId, std::string projectName, std::string taskName, std::string newTaskDescription
) const {
    notificationService.notify(
        std::move(userId), "Обновление описания задачи",
        std::format(
            "Описание задачи {} в проекте {} изменено на: {}",
            taskName, projectName, newTaskDescription
        )
    );
}

void TaskService::notifyTaskPriorityUpdate(
    std::string userId, std::string projectName, std::string taskName, std::string newTaskPriority
) const {
    notificationService.notify(
        std::move(userId), "Обновление приоритета задачи",
        std::format(
            "Приоритет задачи {} в проекте {} изменен на {}",
            taskName, projectName, newTaskPriority
        )
    );
}

void TaskService::notifyTaskStatusUpdate(
    std::string userId, std::string projectName, std::string taskName, std::string newTaskStatus
) const {
    notificationService.notify(
        std::move(userId), "Обновление статуса задачи",
        std::format(
            "Статус задачи {} в проекте {} изменен на {}",
            taskName, projectName, newTaskStatus
        )
    );
}

void TaskService::notifyTaskAssigneeUpdate(
    std::string userId, std::string projectName, std::string taskName, std::string newAssigneeName
) const {
    notificationService.notify(
        std::move(userId), "Обновление исполнителя задачи",
        std::format(
            "Исполнитель задачи {} в проекте {} установлен на {}",
            taskName, projectName, newAssigneeName
        )
    );
}

void TaskService::notifyTaskTagAddition(
    std::string userId, std::string projectName, std::string taskName, std::string tagName
) const {
    notificationService.notify(
        std::move(userId), "Добавление тега к задаче",
        std::format("К задаче {} в проекте {} добавлен тег {}", taskName, projectName, tagName)
    );
}

void TaskService::notifyTaskTagDeletion(
    std::string userId, std::string projectName, std::string taskName, std::string tagName
) const {
    notificationService.notify(
        std::move(userId), "Удаление тега из задачи",
        std::format("Из задачи {} в проекте {} удален тег {}", taskName, projectName, tagName)
    );
}