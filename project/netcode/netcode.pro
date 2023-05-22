QT += network websockets

TEMPLATE = lib

# Apparently we need to define a static library to get a dynamic file.
# Whatever.
unix: CONFIG += shared static c++17
win32: CONFIG+= shared static c++17

# Needed so that Windows doesn't do `release/` and `debug/` subfolders
# in the output directory.
CONFIG -= \
        copy_dir_files \
        debug_and_release \
        debug_and_release_target

DESTDIR = $$PWD/../../bin
OBJECTS_DIR = $$PWD/build
MOC_DIR = $$PWD/build

HEADERS += \
    masterserver/include/masterserver_client.hpp \
    masterserver/include/masterserver_client_p.hpp \
    \
    socket/include/network_socket.hpp \
    socket/interfaces/network_socket_i.hpp \
    \
    aoprotocol/include/packet.hpp \
    aoprotocol/include/packet_info.hpp \
    aoprotocol/include/packet_factory.hpp \
    aoprotocol/include/packets/generic_packet.hpp \
    aoprotocol/include/packets/hi_packet.hpp \
    aoprotocol/include/packets/id_packet.hpp

SOURCES += \
    masterserver/src/masterserver_client.cpp \
    \
    socket/src/network_socket.cpp \
    \
    aoprotocol/src/packet.cpp \
    aoprotocol/src/packet_factory.cpp  \
    aoprotocol/src/packets/generic_packet.cpp \
    aoprotocol/src/packets/hi_packet.cpp \
    aoprotocol/src/packets/id_packet.cpp
