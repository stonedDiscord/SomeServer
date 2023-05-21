#ifndef CONNECTION_HANDLER_HPP
#define CONNECTION_HANDLER_HPP

#include <QObject>
#include <memory>

namespace AkashiNetwork {
    class NetworkSocket;
};

namespace AkashiCore {
    namespace Private {
        struct ConnectionHandlerPrivate;
    };

    // Accepts and rejects incoming connections and handles their disconnect gracefully.
    class ConnectionHandler : public QObject
    {
        Q_OBJECT

      public:
        ConnectionHandler(QObject *parent);
        ~ConnectionHandler();

      signals:
        void newClientConnected(AkashiNetwork::NetworkSocket *f_socket);

      private slots:
        void newTCPConnection();
        void newWebSocketConnection();

      private:
        std::unique_ptr<Private::ConnectionHandlerPrivate> d_ptr;

        // clang-format off
        QVector<AkashiNetwork::NetworkSocket*> m_sockets;
        // clang-format on
    };

};

#endif // CONNECITON_HANDLER_HPP
