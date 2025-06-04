#include "../../include/services/project_service.h"
#include "../../include/controllers/project_controllers.h"

ProjectService::ProjectService(NotificationService &notificationService) : notificationService(notificationService) {}

void ProjectService::notifyProjectCreation(const std::string& userId, const std::string& projectName) const {
    notificationService.notify(userId, "Создание проекта", "Вы создали проект " + projectName);
}

void ProjectService::notifyProjectDeletion(const std::string& userId, const std::string& projectName) const {
    notificationService.notify(userId, "Удаление проекта", "Вы удалили проект " + projectName);
}

void ProjectService::notifyProjectMemberInvitation(
    const std::string& userId, const std::string& projectName, const std::string& memberName
) const {
    notificationService.notify(
        userId, "Приглашение участника в команду проект",
        "Участник " + memberName + " успешно приглашен в команду проекта " + projectName
    );
}

void ProjectService::notifyProjectMemberKick(
    const std::string& userId, const std::string& projectName, const std::string& memberName
) const {
    notificationService.notify(
        userId, "Исключение участника из команды проекта",
        "Участник " + memberName + " исключен из команды проекта " + projectName
    );
}