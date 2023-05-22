#include "socket/include/network_socket.hpp"

#include <QDebug>
#include <QTcpSocket>
#include <QWebSocket>

using namespace AkashiNetwork;

AOTCPSocket::AOTCPSocket(QObject *parent, QTcpSocket *f_socket) :
    NetworkSocket(parent),
    m_socket(f_socket)
{
    connect(m_socket, &QTcpSocket::readyRead,
            this, &AOTCPSocket::receiveData);
    connect(m_socket, &QTcpSocket::disconnected,
            this, &AOTCPSocket::disconnected);
    m_socket->write("decryptor#NOENCRYPT#%");
    ip = m_socket->peerAddress();
}

AOTCPSocket::~AOTCPSocket()
{
    qDebug() << "[AOTCPSOCKET]DTOR Destroying client connection.";
}

QHostAddress AOTCPSocket::remoteIP()
{
    return ip;
}

void AOTCPSocket::writeData(const QByteArray f_data)
{
    m_socket->write(f_data);
}

void AOTCPSocket::receiveData()
{
    QString l_data = m_socket->readAll();
    qDebug() << l_data;
};

AOWebSocket::AOWebSocket(QObject *parent, QWebSocket *f_socket) :
    NetworkSocket(parent),
    m_socket(f_socket)
{
    connect(m_socket, &QWebSocket::textMessageReceived,
            this, &AOWebSocket::receiveData);
    connect(m_socket, &QWebSocket::disconnected,
            this, &AOWebSocket::disconnected);

    bool is_local = (m_socket->peerAddress() == QHostAddress::LocalHost) ||
                    (m_socket->peerAddress() == QHostAddress::LocalHostIPv6) ||
                    (m_socket->peerAddress() == QHostAddress("::ffff:127.0.0.1"));
    // TLDR : We check if the header comes trough a proxy/tunnel running locally.
    // This is to ensure nobody can send those headers from the web.

    QNetworkRequest l_request = m_socket->request();
    if (l_request.hasRawHeader("x-forwarded-for") && is_local) {
        ip = QHostAddress(QString::fromUtf8(l_request.rawHeader("x-forwarded-for")));
    }
    else {
        ip = m_socket->peerAddress();
    }
}

AOWebSocket::~AOWebSocket()
{
    qDebug() << "[AOWEBSOCKET]DTOR Destroying client connection.";
}

QHostAddress AOWebSocket::remoteIP()
{
    return ip;
}

void AOWebSocket::writeData(const QByteArray f_data)
{
    m_socket->sendTextMessage(f_data);
}

void AOWebSocket::receiveData(QString f_data)
{
    qDebug() << f_data;
}
