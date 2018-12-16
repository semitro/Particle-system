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
    include/particle-system/core/particlelaw.hpp \
    include/particle-system/core/emitter.hpp \
    include/particle-system/core/oneoffemitter.hpp \
    include/particle-system/core/newtonlaw.hpp

SOURCES += \
    src/main.cpp \
    src/particle-system/core/particlelaw.cpp \
    src/particle-system/graphics/particlesystem.cpp \
    src/particle-system/core/oneoffemitter.cpp \
    include/particle-system/core/newtonlaw.cpp

SUBDIRS += \
    SarticlePystem.pro

DISTFILES+=
        shaders/shader.frag

