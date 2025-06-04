#ifndef PROJECT_SERVICE_H
#define PROJECT_SERVICE_H

#include "notification_service.h"

class ProjectService {
    NotificationService& notificationService;
public:
    explicit ProjectService(NotificationService& notificationService);
    ~ProjectService() = default;

    void notifyProjectCreation(const std::string &userId, const std::string &projectName) const;
    void notifyProjectDeletion(const std::string &userId, const std::string &projectName) const;
    void notifyProjectMemberInvitation(
        const std::string &userId, const std::string &projectName, const std::string &memberName
    ) const;
    void notifyProjectMemberKick(
        const std::string& userId, const std::string& projectName, const std::string& memberName
    ) const;
};

#endif //PROJECT_SERVICE_H