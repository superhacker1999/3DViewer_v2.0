QT       += core gui openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../controller/controller.cc \
    ../model/facade/model.cc \
    ../model/subsystems/parser.cc \
    ../model/subsystems/shifter.cc \
    ../model/subsystems/spinner.cc \
    interface/iface.cpp \
    main.cpp \
    render/render.cpp \
    view.cpp

HEADERS += \
    ../controller/controller.h \
    ../model/facade/model.h \
    ../model/helpers/s21_matrix.h \
    ../model/helpers/using.h \
    ../model/subsystems/parser.h \
    ../model/subsystems/shifter.h \
    ../model/subsystems/spinner.h \
    ../model/subsystems/subsystems.h \
    interface/iface.h \
    render/render.h \
    view.h \
    /usr/local/lib/gcc/11/gcc/x86_64-apple-darwin20/11/include/omp.h

FORMS += \
    interface/iface.ui \
    view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
