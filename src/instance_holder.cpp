#include "../include/sql/sqlite3_handler.h"
#include "../include/instance_holder.h"

std::shared_ptr<InstanceHolder> InstanceHolder::instance = nullptr;

InstanceHolder::InstanceHolder() :
    sqlHandler(SQLite3Handler("../database.db")),

    userService(UserService(sqlHandler)),
    emailService(EmailService("ZubMax82@yandex.ru", "whgsaxcnkivlmznp")),
    notificationService(NotificationService(userService, emailService)),
    projectService(ProjectService(notificationService)),
    taskService(TaskService(notificationService)),
    tagService(TagService(notificationService)),
    commentService(CommentService(notificationService)) {}

std::unique_ptr<UserService> InstanceHolder::getUserService() {
    return std::make_unique<UserService>(userService);
}

std::unique_ptr<EmailService> InstanceHolder::getEmailService() {
    return std::make_unique<EmailService>(emailService);
}

std::unique_ptr<NotificationService> InstanceHolder::getNotificationService() {
    return std::make_unique<NotificationService>(notificationService);
}

std::unique_ptr<ProjectService> InstanceHolder::getProjectService() {
    return std::make_unique<ProjectService>(projectService);
}

std::unique_ptr<TaskService> InstanceHolder::getTaskService() {
    return std::make_unique<TaskService>(taskService);
}

std::unique_ptr<TagService> InstanceHolder::getTagService() {
    return std::make_unique<TagService>(tagService);
}

std::unique_ptr<CommentService> InstanceHolder::getCommentService() {
    return std::make_unique<CommentService>(commentService);
}