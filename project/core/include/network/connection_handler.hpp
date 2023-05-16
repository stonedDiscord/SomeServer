#ifndef CONNECTION_HANDLER_HPP
#define CONNECTION_HANDLER_HPP

#include <QObject>
#include <memory>

class NetworkSocket;

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

      private slots:
        void newTCPConnection();
        void newWebSocketConnection();

      private:
        std::unique_ptr<Private::ConnectionHandlerPrivate> d_ptr;

        QVector<NetworkSocket *> m_sockets;

        int active_connections = 0;
    };

};

#endif // CONNECITON_HANDLER_HPP
