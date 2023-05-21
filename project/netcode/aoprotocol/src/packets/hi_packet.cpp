#include "aoprotocol/include/packets/hi_packet.hpp"

#include <QDebug>

using namespace AkashiNetwork;

PacketHI::PacketHI(QStringList &contents) :
    AOPacket(contents)
{
}

PacketInfo PacketHI::getPacketInfo() const
{
    PacketInfo info{
        .min_args = 1,
        .header = "HI"};
    return info;
}

bool PacketHI::validatePacket() const
{
    // We can always convert a string to a string. No point in checking.
    return true;
}
