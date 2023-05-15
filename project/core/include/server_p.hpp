#ifndef SERVER_PRIVATE_HPP
#define SERVER_PRIVATE_HPP

#include <memory>

namespace AkashiCore {
 class ConnectionHandler;
}

namespace AkashiCore::Private {
    struct ServerPrivate
    {
        AkashiCore::ConnectionHandler* connection_handler;
    };
}

#endif // SERVER_PRIVATE_HPP
