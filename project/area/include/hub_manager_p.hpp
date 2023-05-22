#ifndef HUB_MANAGER_PRIVATE_HPP
#define HUB_MANAGER_PRIVATE_HPP

#include <QVector>

namespace AkashiArea {
    class AreaManager;

    namespace Private {
        struct HubManagerPrivate
        {
            QVector<AreaManager *> l_hubs;
        };
    }
}

#endif // HUB_MANAGER_PRIVATE_HPP
