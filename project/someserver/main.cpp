#include "include/server.hpp"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    AkashiCore::Server ServerCore(argc, argv);
    ServerCore.setApplicationName("SomeServer");
    ServerCore.setApplicationVersion("0.0.1");

    return ServerCore.exec();
}
