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
    connect(m_socket, &QWebSocket::textMessageReceived, this, &AOWebSocket::receiveData);
}

AOWebSocket::~AOWebSocket()
{
    qDebug() << "[AOWEBSOCKET]DTOR Destroying client connection.";
}

void AOWebSocket::writeData(const QByteArray f_data)
{
    m_socket->sendTextMessage(f_data);
}

void AOWebSocket::receiveData(QString f_data)
{
    qDebug() << f_data;
}
