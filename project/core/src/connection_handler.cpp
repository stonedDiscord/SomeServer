#include <include/network/connection_handler.hpp>
#include <include/network/connection_handler_p.hpp>

#include <QDebug>

AkashiCore::ConnectionHandler::ConnectionHandler(QObject *parent) :
    QObject(parent),
    d_ptr(std::make_unique<AkashiCore::Private::ConnectionHandlerPrivate>())
{
    qDebug() << "[ConnectionHandler::CTOR"
             << "Starting ConnectionHandler";
}

AkashiCore::ConnectionHandler::~ConnectionHandler()
{
    qDebug() << "[ConnectionHandler::DTOR"
             << "Destroying ConnectionHandler";
}
