#include "../../include/builders/project_dto_builders.h"

std::unique_ptr<ProjectAction> ProjectActionBuilder::build() {
    if (userId.empty() || projectName.empty()) {
        throw std::runtime_error("Required fields are not set");
    }

    return std::make_unique<ProjectAction>(std::move(userId), std::move(projectName));
}


ProjectMemberActionBuilder &ProjectMemberActionBuilder::setMemberName(std::string memberName) {
    if (memberName.empty()) {
        throw std::invalid_argument("Member ID cannot be empty");
    }

    this->memberName = std::move(memberName);

    return *this;
}

std::unique_ptr<ProjectMemberAction> ProjectMemberActionBuilder::build() {
    if (userId.empty() || projectName.empty() || memberName.empty()) {
        throw std::invalid_argument("Required fields are not set");
    }

    return std::make_unique<ProjectMemberAction>(
        std::move(userId), std::move(projectName), std::move(memberName)
    );
}