#include "../../include/builders/tag_dto_builders.h"

TagActionBuilder &TagActionBuilder::setTagName(std::string tagName) {
    if (tagName.empty()) {
        throw std::invalid_argument("Tag name cannot be empty");
    }

    this->tagName = std::move(tagName);

    return *this;
}

std::unique_ptr<TagAction> TagActionBuilder::build() {
    if (userId.empty() || projectName.empty() || tagName.empty()) {
        throw std::runtime_error("Required fields are not set");
    }

    return std::make_unique<TagAction>(std::move(userId), std::move(projectName), std::move(tagName));
}