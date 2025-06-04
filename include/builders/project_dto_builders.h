#ifndef PROJECT_DTO_BUILDERS_H
#define PROJECT_DTO_BUILDERS_H

#include <string>

#include "builder.h"
#include "../dto/project_dto.h"

template<typename Derived>
class ProjectActionBuilderBase {
protected:
    std::string userId{};
    std::string projectName{};

public:
    ProjectActionBuilderBase() = default;
    virtual ~ProjectActionBuilderBase() = default;

    Derived& setUserId(std::string userId) {
        if (userId.empty()) {
            throw std::invalid_argument("User ID cannot be empty");
        }

        this->userId = std::move(userId);

        return static_cast<Derived&>(*this);
    }
    Derived& setProjectName(std::string projectName) {
        if (projectName.empty()) {
            throw std::invalid_argument("Project name cannot be empty");
        }

        this->projectName = std::move(projectName);

        return static_cast<Derived&>(*this);
    }
};

class ProjectActionBuilder final : public Builder<ProjectAction>,
                                   public ProjectActionBuilderBase<ProjectActionBuilder> {
public:
    ProjectActionBuilder() = default;
    ~ProjectActionBuilder() override = default;

    std::unique_ptr<ProjectAction> build() override;
};

class ProjectMemberActionBuilder final : public Builder<ProjectMemberAction>,
                                         public ProjectActionBuilderBase<ProjectMemberActionBuilder> {
    std::string memberName{};
public:
    ProjectMemberActionBuilder() = default;
    ~ProjectMemberActionBuilder() override = default;

    ProjectMemberActionBuilder& setMemberName(std::string memberName);
    std::unique_ptr<ProjectMemberAction> build() override;
};

#endif //PROJECT_DTO_BUILDERS_H