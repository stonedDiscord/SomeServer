#ifndef MASTERSERVER_CLIENT_PRIVATE_HPP
#define MASTERSERVER_CLIENT_PRIVATE_HPP

#include <QNetworkAccessManager>
#include <QString>
#include <QTimer>

namespace AkashiExternal::Private {
    struct MasterserverPrivate
    {
        QNetworkAccessManager network;
        QTimer timer;
        QString hostname;
        QString server_name;
        QString description;
        int playercount;
        int port;
        int ws_port;

        QString masterserver_hostname = "https://servers.aceattorneyonline.com/servers";
    };
}

#endif // MASTERSERVER_PRIVATE_HPP