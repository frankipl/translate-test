#ifndef ZMIENNE
#define ZMIENNE
#include <QStandardPaths>
#include <QGuiApplication>
#include <QScreen>
#include <qstring.h>
#include <qvariant.h>
#include <QObject>
#include <QDir>

class QString;
class QVariant;


class Singleton: public QObject {
    Q_OBJECT
// definicja klasy o nazwie Singleton - jest
// to nazwa wlasna :)
public:

    QString mainPath;
    QString confDir;
    QString configFile;
    qreal   pixelRatio;
    QLocale lang_locale;
    QString lang_code;


public slots:

private:
	Singleton();
	Singleton(const Singleton&);
	// konstruktor klasy

	friend Singleton& Zm();
};

Singleton& Zm();

#endif //ZMIENNE
