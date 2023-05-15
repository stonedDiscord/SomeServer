#ifndef CONNECTION_HANDLER_HPP
#define CONNECTION_HANDLER_HPP

#include <QObject>
#include <memory>

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

      private:
        std::unique_ptr<Private::ConnectionHandlerPrivate> d_ptr;
    };

};

#endif // CONNECITON_HANDLER_HPP
