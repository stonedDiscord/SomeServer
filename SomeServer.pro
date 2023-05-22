TEMPLATE = subdirs

SUBDIRS += \
    automod \
    core\
    someserver \
    netcode \
    area

automod.subdir = project/automod
core.subdir = project/core
someserver.subdir = project/someserver
netcode.subdir = project/netcode
area.subdir = project/area

someserver.depends = automod core netcode area

