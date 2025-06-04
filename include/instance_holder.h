#ifndef INSTANCE_HOLDER_H
#define INSTANCE_HOLDER_H

#include "services/comment_service.h"
#include "services/email_service.h"
#include "services/notification_service.h"
#include "services/project_service.h"
#include "services/tag_service.h"
#include "services/task_service.h"
#include "services/user_service.h"
#include "sql/sqlite3_handler.h"

class InstanceHolder {
    SQLite3Handler sqlHandler;

    UserService userService;
    EmailService emailService;
    NotificationService notificationService;
    ProjectService projectService;
    TaskService taskService;
    TagService tagService;
    CommentService commentService;

    static std::shared_ptr<InstanceHolder> instance;
public:
    InstanceHolder();
    ~InstanceHolder() = default;
    InstanceHolder(const InstanceHolder&) = delete;
    InstanceHolder& operator=(const InstanceHolder&) = delete;

    static void initialize() {
        instance = std::make_shared<InstanceHolder>();
    }

    static std::shared_ptr<InstanceHolder> getInstance() {
        return instance;
    }

    std::unique_ptr<UserService> getUserService();
    std::unique_ptr<EmailService> getEmailService();
    std::unique_ptr<NotificationService> getNotificationService();
    std::unique_ptr<ProjectService> getProjectService();
    std::unique_ptr<TaskService> getTaskService();
    std::unique_ptr<TagService> getTagService();
    std::unique_ptr<CommentService> getCommentService();
};

#endif //INSTANCE_HOLDER_H