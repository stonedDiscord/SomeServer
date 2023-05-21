#include "aoprotocol/include/packets/generic_packet.hpp"

#include <QDebug>

using namespace AkashiNetwork;

PacketGeneric::PacketGeneric(QString header, QStringList contents) :
    AOPacket(contents),
    header(header)
{
}

PacketInfo PacketGeneric::getPacketInfo() const
{
    PacketInfo info{
        .min_args = 0,
        .header = header};
    return info;
}

bool PacketGeneric::validatePacket() const
{
    qDebug() << "ERROR: Cannot handle generic packet: " << header;
    qDebug() << "Packet is either unimplemented, or is meant to be sent to client";
    return false;
}
