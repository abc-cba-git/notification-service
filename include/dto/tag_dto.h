#ifndef TAG_DTO_H
#define TAG_DTO_H

#include <string>
#include <json/value.h>

class TagAction {
    std::string userId;
    std::string projectName;
    std::string tagName;
public:
    TagAction(std::string userId, std::string projectName, std::string tagName);
    ~TagAction() = default;

    [[nodiscard]] std::string getUserId() const;
    [[nodiscard]] std::string getProjectName() const;
    [[nodiscard]] std::string getTagName() const;

    static std::unique_ptr<TagAction> fromJson(const std::shared_ptr<Json::Value>& json);
};

#endif //TAG_DTO_H