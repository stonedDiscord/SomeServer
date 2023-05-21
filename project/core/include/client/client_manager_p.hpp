#ifndef CLIENT_MANAGER_PRIVATE_HPP
#define CLIENT_MANAGER_PRIVATE_HPP

#include <QVector>

namespace AkashiCore {

    class Client;

    namespace Private {
        struct ClientManagerPrivate
        {
            QVector<AkashiCore::Client *> clients;
        };
    }
}

#endif
