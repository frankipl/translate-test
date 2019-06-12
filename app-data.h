#ifndef APPDATA_H
#define APPDATA_H

#include <QObject>
#include <QtCore>

struct LangDataStruct {
    QString lang_code;
    QString lang_name;
    QString lang_locale;
};

class AppData: public QObject
{
    Q_OBJECT
public:
    AppData(QObject *parent,QSettings *settings);

    Q_PROPERTY(QString curr_lang_code MEMBER m_curr_lang_code NOTIFY currLangCodeChanged)
    Q_PROPERTY(QString curr_lang_name MEMBER m_curr_lang_name NOTIFY currLangNameChanged)

    Q_INVOKABLE void selectLang(QString lang_code);

public slots:
    void setTranslator(QTranslator *translator);
signals:
    void currLangNameChanged();
    void currLangCodeChanged();
    void retranslate();
private slots:
    void changeTranslation(QString lang_code);
    void translateLangMap();
    void setLangMap();
    void fillLangMap(QString lang_code,LangDataStruct *p);
    QString getLangName(QString lang_code);
private:
    QSettings   *settings;
    QString     m_curr_lang_code;
    QString     m_curr_lang_name;
    QMap<QString,LangDataStruct*> langMap;
    QTranslator *translator;
};
#endif // APPDATA_H
