#include "include/network/connection_handler.hpp"
#include "../netcode/socket/include/network_socket.hpp"
#include "include/configuration/config_manager.hpp"
#include "include/network/connection_handler_p.hpp"

#include <QDebug>
#include <QHostAddress>
#include <QTcpServer>
#include <QWebSocketServer>

AkashiCore::ConnectionHandler::ConnectionHandler(QObject *parent) :
    QObject(parent),
    d_ptr(std::make_unique<AkashiCore::Private::ConnectionHandlerPrivate>())
{
    qDebug() << "[ConnectionHandler]::CTOR"
             << "Starting ConnectionHandler";

    int server_port = ConfigManager::getInstance().server_port();
    if (server_port != 0) {
        d_ptr->tcp_server = new QTcpServer(this);

        if (d_ptr->tcp_server->listen(QHostAddress::LocalHost, server_port)) {
            qDebug() << "[ConnectionHandler]::CTOR"
                     << "Listening for incoming TCP connection on port"
                     << server_port;
            connect(d_ptr->tcp_server, &QTcpServer::newConnection, this, &ConnectionHandler::newTCPConnection);
        }
        else {
            qDebug() << "[ConnectionHandler]::CTOR"
                     << "An error occured starting the TCP Server:" << d_ptr->tcp_server->serverError();
        }
    }

    int ws_server_port = ConfigManager::getInstance().ws_server_port();
    if (ws_server_port != 0) {
        d_ptr->ws_server = new QWebSocketServer("akashi", QWebSocketServer::SslMode::NonSecureMode, this);

        if (d_ptr->ws_server->listen(QHostAddress::LocalHost, ws_server_port)) {
            qDebug() << "[ConnectionHandler]::CTOR"
                     << "Listening for incoming Websocket connection on port"
                     << ws_server_port;
            connect(d_ptr->ws_server, &QWebSocketServer::newConnection, this, &ConnectionHandler::newWebSocketConnection);
        }
        else {
            qDebug() << "[ConnectionHandler]::CTOR"
                     << "An error occured starting the Websocket Server:" << d_ptr->tcp_server->serverError();
        }
    }
}

AkashiCore::ConnectionHandler::~ConnectionHandler()
{
    qDebug() << "[ConnectionHandler]::DTOR"
             << "Destroying ConnectionHandler";
}

void AkashiCore::ConnectionHandler::newTCPConnection()
{
    qDebug() << "[ConnectionHandler]::TCPConnect"
             << "Incoming TCP connection.";
    QTcpSocket *l_new_socket = d_ptr->tcp_server->nextPendingConnection();

    AkashiNetwork::NetworkSocket *l_socket = new AkashiNetwork::AOTCPSocket(this, l_new_socket);
    m_sockets.append(l_socket);
}

void AkashiCore::ConnectionHandler::newWebSocketConnection()
{
    qDebug() << "[ConnectionHandler]::WebSocketConnect"
             << "Incoming Websocket connection.";
    QWebSocket *l_new_socket = d_ptr->ws_server->nextPendingConnection();

    AkashiNetwork::NetworkSocket *l_socket = new AkashiNetwork::AOWebSocket(this, l_new_socket);
    m_sockets.append(l_socket);
}
