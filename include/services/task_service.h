#ifndef TASK_SERVICE_H
#define TASK_SERVICE_H

#include "notification_service.h"

class TaskService {
    NotificationService& notificationService;
public:
    explicit TaskService(NotificationService& notificationService);
    ~TaskService() = default;

    void notifyTaskCreation(std::string userId, std::string projectName, std::string taskName) const;
    void notifyTaskDeletion(std::string userId, std::string projectName, std::string taskName) const;
    void notifyTaskNameUpdate(
        std::string userId, std::string projectName, std::string taskName, std::string newTaskName
    ) const;
    void notifyTaskDescriptionUpdate(
        std::string userId, std::string projectName, std::string taskName, std::string newTaskDescription
    ) const;
    void notifyTaskPriorityUpdate(
        std::string userId, std::string projectName, std::string taskName, std::string newTaskPriority
    ) const;
    void notifyTaskStatusUpdate(
        std::string userId, std::string projectName, std::string taskName, std::string newTaskStatus
    ) const;
    void notifyTaskAssigneeUpdate(
        std::string userId, std::string projectName, std::string taskName, std::string newAssigneeName
    ) const;
    void notifyTaskTagAddition(std::string userId, std::string projectName, std::string taskName, std::string tagName) const;
    void notifyTaskTagDeletion(std::string userId, std::string projectName, std::string taskName, std::string tagName) const;
};

#endif //TASK_SERVICE_H