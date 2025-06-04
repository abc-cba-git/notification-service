#ifndef PROJECT_DTO_H
#define PROJECT_DTO_H

#include <string>
#include <json/value.h>

class ProjectAction {
    std::string userId;
    std::string projectName;
public:
    ProjectAction(std::string userId, std::string projectName);
    ~ProjectAction() = default;

    [[nodiscard]] std::string getUserId() const;
    [[nodiscard]] std::string getProjectName() const;

    static std::unique_ptr<ProjectAction> fromJson(const std::shared_ptr<Json::Value>& json);
};

class ProjectMemberAction {
    std::string userId;
    std::string projectName;
    std::string memberName;
public:
    ProjectMemberAction(std::string userId, std::string projectName, std::string memberName);
    ~ProjectMemberAction() = default;

    [[nodiscard]] std::string getUserId() const;
    [[nodiscard]] std::string getProjectName() const;
    [[nodiscard]] std::string getMemberName() const;

    static std::unique_ptr<ProjectMemberAction> fromJson(const std::shared_ptr<Json::Value>& json);
};

#endif //PROJECT_DTO_H