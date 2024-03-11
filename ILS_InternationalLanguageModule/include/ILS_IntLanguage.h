#ifndef ILS_INTLANGUAGE_H_
#define ILS_INTLANGUAGE_H_

#include"ILS_IntLanguageDataAbstract.h"

class IntLanguage
    :public IntLanguageDataAbstract { 
private:
    IntLanguageDataAbstract* m_intLanData{nullptr};

private:
    IntLanMap* m_intLanMap{nullptr};

public:
    IntLanguage(IntLanguageDataAbstract * intLanguageData);

    ~IntLanguage();
public:
    void setLanguageData(IntLanguageDataAbstract* intLanData);

public:
    // 通过 IntLanguageDataAbstract 继承
    ErrorInfo iniCom() override;

    ErrorInfo desCom() override;

    ErrorInfo searchString(const String& id, const String& language, String& s) const override;

    ErrorInfo storeString(const String& id, const String& language, const String& s) override;

    ErrorInfo changeString(const String& id, const String& language, const String& s) override;

    ErrorInfo delString(const String& id, const String& language) override;

    ErrorInfo getMap(IntLanMap* intLanMap) const override;

    ErrorInfo getMap(const String& language, LanStringMap* lanStringMap) const override;

    ErrorInfo clearData() override;

};



#endif // !ILS_INTLANGUAGE_H_
