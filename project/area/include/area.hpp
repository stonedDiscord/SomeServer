#ifndef AREA_HPP
#define AREA_HPP

#include <QJsonObject>

namespace AkashiArea {
    class Area
    {
        Area(const QJsonObject &f_area_entry);
        ~Area();
    };
}

#endif // AREA_HPP
