cmake_minimum_required(VERSION 3.30)
project(notification_service)

set(CMAKE_CXX_STANDARD 20)

find_package(Drogon REQUIRED)

find_package(CURL REQUIRED)

add_executable(notification_service
        sqlite/sqlite3.h
        sqlite/sqlite3.c

        include/sql/sqlite3_handler.h
        src/sql/sqlite3_handler.cpp

        include/dto/user_dto.h
        include/dto/project_dto.h
        include/dto/task_dto.h
        include/dto/tag_dto.h
        include/dto/comment_dto.h
        src/dto/user_dto.cpp
        src/dto/project_dto.cpp
        src/dto/task_dto.cpp
        src/dto/tag_dto.cpp
        src/dto/comment_dto.cpp

        include/builders/builder.h
        include/builders/user_dto_builders.h
        include/builders/project_dto_builders.h
        include/builders/task_dto_builders.h
        include/builders/tag_dto_builders.h
        include/builders/comment_dto_builders.h
        src/builders/user_dto_builders.cpp
        src/builders/project_dto_builders.cpp
        src/builders/task_dto_builders.cpp
        src/builders/tag_dto_builders.cpp
        src/builders/comment_dto_builders.cpp

        include/services/notification_service.h
        include/services/user_service.h
        include/services/email_service.h
        include/services/project_service.h
        include/services/task_service.h
        include/services/tag_service.h
        include/services/comment_service.h
        src/services/user_service.cpp
        src/services/email_service.cpp
        src/services/notification_service.cpp
        src/services/project_service.cpp
        src/services/task_service.cpp
        src/services/tag_service.cpp
        src/services/comment_service.cpp

        include/instance_holder.h
        src/instance_holder.cpp

        include/controllers/user_controllers.h
        include/controllers/project_controllers.h
        include/controllers/task_controllers.h
        include/controllers/tag_controllers.h
        include/controllers/comment_controllers.h
        src/controllers/user_controllers.cpp
        src/controllers/project_controllers.cpp
        src/controllers/task_controllers.cpp
        src/controllers/tag_controllers.cpp
        src/controllers/comment_controllers.cpp

        main.cpp
)

target_link_libraries(notification_service
        PRIVATE
        Drogon::Drogon
        PRIVATE ${CURL_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CURL_INCLUDE_DIRS})