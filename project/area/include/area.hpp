#ifndef AREA_HPP
#define AREA_HPP

#include <QJsonObject>

namespace AkashiArea {
    class Area
    {
        Area(const QJsonObject &f_area_config);
        ~Area();

        void setAreaName(const QString &f_area_name);
        QString getAreaName() const;

        void addClient(const int &f_player_id);
        void removeClient(const int &f_player_id);
        QVector<int> getClients() const;

      private:
        QString name;
        QVector<int> clients;
    };
}

#endif // AREA_HPP
