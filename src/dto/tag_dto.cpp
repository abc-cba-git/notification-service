#include "../../include/dto/tag_dto.h"

#include "../../include/builders/tag_dto_builders.h"

TagAction::TagAction(
    std::string userId, std::string projectName, std::string tagName
) : userId(std::move(userId)), projectName(std::move(projectName)), tagName(std::move(tagName)) {}

std::string TagAction::getUserId() const {
    return userId;
}

std::string TagAction::getProjectName() const {
    return projectName;
}

std::string TagAction::getTagName() const {
    return tagName;
}

std::unique_ptr<TagAction> TagAction::fromJson(const std::shared_ptr<Json::Value> &json) {
    return TagActionBuilder()
        .setUserId(json.operator*()["user_id"].asString())
        .setProjectName(json.operator*()["project_name"].asString())
        .setTagName(json.operator*()["tag_name"].asString())
        .build();
}