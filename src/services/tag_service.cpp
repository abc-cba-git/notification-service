#include "../../include/services/tag_service.h"

TagService::TagService(NotificationService &notificationService) : notificationService(notificationService) {}

void TagService::notifyTagCreation(
    const std::string &userId, const std::string &projectName, const std::string &tagName
) const {
    notificationService.notify(
        userId, "Создание тега",
        std::format("Тег {} создан в проекте {}", tagName, projectName)
    );
}

void TagService::notifyTagDeletion(
    const std::string &userId, const std::string &projectName, const std::string &tagName
) const {
    notificationService.notify(
        userId, "Удаление тега",
        std::format("Тег {} удален в проекте {}", tagName, projectName)
    );
}