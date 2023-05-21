#ifndef PACKET_GENERIC_H
#define PACKET_GENERIC_H

#include "aoprotocol/include/packet.hpp"

namespace AkashiNetwork {
    class PacketGeneric : public AOPacket
    {
      public:
        PacketGeneric(QString header, QStringList contents);
        virtual PacketInfo getPacketInfo() const;
        virtual bool validatePacket() const;

      private:
        QString header;
    };
}
#endif
