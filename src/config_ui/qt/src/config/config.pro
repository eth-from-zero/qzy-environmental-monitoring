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
    sources/widgets/common/confirmation_dialog.cpp \
    sources/widgets/device/device.cpp \
    sources/widgets/device/params_config/channel/dv_pc_device_channel.cpp \
    sources/widgets/device/params_config/dv_params_config.cpp \
    sources/widgets/device/params_config/timer/dv_pc_timer.cpp \
    sources/widgets/measurement/measurement.cpp \
    sources/widgets/measurement/variant_edit/alarmlimitset.cpp \
    sources/widgets/measurement/variant_edit/alarmlimitset/alarmlimitedit.cpp \
    sources/widgets/measurement/variant_edit/extend/logicexpr.cpp \
    sources/widgets/measurement/variant_edit/extend/selectvar.cpp \
    sources/widgets/measurement/variant_edit/measuringset.cpp \
    sources/widgets/measurement/variant_edit/measuringset/measuringedit.cpp \
    sources/widgets/measurement/variant_edit/mm_variant_edit.cpp \
    sources/widgets/measurement/variant_edit/unitset.cpp \
    sources/widgets/measurement/variant_edit/unitset/selectunit.cpp \
    sources/widgets/other/operator_config/atomic/other_oc_ac_edit.cpp \
    sources/widgets/other/operator_config/atomic/other_oc_atomic.cpp \
    sources/widgets/other/operator_config/operator_config.cpp \
    sources/widgets/other/operator_config/process/other_oc_process.cpp \
    sources/widgets/other/operator_config/sysmode/other_oc_sysmode.cpp \
    sources/widgets/other/other.cpp \
    sources/widgets/serialport/serialport.cpp \
    sources/widgets/switching/switching.cpp \
    sources/widgets/switching/variant_edit/si_variant_edit.cpp \
    sources/widgets/switching/variant_edit/type_brower/ss_ve_type_brower.cpp \
    sources/widgets/welcome.cpp

HEADERS += \
    headers/mainwindow.h \
    headers/widgets/common/confirmation_dialog.h \
    headers/widgets/device/device.h \
    headers/widgets/device/params_config/channel/dv_pc_device_channel.h \
    headers/widgets/device/params_config/dv_params_config.h \
    headers/widgets/device/params_config/timer/dv_pc_timer.h \
    headers/widgets/measurement/measurement.h \
    headers/widgets/measurement/variant_edit/alarmlimitset.h \
    headers/widgets/measurement/variant_edit/alarmlimitset/alarmlimitedit.h \
    headers/widgets/measurement/variant_edit/extend/logicexpr.h \
    headers/widgets/measurement/variant_edit/extend/selectvar.h \
    headers/widgets/measurement/variant_edit/measuringset.h \
    headers/widgets/measurement/variant_edit/measuringset/measuringedit.h \
    headers/widgets/measurement/variant_edit/mm_variant_edit.h \
    headers/widgets/measurement/variant_edit/unitset.h \
    headers/widgets/measurement/variant_edit/unitset/selectunit.h \
    headers/widgets/other/operator_config/atomic/other_oc_ac_edit.h \
    headers/widgets/other/operator_config/atomic/other_oc_atomic.h \
    headers/widgets/other/operator_config/process/other_oc_process.h \
    headers/widgets/other/operator_config/sysmode/other_oc_sysmode.h \
    headers/widgets/other/other.h \
    headers/widgets/serialport/serialport.h \
    headers/widgets/switching/switching.h \
    headers/widgets/switching/variant_edit/si_variant_edit.h \
    headers/widgets/switching/variant_edit/type_brower/ss_ve_type_brower.h \
    headers/widgets/welcome.h \
    headers/widgets/other/operator_config/operator_config.h \
    sources/widgets/other/operator_config/operator_config.h

FORMS += \
    ui/common/confirmation_dialog.ui \
    ui/device/device.ui \
    ui/device/params_config/channel/dv_pc_device_channel.ui \
    ui/device/params_config/dv_params_config.ui \
    ui/device/params_config/timer/dv_pc_timer.ui \
    ui/measurement/measurement.ui \
    ui/measurement/variant_edit/alarmlimitset/ve_al_alarmlimitedit.ui \
    ui/measurement/variant_edit/extend/ve_ed_logicexpr.ui \
    ui/measurement/variant_edit/extend/ve_ed_selectvar.ui \
    ui/measurement/variant_edit/measuringset/ve_me_measuringedit.ui \
    ui/measurement/variant_edit/mm_variant_edit.ui \
    ui/measurement/variant_edit/unitset/ve_us_selectunit.ui \
    ui/measurement/variant_edit/ve_alarmlimitset.ui \
    ui/measurement/variant_edit/ve_basic.ui \
    ui/measurement/variant_edit/ve_extend.ui \
    ui/measurement/variant_edit/ve_measuringset.ui \
    ui/measurement/variant_edit/ve_unitset.ui \
    ui/other/operator_config/atomic/other_oc_ac_edit.ui \
    ui/other/operator_config/atomic/other_oc_atomic.ui \
    ui/other/operator_config/other_operator_config.ui \
    ui/other/operator_config/process/other_oc_process.ui \
    ui/other/operator_config/sysmod/other_oc_sysmode.ui \
    ui/other/other.ui \
    ui/serialport/serialport.ui \
    ui/switching/switching.ui \
    ui/main.ui \
    ui/switching/variant_edit/si_variant_edit.ui \
    ui/switching/variant_edit/si_ve_type_brower.ui \
    ui/welcome.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
