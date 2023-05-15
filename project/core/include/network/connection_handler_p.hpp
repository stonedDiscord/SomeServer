#ifndef CONNECTION_HANDLER_PRIVATE_HPP
#define CONNECTION_HANDLER_PRIVATE_HPP

#include <memory>

class QTcpServer;
class QWebSocketServer;

namespace AkashiCore::Private {

    struct ConnectionHandlerPrivate
    {
        QTcpServer *tcp_server;
        QWebSocketServer *ws_server;
    };
}

#endif // CONNECTION_HANDLER_PRIVATE_HPP
