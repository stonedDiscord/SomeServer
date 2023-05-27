TEMPLATE = subdirs

SUBDIRS += \
    core\
    someserver \
    netcode \
    area

automod.subdir = project/automod
core.subdir = project/core
someserver.subdir = project/someserver
netcode.subdir = project/netcode
area.subdir = project/area

someserver.depends = core netcode area
