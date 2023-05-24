#ifndef SERVER_PRIVATE_HPP
#define SERVER_PRIVATE_HPP

#include <memory>

namespace AkashiCore {
    class ClientManager;
}

namespace AkashiNetwork {
    class ConnectionHandler;
    class MasterserverClient;
}

namespace AkashiArea {
    class HubManager;
}

namespace AkashiCore::Private {
    struct ServerPrivate
    {
        AkashiCore::ClientManager *client_manager;
        AkashiNetwork::ConnectionHandler *connection_handler;
        AkashiNetwork::MasterserverClient *masterserver_client;
        AkashiArea::HubManager *hub_manager;
    };
}

#endif // SERVER_PRIVATE_HPP
