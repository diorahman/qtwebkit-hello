SOURCES += appwindow.cpp main.cpp page.cpp utils.cpp
HEADERS += appwindow.h page.h utils.h

QT += webkit

QT += network webkit
QT -= declarative

macx {
    CONFIG -= app_bundle
}

# deployment script
source = $$PWD/html
source = $$replace(source, /, \\)
target = $$OUT_PWD/html
target = $$replace(target, /, \\)
copydata.commands = $(COPY_DIR) \"$$source\" \"$$target\"
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata

