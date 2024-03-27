#ifndef ILS_INTLANGUAGEDATAABSTRACTTEST_H_
#define ILS_INTLANGUAGEDATAABSTRACTTEST_H_

#include"pch.h"

#include<ILS_IntLanguageDataXML.h>
#include<ILS_IntLanguage.h>

namespace HiddenButNotExposed {
namespace ILS {
    const static IntLanguageDataAbstract::String  DEFAULT_PATH = R"(D:\code\Repo\ILS_InternationalLanguageModule_Test\database\dataFile.xml)";

    class IntLanguageDataXMLTest {
    private:
        IntLanguageDataAbstract* m_intLanguage{ nullptr };
    public:
        IntLanguageDataXMLTest() {
            m_intLanguage = new IntLanguageDataXML(DEFAULT_PATH);
        }
        ~IntLanguageDataXMLTest() { delete m_intLanguage; }
    public:
        IntLanguageDataAbstract* getTestObject() { return m_intLanguage; }

    };

    class IntLanguageTest {
    private:
        IntLanguageDataAbstract* m_intLanguage{ nullptr };
    public:
        IntLanguageTest() {
            m_intLanguage = new IntLanguage_Database(new IntLanguageDataXML(DEFAULT_PATH));
        }
        ~IntLanguageTest() { delete m_intLanguage; }
    public:
        IntLanguageDataAbstract* getTestObject() { return m_intLanguage; }

    };



}//package
}//company




#endif // !INTLANGUAGEDATAABSTRACTTEST_H_


