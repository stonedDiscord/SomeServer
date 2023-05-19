#include <../netcode/masterserver/include/masterserver_client.hpp>
#include <include/network/connection_handler.hpp>
#include <include/server.hpp>
#include <include/server_p.hpp>

#include <QDebug>

AkashiCore::Server::Server(int argc, char *argv[]) :
    QCoreApplication(argc, argv),
    d_ptr(std::make_unique<Private::ServerPrivate>())
{
    qDebug() << "[SERVER]::CTOR"
             << "Starting Server";
    d_ptr.get()->connection_handler = new AkashiCore::ConnectionHandler(this);

    AkashiExternal::MasterserverClient::MS_ClientConfig l_config;
    l_config.server_name = "MyFirstServer";
    l_config.description = "Test Description";
    l_config.playercount = 0;
    l_config.port = 27016;
    l_config.ws_port = 27017;
    l_config.hostname = "my.domain.tld";
    d_ptr.get()->masterserver_client = new AkashiExternal::MasterserverClient(this, l_config);
}

AkashiCore::Server::~Server()
{
    qDebug() << "[SERVER]::DTOR"
             << "Destroying Server";
}
