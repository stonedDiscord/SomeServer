#include "include/client/client_manager.hpp"
#include "../netcode/socket/include/network_socket.hpp"
#include "include/client/client.hpp"
#include "include/client/client_manager_p.hpp"

#include <QDebug>

using namespace AkashiCore;

ClientManager::ClientManager(QObject *parent) :
    QObject(parent),
    d_ptr(std::make_unique<Private::ClientManagerPrivate>())
{
    qDebug() << "[ClientManager]::CTOR"
             << "Starting ClientManager";
}

ClientManager::~ClientManager()
{
    qDebug() << "[ClientManager]::DTOR"
             << "Destroying ClientManager";
}

void ClientManager::on_newClientConnected(AkashiNetwork::NetworkSocket *l_socket)
{
    auto l_client = new Client(this, l_socket, 0);
    d_ptr.get()->clients.insert(0, l_client);
}
