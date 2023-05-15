#include "include/configuration/config_manager.hpp"
#include "include/configuration/config_manager_p.hpp"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QSettings>

AkashiCore::ConfigManager::ConfigManager() :
    d_ptr(std::make_unique<Private::ConfigManagerPrivate>())
{
    d_ptr->config = new QSettings("config/config.ini", QSettings::IniFormat);
    d_ptr->config->setIniCodec("UTF-8");
}

AkashiCore::ConfigManager::~ConfigManager() {}

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

int AkashiCore::ConfigManager::server_port()
{
    return d_ptr->config->value("config/server_port", 0).toInt();
}

int AkashiCore::ConfigManager::ws_server_port()
{
    return d_ptr->config->value("config/ws_server_port", 0).toInt();
}
