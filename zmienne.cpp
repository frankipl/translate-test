#include "zmienne.h"

Singleton::Singleton():QObject() {
// konstruktor klasy - nie używany :))


#if defined(Q_OS_LINUX)

    mainPath=QDir::currentPath();
    confDir=mainPath+QDir::separator()+QString("config")+QDir::separator();
#elif defined(Q_OS_ANDROID)
    appName=QString::fromUtf8("octobersoftware.catcher");
    QDir dir(QStandardPaths::standardLocations(QStandardPaths::DataLocation).value(0));
    mainPath=dir.path()+QDir::separator();
#elif defined(Q_OS_IOS) || defined(Q_OS_MAC)
    appName=QString::fromUtf8("octobersoftware.catcher");
    QDir dir(QStandardPaths::standardLocations(QStandardPaths::DataLocation).value(0));
    mainPath=dir.path()+QDir::separator();

    #ifdef __APPLE__
        #ifdef TARGET_OS_IPHONE
            // iOS
            confDir=mainPath+QString("Documents/");
        #elif TARGET_IPHONE_SIMULATOR
            // iOS Simulator
            confDir=mainPath+QString("Documents/");
        #elif TARGET_OS_MAC
            // Other kinds of Mac OS
        #else
            // Unsupported platform
        #endif
    #else
        confDir=mainPath;
    #endif
#endif

    pixelRatio=QGuiApplication::primaryScreen()->devicePixelRatio();


    configFile=QString::fromUtf8("parcel-watcher.conf");


}
Singleton& Zm() {
// funkcja glowna singletonu
	static Singleton zmienne;
	return zmienne;
}
