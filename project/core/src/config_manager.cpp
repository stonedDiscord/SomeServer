#include "include/configuration/config_manager.hpp"
#include "include/configuration/config_manager_p.hpp"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QSettings>

using namespace AkashiCore;

ConfigManager::ConfigManager() :
    d_ptr(std::make_unique<Private::ConfigManagerPrivate>())
{
    d_ptr->config = new QSettings("config/config.ini", QSettings::IniFormat);
    d_ptr->config->setIniCodec("UTF-8");
}

ConfigManager::~ConfigManager() {}

bool ConfigManager::checkConfiguration()
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

int ConfigManager::serverPort()
{
    return d_ptr->config->value("config/server_port", 0).toInt();
}

int ConfigManager::wsServerPort()
{
    return d_ptr->config->value("config/ws_server_port", 0).toInt();
}

QString ConfigManager::serverName()
{
    return d_ptr->config->value("config/server_name", "My First Server").toString();
}

QString ConfigManager::serverDescription()
{
    return d_ptr->config->value("config/server_description", "Sample Text").toString();
}

bool ConfigManager::enableAdvertiser()
{
    return d_ptr->config->value("advertiser/advertise", false).toBool();
}

bool ConfigManager::showDebug()
{
    return d_ptr->config->value("advertiser/debug", false).toBool();
}

QString ConfigManager::masterServerAddress()
{
    return d_ptr->config->value("advertiser/ms_ip", "").toString();
}

QString ConfigManager::hostname()
{
    return d_ptr->config->value("advertiser/hostname", "").toString();
}
