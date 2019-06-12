#include "app-data.h"
#include "zmienne.h"

AppData::AppData(QObject *parent,QSettings *settings): QObject (parent)
{
    this->settings = settings;

    this->setLangMap();

    m_curr_lang_code=Zm().lang_code;
    m_curr_lang_name=this->getLangName(Zm().lang_code);
    emit currLangCodeChanged();
    emit currLangNameChanged();
}
void AppData::selectLang(QString lang_code) {
    if(!langMap.contains(lang_code)) {
        qWarning()<<"AppData::selectLang unknown lang_code:"<<lang_code;
        return;
    }
    LangDataStruct *p=langMap[lang_code];

    settings->setValue("lang_code",p->lang_code);
    settings->setValue("lang_locale",p->lang_locale);
    Zm().lang_code=p->lang_code;
    Zm().lang_locale=QLocale(p->lang_locale);

    this->changeTranslation(p->lang_code);
    this->translateLangMap();

    m_curr_lang_code=p->lang_code;
    m_curr_lang_name=p->lang_name;
    emit currLangCodeChanged();
    emit currLangNameChanged();

    emit retranslate();
}
void AppData::changeTranslation(QString lang_code) {
    QCoreApplication::instance()->removeTranslator(translator);
    if(lang_code!=QString("pl")) {
        QString translations =QString(":/translations/translate-test_%1").arg(lang_code);
        //QApplication::instance()->removeTranslator(&translator);
        if (translator->load(translations)) {
            qDebug() << "LOAD FINISHED";
            QCoreApplication::instance()->installTranslator(translator);
            //QApplication::instance()->installTranslator(&translator);
        } else {
            qDebug() << "COULD NOT INSTALL TRANSLATIONS " << translations;
        }
    }
}
void AppData::translateLangMap() {
    QMapIterator<QString,LangDataStruct*> i(langMap);
    while(i.hasNext()) {
        i.next();
        this->fillLangMap(i.value()->lang_code,i.value());
    }
}
void AppData::setLangMap() {
    LangDataStruct *p=new LangDataStruct;
    p->lang_code=QString("pl");
    this->fillLangMap(p->lang_code,p);
    langMap.insert(p->lang_code,p);

    p=new LangDataStruct;
    p->lang_code=QString("en");
    this->fillLangMap(p->lang_code,p);
    langMap.insert(p->lang_code,p);

    p=new LangDataStruct;
    p->lang_code=QString("de");
    this->fillLangMap(p->lang_code,p);
    langMap.insert(p->lang_code,p);
}
void AppData::fillLangMap(QString lang_code,LangDataStruct *p) {
    if(lang_code==QString("pl")) {
        p->lang_locale=QString("pl_PL");
        p->lang_name=tr("Polish");
    } else if(lang_code==QString("en")) {
        p->lang_locale=QString("en_EN");
        p->lang_name=tr("English");
    }
    else if(lang_code==QString("de")) {
        p->lang_locale=QString("de_DE");
        p->lang_name=tr("Deutsch");
    }
    else {
        qWarning()<<"AppData::fillLangMap unknown lang_code:"<<lang_code;
    }
}
void AppData::setTranslator(QTranslator *translator) {
    this->translator=translator;
}
QString AppData::getLangName(QString lang_code) {
    if(!langMap.contains(lang_code)) {
        qWarning()<<"AppData::getLangName unknown lang_code:"<<lang_code;
        return QString("Lang error");
    }
    return langMap[lang_code]->lang_name;
}
