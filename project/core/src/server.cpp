#include <../netcode/masterserver/include/masterserver_client.hpp>
#include <../netcode/socket/include/network_socket.hpp>
#include <include/client/client_manager.hpp>
#include <include/configuration/config_manager.hpp>
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
    d_ptr.get()->client_manager = new AkashiCore::ClientManager(this);

    connect(d_ptr.get()->connection_handler, &ConnectionHandler::newClientConnected,
            d_ptr.get()->client_manager, &ClientManager::on_newClientConnected);

    if (ConfigManager::getInstance().enableAdvertiser()) {
        ConfigManager *config = &ConfigManager::getInstance();
        AkashiNetwork::MasterserverClient::MS_ClientConfig l_config;
        l_config.server_name = config->serverName();
        l_config.description = config->serverDescription();
        l_config.playercount = 0;
        l_config.port = config->serverPort();
        l_config.ws_port = config->wsServerPort();
        l_config.hostname = config->hostname();
        d_ptr.get()->masterserver_client = new AkashiNetwork::MasterserverClient(this, l_config);
    }
}

AkashiCore::Server::~Server()
{
    qDebug() << "[SERVER]::DTOR"
             << "Destroying Server";
}
