#ifndef SERVER_PRIVATE_HPP
#define SERVER_PRIVATE_HPP

#include <memory>

namespace AkashiCore {
    class ConnectionHandler;
}

namespace AkashiNetwork {
    class MasterserverClient;
}

namespace AkashiCore::Private {
    struct ServerPrivate
    {
        AkashiCore::ConnectionHandler *connection_handler;
        AkashiNetwork::MasterserverClient *masterserver_client;
    };
}

#endif // SERVER_PRIVATE_HPP
