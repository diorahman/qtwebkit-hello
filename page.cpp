#include "page.h"
#include "Utils.h"

#include <QUrl>
#include <QWebFrame>
#include <QDir>
#include <QDebug>

/*
 * Constructor
 */
Page::Page(QWidget * parent) : QWebView(parent) {
    setObjectName("WebKitHelloWebPage");
    setPage(new WebKitHelloWebPage);

    // uncomment following line to remove or handle right-click events (don't show context menu)
    // setContextMenuPolicy(Qt::NoContextMenu);

    // inspector, will be removed after release
    page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

    // some settings

    // false
    page()->settings()->setAttribute(QWebSettings::JavaEnabled, false);
    page()->settings()->setAttribute(QWebSettings::PluginsEnabled, false);

    // true
    page()->settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);

    // connections
    QObject::connect(page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(loadNativeObject()));
}

/*
 * Destructor
 */
Page::~Page() {
}

void Page::run() {
    loadPageIndex(true);
}

/*
 * Add js object and load plugin
 */
void Page::loadNativeObject() {
    qDebug() << "load native object";
}

void Page::loadPageIndex(bool success) {
    Q_UNUSED(success)

#ifdef Q_OS_WIN32
    QUrl index = QUrl( "file:///" + QDir::toNativeSeparators(Utils::adjustPath("html/index.html")).replace("\\","/"));
#else
    QUrl index = QUrl("html/index.html");
#endif
    setUrl(index);
}

QString WebKitHelloWebPage::userAgentForUrl(const QUrl &url) const {
    Q_UNUSED(url);
    return QString("WebKit Hello v0.0.1");
}
