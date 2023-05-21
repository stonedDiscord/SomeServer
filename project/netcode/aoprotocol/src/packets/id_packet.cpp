#include "aoprotocol/include/packets/id_packet.hpp"
#include <QDebug>

using namespace AkashiNetwork;

PacketID::PacketID(QStringList &contents) :
    AOPacket(contents)
{
}

PacketInfo PacketID::getPacketInfo() const
{
    PacketInfo info{
        .min_args = 2,
        .header = "ID"};
    return info;
}

bool PacketID::validatePacket() const
{
    return true;
}
