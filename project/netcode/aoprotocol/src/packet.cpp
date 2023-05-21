#include "aoprotocol/include/packet.hpp"
#include "aoprotocol/include/packet_factory.hpp"
#include "aoprotocol/include/packets/hi_packet.hpp"
#include "aoprotocol/include/packets/id_packet.hpp"

AkashiNetwork::AOPacket::AOPacket(QStringList p_contents) :
    m_content(p_contents),
    escaped(false)
{
}

const QStringList AkashiNetwork::AOPacket::getContent()
{
    return m_content;
}

QString AkashiNetwork::AOPacket::toString()
{
    if (!isPacketEscaped() && !(getPacketInfo().header == "LE")) {
        // We will never send unescaped data to a client, unless its evidence.
        this->escapeContent();
    }
    else {
        // Of course AO has SOME expection to the rule.
        this->escapeEvidence();
    }
    return QString("%1#%2#%3").arg(getPacketInfo().header, m_content.join("#"), packetFinished);
}

QByteArray AkashiNetwork::AOPacket::toUtf8()
{
    QString l_packet = this->toString();
    return l_packet.toUtf8();
}

void AkashiNetwork::AOPacket::setContentField(int f_content_index, QString f_content_data)
{
    m_content[f_content_index] = f_content_data;
}

void AkashiNetwork::AOPacket::escapeContent()
{
    m_content.replaceInStrings("#", "<num>")
        .replaceInStrings("%", "<percent>")
        .replaceInStrings("$", "<dollar>")
        .replaceInStrings("&", "<and>");
    this->setPacketEscaped(true);
}

void AkashiNetwork::AOPacket::unescapeContent()
{
    m_content.replaceInStrings("<num>", "#")
        .replaceInStrings("<percent>", "%")
        .replaceInStrings("<dollar>", "$")
        .replaceInStrings("<and>", "&");
    this->setPacketEscaped(false);
}

void AkashiNetwork::AOPacket::escapeEvidence()
{
    m_content.replaceInStrings("#", "<num>")
        .replaceInStrings("%", "<percent>")
        .replaceInStrings("$", "<dollar>");
    this->setPacketEscaped(true);
}

void AkashiNetwork::AOPacket::setPacketEscaped(bool f_packet_state)
{
    escaped = f_packet_state;
}

bool AkashiNetwork::AOPacket::isPacketEscaped()
{
    return escaped;
}

void AkashiNetwork::AOPacket::registerPackets()
{
    PacketFactory::registerClass<PacketHI>("HI");
    PacketFactory::registerClass<PacketID>("ID");
}
