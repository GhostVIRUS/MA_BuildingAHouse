TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Scene.cpp \
    Wall.cpp \
    House.cpp \
    Geometry.cpp

HEADERS += \
    Scene.h \
    Wall.h \
    House.h \
    Geometry.h
