#ifndef AREA_MANAGER_PRIVATE_HPP
#define AREA_MANAGER_PRIVATE_HPP

#include <QVector>

namespace AkashiArea {
    class Area;

    namespace Private {
        struct AreaManagerPrivate
        {
            QString hub_name;
            QVector<Area *> areas;
        };
    }
}

#endif // AREA_MANAGER_PRIVATE_HPP
