#ifndef SERVER_PRIVATE_HPP
#define SERVER_PRIVATE_HPP

#include <memory>

namespace AkashiCore {
    class ConnectionHandler;
    class ClientManager;
}

namespace AkashiNetwork {
    class MasterserverClient;
}

namespace AkashiCore::Private {
    struct ServerPrivate
    {
        AkashiCore::ConnectionHandler *connection_handler;
        AkashiCore::ClientManager *client_manager;
        AkashiNetwork::MasterserverClient *masterserver_client;
    };
}

#endif // SERVER_PRIVATE_HPP
