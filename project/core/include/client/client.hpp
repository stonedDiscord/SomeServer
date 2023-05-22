#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <QObject>
#include <memory>

namespace AkashiNetwork {
    class NetworkSocket;
}

namespace AkashiCore {
    namespace Private {
        struct ClientPrivate;
    }

    class Client : public QObject
    {
        Q_OBJECT

      public:
        Client(QObject *parent, AkashiNetwork::NetworkSocket *f_socket, int client_id = -1);
        ~Client();

      signals:
        void clientDisconnected(int f_client_id);

      private:
        std::unique_ptr<Private::ClientPrivate> d_ptr;
    };
}

#endif // CLIENT_HPP
