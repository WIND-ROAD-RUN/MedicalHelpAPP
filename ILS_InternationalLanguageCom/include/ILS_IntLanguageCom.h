#ifndef ILS_INTLANGUAGECOM_H_
#define ILS_INTLANGUAGECOM_H_

#include"ILS_IntLanguageDataAbstract.h"

class IntLanguageCom {
public:
    using String = IntLanguageDataAbstract::String;

private:
    IntLanguageCom(IntLanguageDataAbstract * intLanguageDataAbstract) {}

private:
    static IntLanguageCom* m_instance;

public:
    ~IntLanguageCom() {}

    static IntLanguageCom*
        getInstance(IntLanguageDataAbstract* intLanguageDataAbstract) {
        if (!m_instance) {
            return new IntLanguageCom(intLanguageDataAbstract);
        }
    }

private:
    IntLanguageDataAbstract* m_intLanguageData{nullptr};

public:
    bool iniCom();

    bool desCom();

public:
    IntLanguageDataAbstract::ErrorInfo searchString(const String& id,const String& language,String & s );

};


#endif // !ILS_INTLANGUAGECOM_H_
