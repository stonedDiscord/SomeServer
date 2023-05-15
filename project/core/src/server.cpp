#include <include/server.hpp>
#include <include/server_p.hpp>
#include <include/network/connection_handler.hpp>

#include <QDebug>

AkashiCore::Server::Server(int argc, char *argv[]) :
    QCoreApplication(argc, argv),
    d_ptr(std::make_unique<Private::ServerPrivate>())
{
    qDebug() << "[SERVER]::CTOR"
             << "Starting Server";
    d_ptr.get()->connection_handler = new AkashiCore::ConnectionHandler(this);
}

AkashiCore::Server::~Server()
{
    qDebug() << "[SERVER]::DTOR"
             << "Destroying Server";
}
