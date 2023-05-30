TEMPLATE = subdirs

SUBDIRS += \
    core \
    someserver \
    net

core.subdir = project/core
core.depends = net
someserver.subdir = project/someserver
someserver.depends = core net
net.subdir = project/net
