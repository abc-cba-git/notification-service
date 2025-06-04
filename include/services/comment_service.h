#ifndef COMMENT_SERVICE_H
#define COMMENT_SERVICE_H

#include "notification_service.h"

class CommentService {
    NotificationService& notificationService;
public:
    explicit CommentService(NotificationService& notificationService);
    ~CommentService() = default;

    void notifyCommentCreation(
        const std::string &userId, const std::string &taskName, const std::string& commentContent
    ) const;
    void notifyCommentDeletion(
        const std::string &userId, const std::string &taskName, const std::string& commentContent
    ) const;
};

#endif //COMMENT_SERVICE_H