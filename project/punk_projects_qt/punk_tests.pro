######################################################################
# Automatically generated by qmake (2.01a) ?? 25. ??? 21:35:03 2013
######################################################################

QMAKE_CXXFLAGS += -std=c++11

CONFIG -= QT

DEFINES += _WIN32 USE_OPENGL

TEMPLATE = app
TARGET = punk_tests

DEPENDPATH += . ..\..\source\tests\test_create_opengl_window
DEPENDPATH += . ..\..\source\tests\test_create_opengl_window

Release:LIBPATH += ./../../bin/release
Debug:LIBPATH += ./../../bin/debug

LIBS += -lpunk_engine

Release:DESTDIR = ./../../bin/release
Release:OBJECTS_DIR = release/.obj
Release:MOC_DIR = release/.moc
Release:RCC_DIR = release/.rcc
Release:UI_DIR = release/.ui

Debug:DESTDIR = ./../../bin/debug
Debug:OBJECTS_DIR = debug/.obj
Debug:MOC_DIR = debug/.moc
Debug:RCC_DIR = debug/.rcc
Debug:UI_DIR = debug/.ui

# Input
HEADERS += ../../source/tests/test_create_opengl_window/test_create_opengl_window.h \
           ../../source/tests/test_interface.h \
    ../../source/tests/test_clear_window/test_clear_buffer.h \
    ../../source/tests/test_first_triangle/firsttriangleandquad.h \
    rotate_triangle.h \
    ../../source/tests/rotate_triangle.h \
    ../../source/tests/colored_triangle_test.h \
    ../../source/tests/test5.h \
    ../../source/tests/test6.h \
    ../../source/tests/test7.h \
    ../../source/tests/test8.h \
    ../../source/tests/test9.h \
    ../../source/tests/test3.h \
    ../../source/tests/test10.h \
    ../../source/tests/test11.cpp \
    ../../source/tests/test2.h \
    ../../source/tests/test12.h \
    ../../source/tests/test13.h \
    ../../source/tests/test14.h

SOURCES += ../../source/tests/main.cpp \
           ../../source/tests/test_create_opengl_window/test_create_opengl_window.cpp \
    ../../source/tests/test_clear_window/test_clear_buffer.cpp \
    ../../source/tests/test_first_triangle/firsttriangleandquad.cpp \
    ../../source/tests/colored_triangle_test.cpp \
    ../../source/tests/rotate_triangle.cpp \
    ../../source/tests/test5.cpp \
    ../../source/tests/test6.cpp \
    ../../source/tests/test7.cpp \
    ../../source/tests/test8.cpp \
    ../../source/tests/test9.cpp \
    ../../source/tests/test3.cpp \
    ../../source/tests/test10.cpp \
    ../../source/tests/test11.cpp \
    ../../source/tests/test2.cpp \
    ../../source/tests/test12.cpp \
    ../../source/tests/test13.cpp \
    ../../source/tests/test14.cpp

