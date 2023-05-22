#include "include/hub_manager.hpp"
#include "include/hub_manager_p.hpp"

using namespace AkashiArea;

#include <QDebug>
#include <QJsonDocument>

HubManager::HubManager(QObject *parent, const QJsonDocument &f_area_list) :
    QObject(parent),
    d_ptr(std::make_unique<Private::HubManagerPrivate>())
{
    qDebug() << "[HUBMANAGER]::CTOR"
             << "Starting Hub Manager";
}

HubManager::~HubManager()
{
    qDebug() << "[HUBMANAGER]::DTOR"
             << "Destroying Hub Manager";
}
