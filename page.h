#ifndef PAGE_H
#define PAGE_H

#include <QWebView>
#include <QVariantMap>

class WebKitHelloWebPage : public QWebPage {
    QString userAgentForUrl(const QUrl & url) const;
};

class Page : public QWebView {

  Q_OBJECT

public:
  explicit Page(QWidget * parent = 0);
  ~Page();

private slots:
  void loadNativeObject();

public slots:
    void run();
    void loadPageIndex(bool success);
};

#endif
