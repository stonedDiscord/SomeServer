TEMPLATE = subdirs

SUBDIRS += \
    automod \
    core\
    someserver

automod.subdir = project/automod
core.subdir = project/core
someserver.subdir = project/someserver

someserver.depends = automod core

