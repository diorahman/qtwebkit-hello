#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include <QUrl>

class Page;

class AppWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit AppWindow(QWidget *parent = 0);

private slots:
    void onLoadProgress(int);
    void onLoadFinished(bool);
    void onLoadStarted();

private:
    Page * m_page;
};

#endif // APPWINDOW_H
