#include <QApplication>
#include <FelgoApplication>
#include "backend.h"
#include "zmienne.h"
#include <QQmlApplicationEngine>

// uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
//#include <FelgoLiveClient>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSettings *settings;
    if(QFile(Zm().confDir+Zm().configFile).exists()) {
        settings=new QSettings(Zm().confDir+Zm().configFile,QSettings::IniFormat);
    } else {
        settings=new QSettings(QString(":/config/")+Zm().configFile,QSettings::IniFormat);
    }
    Zm().lang_code=settings->value(QString("lang_code")).toString();
    qDebug()<<"Main lang_code:"<<Zm().lang_code;
    delete settings;

    QTranslator *translator=new QTranslator();
    if(Zm().lang_code!=QString("pl")) {
        QString translations =QString(":/translations/translate-test_%1").arg(Zm().lang_code);
        app.removeTranslator(translator);
        //QApplication::instance()->removeTranslator(&translator);
        if (translator->load(translations)) {
            qDebug() << "LOAD FINISHED";
            app.installTranslator(translator);
            //QApplication::instance()->installTranslator(&translator);
        } else {
            qDebug() << "COULD NOT INSTALL TRANSLATIONS " << translations;
        }
    }

    FelgoApplication felgo;

    // Use platform-specific fonts instead of Felgo's default font
    felgo.setPreservePlatformFonts(true);

    QQmlApplicationEngine engine;
    felgo.initialize(&engine);

    // Set an optional license key from project file
    // This does not work if using Felgo Live, only for Felgo Cloud Builds and local builds
    felgo.setLicenseKey(PRODUCT_LICENSE_KEY);

    // use this during development
    // for PUBLISHING, use the entry point below
    //felgo.setMainQmlFileName(QStringLiteral("qml/Main.qml"));

    // use this instead of the above call to avoid deployment of the qml files and compile them into the binary with qt's resource system qrc
    // this is the preferred deployment option for publishing games to the app stores, because then your qml files and js files are protected
    // to avoid deployment of your qml files and images, also comment the DEPLOYMENTFOLDERS command in the .pro file
    // also see the .pro file for more details
     felgo.setMainQmlFileName(QStringLiteral("qrc:/qml/Main.qml"));

     BackEnd backEnd(&engine);

    engine.load(QUrl(felgo.mainQmlFileName()));

    backEnd.init(translator);
    // to start your project as Live Client, comment (remove) the lines "felgo.setMainQmlFileName ..." & "engine.load ...",
    // and uncomment the line below
    //FelgoLiveClient client (&engine);

    return app.exec();
}
