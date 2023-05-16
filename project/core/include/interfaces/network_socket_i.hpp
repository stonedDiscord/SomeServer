#ifndef NETWORK_SOCKET_INTERFACE_HPP
#define NETWORK_SOCKET_INTERFACE_HPP

#include <QObject>

namespace AkashiCore {
    class NetworkSocket : public QObject
    {
        Q_OBJECT

      public:
        NetworkSocket(QObject *parent) :
            QObject(parent){};
        ~NetworkSocket() = default;

      signals:
        void dataReceivedByClient(int f_client_id, QString f_message_data);
    };
}

#endif // NETWORK_SOCKET_INTERFACE_HPP
