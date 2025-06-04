#ifndef TAG_SERVICE_H
#define TAG_SERVICE_H

#include "notification_service.h"

class TagService {
    NotificationService& notificationService;
public:
    explicit TagService(NotificationService& notificationService);
    ~TagService() = default;

    void notifyTagCreation(const std::string &userId, const std::string &projectName, const std::string& tagName) const;
    void notifyTagDeletion(const std::string &userId, const std::string &projectName, const std::string& tagName) const;
};

#endif //TAG_SERVICE_H