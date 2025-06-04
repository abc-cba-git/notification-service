#include "../../include/dto/comment_dto.h"

#include "../../include/builders/comment_dto_builders.h"

CommentAction::CommentAction(
    std::string userId, std::string taskName, std::string commentContent
) : userId(std::move(userId)), taskName(std::move(taskName)), commentContent(std::move(commentContent)) {}

std::string CommentAction::getUserId() const {
    return userId;
}

std::string CommentAction::getTaskName() const {
    return taskName;
}

std::string CommentAction::getCommentContent() const {
    return commentContent;
}

std::unique_ptr<CommentAction> CommentAction::fromJson(const std::shared_ptr<Json::Value> &json) {
    return CommentActionBuilder()
        .setUserId(json.operator*()["user_id"].asString())
        .setTaskName(json.operator*()["task_name"].asString())
        .setCommentContent(json.operator*()["comment_content"].asString())
        .build();
}