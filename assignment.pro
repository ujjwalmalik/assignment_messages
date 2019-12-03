include(gtest_dependency.pri)
GOOGLETEST_DIR =
TEMPLATE = app
CONFIG += console
#CONFIG -= app_bundle
#CONFIG += thread
#CONFIG -= qt

HEADERS += \
        tst_client.h \
    client.h \
    common.h

SOURCES += \
        main.cpp \
    client.cpp
