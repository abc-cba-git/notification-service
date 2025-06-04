#ifndef TAG_DTO_BUILDERS_H
#define TAG_DTO_BUILDERS_H

#include <string>

#include "builder.h"
#include "../dto/tag_dto.h"
#include "project_dto_builders.h"

class TagActionBuilder final : public Builder<TagAction>, public ProjectActionBuilderBase<TagActionBuilder> {
    std::string tagName{};
public:
    TagActionBuilder() = default;
    ~TagActionBuilder() override = default;

    TagActionBuilder& setTagName(std::string tagName);
    std::unique_ptr<TagAction> build() override;
};

#endif //TAG_DTO_BUILDERS_H