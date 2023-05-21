#include "include/client/client.hpp"
#include "../netcode/socket/include/network_socket.hpp"
#include "include/client/client_p.hpp"

#include <QDebug>

AkashiCore::Client::Client(QObject *parent, AkashiNetwork::NetworkSocket *f_socket, int client_id) :
    QObject(parent),
    d_ptr(std::make_unique<Private::ClientPrivate>())
{
    qDebug() << "[CLIENT]::CTOR"
             << "Creating client with id" << client_id;
    d_ptr.get()->id = client_id;
    d_ptr.get()->socket = f_socket;
    d_ptr.get()->socket->writeData("decryptor#NOENCRYPT#%");
}

AkashiCore::Client::~Client()
{
    qDebug() << "[CLIENT]::DTOR"
             << "Destroying Client with id" << d_ptr->id;
}
