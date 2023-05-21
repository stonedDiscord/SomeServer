#ifndef ID_PACKET_HPP
#define ID_PACKET_HPP

#include "aoprotocol/include/packet.hpp"

namespace AkashiNetwork {
    class PacketID : public AOPacket
    {
      public:
        PacketID(QStringList &contents);
        virtual PacketInfo getPacketInfo() const;
        virtual bool validatePacket() const;
    };
}
#endif // ID_PACKET_HPP
