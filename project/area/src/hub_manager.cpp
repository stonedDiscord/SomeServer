#include "include/hub_manager.hpp"
#include "include/hub_manager_p.hpp"

using namespace AkashiArea;

#include <QDebug>
#include <QJsonDocument>

std::unique_ptr<Private::HubManagerPrivate> AkashiArea::HubManager::d_ptr = std::make_unique<Private::HubManagerPrivate>();

// Passing the arealist as a QString to handle invalid QJsonDocument by the hub manager.
HubManager::HubManager(QObject *parent, const QString &f_area_list) :
    QObject(parent)
{
    qDebug() << "[HUBMANAGER]::CTOR"
             << "Starting Hub Manager";
}

HubManager::~HubManager()
{
    qDebug() << "[HUBMANAGER]::DTOR"
             << "Destroying Hub Manager";
}
