#include "packet.hpp"

#include <map>

namespace AkashiNetwork {
    class PacketFactory
    {
      public:
        static bool canCreatePacket(QString header);
        static AOPacket *createPacket(QString header, QStringList content);

        void registerPacket(AOPacket *(*builder)(QStringList content));

      private:
        static std::map<QString, AOPacket *(*)(QStringList)> m_builder_map;
    };
} // namespace AkashiNetwork
