#ifndef CONNECTION_HANDLER_PRIVATE_HPP
#define CONNECTION_HANDLER_PRIVATE_HPP

#include <memory>

#include <QTcpServer>
#include <QWebSocketServer>

namespace AkashiCore::Private {

    struct ConnectionHandlerPrivate
    {
        QTcpServer* m_tcp_server;
        QWebSocketServer* m_ws_server;
    };
}

#endif // CONNECTION_HANDLER_PRIVATE_HPP
