QT += network websockets core

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
    include/server.hpp \
    include/server_p.hpp \
    include/client/client_manager.hpp \
    include/client/client_manager_p.hpp \
    include/client/client.hpp \
    include/client/client_p.hpp \
    include/network/connection_handler.hpp \
    include/network/connection_handler_p.hpp \
    include/configuration/config_manager.hpp \
    include/configuration/config_manager_p.hpp

SOURCES += \
    src/server.cpp \
    src/connection_handler.cpp \
    src/config_manager.cpp \
    src/client/client_manager.cpp \
    src/client/client.cpp
