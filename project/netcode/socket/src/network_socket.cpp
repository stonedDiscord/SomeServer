#include "socket/include/network_socket.hpp"

#include <QDebug>
#include <QTcpSocket>
#include <QWebSocket>

using namespace AkashiNetwork;

AOTCPSocket::AOTCPSocket(QObject *parent, QTcpSocket *f_socket) :
    NetworkSocket(parent),
    m_socket(f_socket)
{
    connect(m_socket, &QTcpSocket::readyRead, this, &AOTCPSocket::receiveData);
    m_socket->write("decryptor#NOENCRYPT#%");
}

AOTCPSocket::~AOTCPSocket()
{
    qDebug() << "[AOTCPSOCKET]DTOR Destroying client connection.";
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
    connect(m_socket, &QWebSocket::textMessageReceived, this, &AOWebSocket::receiveData);
    m_socket->sendTextMessage("DECRYPTOR#NOENCRYPT#%");
}

AOWebSocket::~AOWebSocket()
{
    qDebug() << "[AOWEBSOCKET]DTOR Destroying client connection.";
}

void AOWebSocket::receiveData(QString f_data)
{
    qDebug() << f_data;
}
