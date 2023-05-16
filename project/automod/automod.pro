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
OBJECTS_DIR = $$PWD/../build
MOC_DIR = $$PWD/../build

HEADERS += \
    include/automod.hpp

SOURCES += \
    src/automod.cpp
