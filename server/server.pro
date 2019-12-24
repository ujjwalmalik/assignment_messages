include(gtest_dependency.pri)
GOOGLETEST_DIR =
TEMPLATE = app
CONFIG += console

HEADERS += \
        tst_server.h \
    ../MessageReceiver.h \
    ../common.h

SOURCES += \
        main.cpp \
    ../MessageReceiver.cpp
