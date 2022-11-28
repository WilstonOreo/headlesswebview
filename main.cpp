#include "widget.h"

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCommandLineParser parser;
    parser.setApplicationDescription("WebEngine Browser Window");
    parser.addVersionOption();
    parser.addHelpOption();

    parser.addOptions({
        {"x", QCoreApplication::translate("main", "X position"), "int"},
        {"y", QCoreApplication::translate("main", "Y position"), "int"},
        {"width", QCoreApplication::translate("main", "Window width"), "int"},
        {"height", QCoreApplication::translate("main", "Window height"), "int"},
        {"url",
         QCoreApplication::translate("main", "URL to be loaded"),
         QCoreApplication::translate("main", "URL")},
    });
    parser.process(app);

    QRect geometry(parser.isSet("x") ? parser.value("x").toInt() : 0,
                   parser.isSet("y") ? parser.value("y").toInt() : 0,
                   parser.isSet("width") ? parser.value("width").toInt() : 1024,
                   parser.isSet("height") ? parser.value("height").toInt() : 768);

    QWebEngineView view;
    if (parser.isSet("x") || parser.isSet("y"))
        view.setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    view.setGeometry(geometry);
    view.setPage(new WebEnginePage(&view));
    qDebug() << parser.value("url");
    view.setUrl(QUrl::fromUserInput(parser.value("url")));
    view.show();

    return app.exec();
}
