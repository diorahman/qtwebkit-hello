#include "appwindow.h"
#include "page.h"

#include <QStatusBar>
#include <QEvent>
#include <QDebug>

AppWindow::AppWindow(QWidget *parent) :
    QMainWindow(parent), m_isFinished(false) {

#ifdef Q_OS_MAC
    setUnifiedTitleAndToolBarOnMac(true);
#endif

    m_page = new Page(this);
    m_page->run();
    setCentralWidget(m_page);

    // connections
    connect(m_page, SIGNAL(loadStarted()), this, SLOT(onLoadStarted()));
    connect(m_page, SIGNAL(loadProgress(int)), this, SLOT(onLoadProgress(int)));
    connect(m_page, SIGNAL(loadFinished(bool)), this, SLOT(onLoadFinished(bool)));
}

void AppWindow::onLoadProgress(int progress) {
    if(!m_isFinished){
        statusBar()->showMessage(QString("Loading (%1%)").arg(progress));
        statusBar()->show();
        m_page->hide();
    }
}

void AppWindow::onLoadFinished(bool success) {
    m_isFinished = true;
    if (success) {
        statusBar()->hide();
    } else {
        // todo: load custom html page to show the error
        statusBar()->showMessage("Something wrong");
        statusBar()->show();
        m_page->loadPageIndex(false);
    }
    m_page->show();
}

void AppWindow::onLoadStarted() {
    statusBar()->hide();
}
