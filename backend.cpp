#include "backend.h"
#include "zmienne.h"

BackEnd::BackEnd(QQmlApplicationEngine *engine) {
    this->engine=engine;

    if(QFile(Zm().confDir+Zm().configFile).exists()) {
        this->settings=new QSettings(Zm().confDir+Zm().configFile,QSettings::IniFormat,this);
        qDebug()<<"BackEnd::BackEnd using config file:"<<Zm().confDir+Zm().configFile;
    } else {
        this->settings=new QSettings(QString::fromUtf8(":config/")+Zm().configFile,QSettings::IniFormat,this);
        qDebug()<<"BackEnd::BackEnd creating config file:"<<Zm().confDir+Zm().configFile;
        QStringList list=settings->allKeys();
        QSettings *s2=new QSettings(Zm().confDir+Zm().configFile,QSettings::IniFormat,this);
        for(int i=0;i<list.count();i++) {
            s2->setValue(list.at(i),settings->value(list.at(i)).toString());
            qDebug()<<"BackEnd::BackEnd key:"<<list.at(i)<<" val:"<<settings->value(list.at(i)).toString();
        }
        s2->sync();
        delete s2;
        delete settings;
        settings=new QSettings(Zm().confDir+Zm().configFile,QSettings::IniFormat,this);
    }
    this->setVariables();

    appData=new AppData(this,settings);

    connect(appData,SIGNAL(retranslate()),this,SLOT(retranslate()));

    context=engine->rootContext();
    context->setContextProperty("AppData",appData);

}
void BackEnd::init(QTranslator *translator) {
    qDebug()<<"BackEnd::init locale:"<<Zm().lang_locale;
    rootObject=engine->rootObjects().first();
  //  qmlObject = rootObject->findChild<QObject*>("mainApp");

    qDebug()<<"rootObjects:"<<rootObject;
    appData->setTranslator(translator);
}
void BackEnd::retranslate() {
    qDebug()<<"BackEnd::retranslate";
    engine->retranslate();
}
void BackEnd::setVariables() {
    Zm().lang_code=settings->value("lang_code").toString();
    Zm().lang_locale=QLocale(settings->value("lang_locale").toString());
}
BackEnd::~BackEnd() {
}
