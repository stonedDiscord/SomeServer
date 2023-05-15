#include "include/configuration/config_manager.hpp"
#include "include/configuration/config_manager_p.hpp"

AkashiCore::ConfigManager::ConfigManager() :
    d_ptr(std::make_unique<Private::ConfigManagerPrivate>())
{
}
