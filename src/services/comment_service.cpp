#include "../../include/services/comment_service.h"

CommentService::CommentService(NotificationService &notificationService) : notificationService(notificationService) {}

void CommentService::notifyCommentCreation(
    const std::string &userId, const std::string &taskName, const std::string &commentContent
) const {
    notificationService.notify(
        userId, "Добавление комментария",
        std::format("Добавлен комментарий на задачу '{}': {}", taskName, commentContent)
    );
}

void CommentService::notifyCommentDeletion(
    const std::string &userId, const std::string &taskName, const std::string &commentContent
) const {
    notificationService.notify(
        userId, "Удаление комментария",
        std::format("Удалён комментарий на задачу '{}': {}", taskName, commentContent)
    );
}