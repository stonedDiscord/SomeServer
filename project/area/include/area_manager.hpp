#ifndef AREA_MANAGER_HPP
#define AREA_MANAGER_HPP

#include <QObject>
#include <memory>

namespace AkashiArea {
    namespace Private {
        struct AreaManagerPrivate;
    }

    class AreaManager : public QObject
    {
        Q_OBJECT

      public:
        AreaManager(QObject *parent);
        ~AreaManager();

      private:
        std::unique_ptr<Private::AreaManagerPrivate> d_ptr;
    };
}

#endif // AREA_MANAGER_HPP
