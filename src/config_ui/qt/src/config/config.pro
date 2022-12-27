QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    sources/mainwindow.cpp \
    sources/widgets/measuring.cpp \
    sources/widgets/variant_edit.cpp \
    sources/widgets/variant_edit/alarmlimitset.cpp \
    sources/widgets/variant_edit/extend/logicexpr.cpp \
    sources/widgets/variant_edit/mileageset.cpp \
    sources/widgets/variant_edit/unitset.cpp \
    sources/widgets/variant_edit/unitset/selectunit.cpp \
    sources/widgets/welcome.cpp

HEADERS += \
    headers/mainwindow.h \
    headers/widgets/measuring.h \
    headers/widgets/variant_edit.h \
    headers/widgets/variant_edit/alarmlimitset.h \
    headers/widgets/variant_edit/extend/logicexpr.h \
    headers/widgets/variant_edit/mileageset.h \
    headers/widgets/variant_edit/unitset.h \
    headers/widgets/variant_edit/unitset/selectunit.h \
    headers/widgets/welcome.h

FORMS += \
    ui/variant_edit/extend/ve_ed_logicexpr.ui \
    ui/variant_edit/unitset/ve_us_selectunit.ui \
    ui/variant_edit/ve_alarmlimitset.ui \
    ui/variant_edit/ve_basic.ui \
    ui/variant_edit/ve_extend.ui \
    ui/variant_edit/ve_mileageset.ui \
    ui/variant_edit/ve_unitset.ui \
    ui/main.ui \
    ui/measuring.ui \
    ui/variant_edit.ui \
    ui/welcome.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
