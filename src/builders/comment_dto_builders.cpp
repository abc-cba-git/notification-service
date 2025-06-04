#include "../../include/builders/comment_dto_builders.h"

CommentActionBuilder &CommentActionBuilder::setUserId(std::string userId) {
    if (userId.empty()) {
        throw std::invalid_argument("User ID cannot be empty");
    }

    this->userId = std::move(userId);

    return *this;
}

CommentActionBuilder &CommentActionBuilder::setTaskName(std::string taskName) {
    if (taskName.empty()) {
        throw std::invalid_argument("Task name cannot be empty");
    }

    this->taskName = std::move(taskName);

    return *this;
}

CommentActionBuilder &CommentActionBuilder::setCommentContent(std::string commentContent) {
    if (commentContent.empty()) {
        throw std::invalid_argument("Comment content cannot be empty");
    }

    this->commentContent = std::move(commentContent);

    return *this;
}

std::unique_ptr<CommentAction> CommentActionBuilder::build() {
    if (userId.empty() || taskName.empty() || commentContent.empty()) {
        throw std::runtime_error("Required fields are not set");
    }

    return std::make_unique<CommentAction>(std::move(userId), std::move(taskName), std::move(commentContent));
}