#include "include/network/network_socket.hpp"

#include <QDebug>
#include <QTcpSocket>
#include <QWebSocket>

AkashiCore::AOTCPSocket::AOTCPSocket(QObject *parent, QTcpSocket *f_socket, int f_client_id) :
    NetworkSocket(parent),
    m_socket(f_socket)
{
    // Can't use an initializer list for this one apparently?
    m_client_id = f_client_id;
    connect(f_socket, &QTcpSocket::readyRead, this, &AOTCPSocket::receiveData);
}

void AkashiCore::AOTCPSocket::receiveData()
{
    QString l_data = m_socket->readAll();
    qDebug() << l_data;
};

AkashiCore::AOWebSocket::AOWebSocket(QObject *parent, QWebSocket *f_socket, int f_client_id) :
    NetworkSocket(parent),
    m_socket(f_socket)
{
    // Can't use an initializer list for this one apparently?
    m_client_id = f_client_id;
    connect(f_socket, &QWebSocket::textMessageReceived, this, &AOWebSocket::receiveData);
}

void AkashiCore::AOWebSocket::receiveData(QString f_data)
{
    qDebug() << f_data;
}
