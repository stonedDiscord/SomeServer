#ifndef NETWORK_SOCKET_HPP
#define NETWORK_SOCKET_HPP

class QTcpSocket;
class QWebSocket;

#include "../netcode/socket/interfaces/network_socket_i.hpp"

namespace AkashiNetwork {
    class AOTCPSocket : public NetworkSocket
    {
        Q_OBJECT

      public:
        AOTCPSocket(QObject *parent, QTcpSocket *f_socket);
        ~AOTCPSocket();

        QHostAddress remoteIP() override;

      public slots:
        void writeData(const QByteArray f_data) override;

      private:
        QTcpSocket *m_socket;

      private slots:
        void receiveData();
    };

    class AOWebSocket : public NetworkSocket
    {
        Q_OBJECT

      public:
        AOWebSocket(QObject *parent, QWebSocket *f_socket);
        ~AOWebSocket();

        QHostAddress remoteIP() override;

      public slots:
        void writeData(const QByteArray f_data) override;

      private:
        QWebSocket *m_socket;

      private slots:
        void receiveData(QString f_data = "");
    };
}

#endif // NETWORK_SOCKET_HPP
