#include "include/area_manager.hpp"
#include "include/area.hpp"
#include "include/area_manager_p.hpp"

using namespace AkashiArea;

AreaManager::AreaManager(QObject *parent) :
    QObject(parent),
    d_ptr(std::make_unique<Private::AreaManagerPrivate>())
{
}

AreaManager::~AreaManager()
{
}
