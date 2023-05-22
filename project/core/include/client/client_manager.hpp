#ifndef CLIENT_MANAGER_HPP
#define CLIENT_MANAGER_HPP

#include <QObject>
#include <memory>

namespace AkashiNetwork {
    class NetworkSocket;
}

namespace AkashiCore {
    namespace Private {
        struct ClientManagerPrivate;
    }

    class ClientManager : public QObject
    {
        Q_OBJECT

      public:
        ClientManager(QObject *parent);
        ~ClientManager();

      public slots:
        void on_newClientConnected(AkashiNetwork::NetworkSocket *l_socket);
        void on_clientDisconnected(int f_client_id);

      private:
        std::unique_ptr<Private::ClientManagerPrivate> d_ptr;
    };
}

#endif
