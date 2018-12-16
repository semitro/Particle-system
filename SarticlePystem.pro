TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "/usr/include/SFML/"
INCLUDEPATH += "include/"

CONFIG(release, debug|release): LIBS +=  -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

HEADERS += \
    include/particle-system/core/particle.hpp

SOURCES += \
    src/particle-system/core/particle.cpp \
    src/main.cpp

SUBDIRS += \
    SarticlePystem.pro

