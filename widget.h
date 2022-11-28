#pragma once

#include <QWebEngineFullScreenRequest>
#include <QWebEngineView>
#include <QWidget>

class WebEnginePage : public QWebEnginePage
{
    Q_OBJECT
public:
    WebEnginePage(QObject *parent = nullptr);
private Q_SLOTS:
    void onFeaturePermissionRequested(const QUrl &securityOrigin, QWebEnginePage::Feature feature);
};
