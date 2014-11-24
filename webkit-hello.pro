SOURCES += appwindow.cpp main.cpp page.cpp utils.cpp
HEADERS += appwindow.h page.h utils.h

QT += webkit

QT += network webkit
QT -= declarative

macx {
    CONFIG -= app_bundle
}