#ifndef ITS_INTLANGUAGEDATAXML_H_
#define ITS_INTLANGUAGEDATAXML_H_

#include"ITS_IntLanguageDataAbstract.h"

class IntLanguageDataXML 
    :public IntLanguageDataAbstract{

public:
    // ͨ通过IntLanguageDataAbstract 继承
    ErrorInfo iniCom() override;

    ErrorInfo desCom() override;

    ErrorInfo searchString(const String& id, const String& language, String& s )const override;

    ErrorInfo storeString(const String& id, const String& language, const String& s) override;

    ErrorInfo changeString(const String& id, const String& language, const String& s) override;

    ErrorInfo delString(const String& id, const String& language, const String& s) override;

    ErrorInfo getMap(IntLanMap* intLanMap )const override;

    ErrorInfo getMap(const String& language, LanStringMap* lanStringMap )const override;

    ErrorInfo clearData() override;

};


#endif // !ITS_INTLANGUAGEDATAXML_H_

