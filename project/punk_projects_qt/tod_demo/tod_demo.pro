######################################################################
# Automatically generated by qmake (2.01a) ?? 25. ??? 21:35:03 2013
######################################################################

*g++* : QMAKE_LFLAGS += -Wl,-z,origin \'-Wl,-rpath,\$\$ORIGIN/\'

QMAKE_CXXFLAGS += -std=c++11

CONFIG -= QT

TEMPLATE = app
TARGET = game_demo

release:LIBPATH += ./../../../bin/release
debug:LIBPATH += ./../../../bin/debug

release:DESTDIR = ./../../../bin/release
release:OBJECTS_DIR = release/.obj
release:MOC_DIR = release/.moc
release:RCC_DIR = release/.rcc
release:UI_DIR = release/.ui

debug:DESTDIR = ./../../../bin/debug
debug:OBJECTS_DIR = debug/.obj
debug:MOC_DIR = debug/.moc
debug:RCC_DIR = debug/.rcc
debug:UI_DIR = debug/.ui

win32 {
DEFINES += _WIN32
}

SOURCES += main.cpp \
    enemy.cpp

releas:MYDLLDIR = $$IN_PWD/../../../../bin/release
debug:MYDLLDIR = $$IN_PWD/../../../../bin/debug

# As our header files are in the same directory, we can make Qt Creator find it
# by specifying it as INCLUDEPATH.
INCLUDEPATH += $$MYDLLDIR

# Dependency to library domain (libdomain.so for Unices or domain.dll on Win32)
# Repeat this for more libraries if needed.
win32:LIBS += $$quote($$MYDLLDIR/domain.dll)
 unix:LIBS += $$quote(-L$$MYDLLDIR) -lpunk_engine -lGL -lXext -lX11 -lXxf86vm

HEADERS += \
    enemy.h \
    game_objects.h