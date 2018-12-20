TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT += core gui charts

INCLUDEPATH += "/usr/include/SFML/"
INCLUDEPATH += "include/"

CONFIG(release, debug|release): LIBS +=  -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

HEADERS += \
    include/particle-system/core/particle.hpp \
    include/particle-system/core/particlelaw.hpp \
    include/particle-system/core/emitter.hpp \
    include/particle-system/core/oneoffemitter.hpp \
    include/particle-system/core/newtonlaw.hpp \
    include/particle-system/core/circleemitter.hpp \
    include/particle-system/core/attractor.hpp \
    include/particle-system/core/basicattractor.hpp \
    include/particle-system/core/emptyattractor.hpp \
    include/particle-system/core/particlesystem.hpp \
    include/particle-system/graphics/particlesdrawer.hpp \
    gui/facilitymenu.hpp \
    gui/qsfmlintegration.hpp \
    gui/particlesystemwindow.hpp

SOURCES += \
    src/main.cpp \
    src/particle-system/core/particlelaw.cpp \
    src/particle-system/core/oneoffemitter.cpp \
    src/particle-system/core/newtonlaw.cpp \
    src/particle-system/core/circleemitter.cpp \
    src/particle-system/core/basicattractor.cpp \
    src/particle-system/core/particlesystem.cpp \
    src/particle-system/graphics/particlesdrawer.cpp \
    gui/facilitymenu.cpp \
    gui/qsfmlintegration.cpp \
    gui/particlesystemwindow.cpp

SUBDIRS += \
    SarticlePystem.pro

DISTFILES+= \
        shaders/shader.frag

FORMS += \
    gui/facilitymenu.ui

