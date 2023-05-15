#include "include/configuration/config_manager.hpp"
#include "include/configuration/config_manager_p.hpp"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QSettings>

AkashiCore::ConfigManager::ConfigManager() :
    d_ptr(std::make_unique<Private::ConfigManagerPrivate>())
{
    d_ptr->m_config = new QSettings("config/config.ini", QSettings::IniFormat);
}

AkashiCore::ConfigManager::~ConfigManager(){}

bool AkashiCore::ConfigManager::checkConfiguration()
{
    if (!QDir().exists("config")) {
        qDebug() << "[ConfigManager]::CHECK"
                 << "Configuration folder not found. Make sure to rename config_sample to config!";
        return false;
    }

    if (!QFile::exists("config/config.ini")) {
        qDebug() << "[ConfigManager]::CHECK"
                 << "Config.ini not found.";
        return false;
    };
    return true;
}
