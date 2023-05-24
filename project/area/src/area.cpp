#include "include/area.hpp"

using namespace AkashiArea;

Area::Area(const QJsonObject &f_area_entry) :
    name(f_area_entry["name"].toString())
{
}

Area::~Area()
{
}

void Area::setAreaName(const QString &f_area_name)
{
    name = f_area_name;
}

QString Area::getAreaName() const
{
    return name;
}

void Area::addClient(const int &f_player_id)
{
    clients.append(f_player_id);
}

void Area::removeClient(const int &f_player_id)
{
    clients.removeAll(f_player_id);
}

QVector<int> Area::getClients() const
{
    return clients;
}
