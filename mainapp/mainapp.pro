TEMPLATE = app

CONFIG += Qt

QT += core gui widgets

SOURCES += \
    main.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../hmi/release/ -lhmi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../hmi/debug/ -lhmi
else:unix: LIBS += -L$$OUT_PWD/../hmi/ -lhmi

INCLUDEPATH += $$PWD/../hmi
DEPENDPATH += $$PWD/../hmi

INCLUDEPATH += $$PWD/../MedianFilterPlugin
LIBS += -L$$OUT_PWD/../MedianFilterPlugin -lMedianFilterPlugin
include(../opencv.pri)

