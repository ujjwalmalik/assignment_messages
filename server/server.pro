include(gtest_dependency.pri)
GOOGLETEST_DIR =
TEMPLATE = app
CONFIG += console

HEADERS += \
        tst_server.h \
    server.h \
    ../common.h

SOURCES += \
        main.cpp \
    server.cpp
