#ifndef CONFIG_MANAGER_PRIVATE_HPP
#define CONFIG_MANAGER_PRIVATE_HPP

class QSettings;

namespace AkashiCore::Private {
    struct ConfigManagerPrivate
    {
        QSettings *m_config;
    };
}

#endif // CONFIG_MANAGER_PRIVATE_HPP
