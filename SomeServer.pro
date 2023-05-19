TEMPLATE = subdirs

SUBDIRS += \
    automod \
    core\
    someserver \
    netcode

automod.subdir = project/automod
core.subdir = project/core
someserver.subdir = project/someserver
netcode.subdir = project/netcode

someserver.depends = automod core netcode

