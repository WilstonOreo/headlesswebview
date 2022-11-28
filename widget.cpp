#include "widget.h"

#include <QWebEngineFullScreenRequest>
#include <QWebEngineSettings>
#include <QWebEngineView>

WebEnginePage::WebEnginePage(QObject *parent) : QWebEnginePage(parent)
{
    connect(this,
            &WebEnginePage::featurePermissionRequested,
            this,
            &WebEnginePage::onFeaturePermissionRequested);
}

void WebEnginePage::onFeaturePermissionRequested(const QUrl &securityOrigin, Feature feature)
{
    if (feature == QWebEnginePage::MediaAudioCapture || feature == QWebEnginePage::MediaVideoCapture
        || feature == QWebEnginePage::MediaAudioVideoCapture)
        setFeaturePermission(securityOrigin, feature, QWebEnginePage::PermissionGrantedByUser);
    else
        setFeaturePermission(securityOrigin, feature, QWebEnginePage::PermissionDeniedByUser);
}
