#include "include/instance_holder.h"

#include <drogon/HttpAppFramework.h>

int main() {
    InstanceHolder::initialize();

    drogon::app()
        .addListener("localhost", 12122)
        .run();
}