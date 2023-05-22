#ifndef HUB_MANAGER_HPP
#define HUB_MANAGER_HPP

#include <QObject>
#include <memory>

namespace AkashiArea {
    namespace Private {
        struct HubManagerPrivate;
    }

    class HubManager : public QObject
    {
        Q_OBJECT

      public:
        HubManager(QObject *parent, const QJsonDocument &f_area_list);
        ~HubManager();

      private:
        std::unique_ptr<Private::HubManagerPrivate> d_ptr;
    };
}

#endif // HUB_MANAGER_HPP
