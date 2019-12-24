include(gtest_dependency.pri)
GOOGLETEST_DIR =
TEMPLATE = app
CONFIG += console

HEADERS += \
        tst_client.h \
    ../common.h \
    ../MessageSender.h

SOURCES += \
        main.cpp \
    ../MessageSender.cpp
