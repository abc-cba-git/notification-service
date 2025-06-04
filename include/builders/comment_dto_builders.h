#ifndef COMMENT_DTO_BUILDERS_H
#define COMMENT_DTO_BUILDERS_H

#include <string>

#include "builder.h"
#include "../dto/comment_dto.h"

class CommentActionBuilder final : public Builder<CommentAction> {
    std::string userId{};
    std::string taskName{};
    std::string commentContent{};
public:
    CommentActionBuilder() = default;
    ~CommentActionBuilder() override = default;

    CommentActionBuilder& setUserId(std::string userId);
    CommentActionBuilder& setTaskName(std::string taskName);
    CommentActionBuilder& setCommentContent(std::string commentContent);
    std::unique_ptr<CommentAction> build() override;
};

#endif //COMMENT_DTO_BUILDERS_H