#ifndef SERVER_PRIVATE_HPP
#define SERVER_PRIVATE_HPP

#include <memory>

namespace AkashiCore {
    class ConnectionHandler;
}

namespace AkashiExternal {
    class MasterserverClient;
}

namespace AkashiCore::Private {
    struct ServerPrivate
    {
        AkashiCore::ConnectionHandler *connection_handler;
        AkashiExternal::MasterserverClient *masterserver_client;
    };
}

#endif // SERVER_PRIVATE_HPP
