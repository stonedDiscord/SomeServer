#include "packet_factory.hpp"

#include <QDebug>

using namespace AkashiNetwork;

namespace AkashiNetwork {
    std::map<QString, AOPacket *(*)(QStringList)> PacketFactory::m_builder_map;

    bool PacketFactory::canCreatePacket(QString header)
    {
        return m_builder_map.count(header);
    }

    AOPacket *PacketFactory::createPacket(QString header, QStringList content)
    {
        return m_builder_map[header](content);
    }

    void PacketFactory::registerPacket(AOPacket *(*builder)(QStringList))
    {
        AOPacket *packet = (*builder)(QStringList{});
        PacketInfo info = packet->getPacketInfo();
        Q_ASSERT(!m_builder_map.count(info.header));
        m_builder_map[info.header] = builder;
        delete packet;
    }

} // namespace AkashiNetwork
