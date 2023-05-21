#ifndef CLIENT_PRIVATE_HPP
#define CLIENT_PRIVATE_HPP

namespace AkashiNetwork {
    class NetworkSocket;
}

namespace AkashiCore::Private {
    struct ClientPrivate
    {
        AkashiNetwork::NetworkSocket *socket;
        int id;
    };
}

#endif
