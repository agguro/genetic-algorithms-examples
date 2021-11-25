TEMPLATE = app
CONFIG += c++11 console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        chromosome.cpp \
        gene.cpp \
        main.cpp \
        population.cpp

HEADERS += \
    chromosome.h \
    gene.h \
    population.h
