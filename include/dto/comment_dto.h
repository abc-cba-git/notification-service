#ifndef COMMENT_DTO_H
#define COMMENT_DTO_H

#include <string>
#include <json/value.h>

class CommentAction {
    std::string userId;
    std::string taskName;
    std::string commentContent;
public:
    CommentAction(std::string userId, std::string taskName, std::string commentContent);
    ~CommentAction() = default;

    [[nodiscard]] std::string getUserId() const;
    [[nodiscard]] std::string getTaskName() const;
    [[nodiscard]] std::string getCommentContent() const;

    static std::unique_ptr<CommentAction> fromJson(const std::shared_ptr<Json::Value>& json);
};

#endif //COMMENT_DTO_H