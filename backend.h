#ifndef BACKEND_H
#define BACKEND_H

#include <QtCore>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "app-data.h"

class BackEnd:public QObject {
    Q_OBJECT
public:
    BackEnd(QQmlApplicationEngine *engine);
    ~BackEnd();
public slots:
    void init(QTranslator *translator);
    void retranslate();
signals:
private slots:
    void setVariables();
private:
    QQmlApplicationEngine   *engine;
    QQmlContext     *context;
    QObject         *rootObject;
    QObject         *qmlObject;
    QSettings       *settings;
    AppData         *appData;
};

#endif // BACKEND_H
