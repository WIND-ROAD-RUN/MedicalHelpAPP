#ifndef ILS_INTLANGUAGEDATAXML_H_
#define ILS_INTLANGUAGEDATAXML_H_

#include"ILS_IntLanguageDataAbstract.h"

namespace pugi {
    class xml_document;
}

class IntLanguageDataXML
    :public IntLanguageDataAbstract {
public:
    IntLanguageDataXML(const String & filtPath);
    ~IntLanguageDataXML();
public:
    // ͨ通过IntLanguageDataAbstract 继承
    ErrorInfo iniCom() override;

    ErrorInfo desCom() override;

    ErrorInfo searchString(const String& id, const String& language, String& s)const override;

    ErrorInfo storeString(const String& id, const String& language, const String& s) override;

    ErrorInfo changeString(const String& id, const String& language, const String& s) override;

    ErrorInfo delString(const String& id, const String& language) override;

    ErrorInfo getMap(IntLanMap* intLanMap)const override;

    ErrorInfo getMap(const String& language, LanStringMap* lanStringMap)const override;

    ErrorInfo clearData() override;

private:
    pugi::xml_document* m_operatorDoc{nullptr};

    String m_filePath;

};


#endif // !ILS_INTLANGUAGEDATAXML_H_

