#ifndef CONFIG_MANAGER_HPP
#define CONFIG_MANAGER_HPP

#include <QObject>
#include <memory>

namespace AkashiCore {
    namespace Private {
        struct ConfigManagerPrivate;
    }

    class ConfigManager : private QObject
    {
        Q_OBJECT

      private:
        ConfigManager();
        ~ConfigManager();
        ;

        std::unique_ptr<Private::ConfigManagerPrivate> d_ptr;

      public:
        ConfigManager(ConfigManager const &) = delete;
        void operator=(ConfigManager const &) = delete;

        static ConfigManager &getInstance()
        {
            static ConfigManager instance;
            return instance;
        }

        static bool checkConfiguration();

        int server_port();
        int ws_server_port();
    };

}

#endif // CONFIG_MANAGER_HPP
