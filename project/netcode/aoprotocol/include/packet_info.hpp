#ifndef PACKET_INFO_HPP
#define PACKET_INFO_HPP

#include <QString>

namespace AkashiNetwork {
    class PacketInfo
    {
      public:
        int min_args; //!< The minimum arguments needed for the packet to be interpreted correctly / make sense.
        QString header;
    };
#endif
}
