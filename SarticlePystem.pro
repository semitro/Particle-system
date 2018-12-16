TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "/usr/include/SFML/"
INCLUDEPATH += "include/"

CONFIG(release, debug|release): LIBS +=  -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

HEADERS += \
    include/particle-system/core/particle.hpp \
    include/particle-system/graphics/particlesystem.hpp \
    include/particle-system/core/particlelaw.hpp

SOURCES += \
    src/main.cpp \
    src/particle-system/core/particlelaw.cpp \
    src/particle-system/graphics/particlesystem.cpp \

SUBDIRS += \
    SarticlePystem.pro

