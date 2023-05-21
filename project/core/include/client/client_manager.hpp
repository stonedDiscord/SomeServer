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

      private:
        std::unique_ptr<Private::ClientManagerPrivate> d_ptr;
    };
}

#endif
