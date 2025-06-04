#include "../../include/dto/project_dto.h"

#include "../../include/builders/project_dto_builders.h"

ProjectAction::ProjectAction(
    std::string userId, std::string projectName
) : userId(std::move(userId)), projectName(std::move(projectName)) {}

std::string ProjectAction::getUserId() const {
    return userId;
}

std::string ProjectAction::getProjectName() const {
    return projectName;
}

std::unique_ptr<ProjectAction> ProjectAction::fromJson(const std::shared_ptr<Json::Value> &json) {
    return ProjectActionBuilder()
        .setUserId(json.operator*()["user_id"].asString())
        .setProjectName(json.operator*()["project_name"].asString())
        .build();
}


ProjectMemberAction::ProjectMemberAction(std::string userId, std::string projectName, std::string memberName) :
    userId(std::move(userId)),
    projectName(std::move(projectName)),
    memberName(std::move(memberName)) {}

std::string ProjectMemberAction::getUserId() const {
    return userId;
}

std::string ProjectMemberAction::getProjectName() const {
    return projectName;
}

std::string ProjectMemberAction::getMemberName() const {
    return memberName;
}

std::unique_ptr<ProjectMemberAction> ProjectMemberAction::fromJson(const std::shared_ptr<Json::Value> &json) {
    return ProjectMemberActionBuilder()
        .setUserId(json.operator*()["user_id"].asString())
        .setProjectName(json.operator*()["project_name"].asString())
        .setMemberName(json.operator*()["member_name"].asString())
        .build();
}
