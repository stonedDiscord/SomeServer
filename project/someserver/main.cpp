#include "include/configuration/config_manager.hpp"
#include "include/server.hpp"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    if (!AkashiCore::ConfigManager::checkConfiguration()) {
        return EXIT_FAILURE;
    }

    AkashiCore::Server ServerCore(argc, argv);
    ServerCore.setApplicationName("SomeServer");
    ServerCore.setApplicationVersion("0.0.1");

    return ServerCore.exec();
}
