#ifndef ILS_INTLANGUAGEDATAABSTRACTTEST_H_
#define ILS_INTLANGUAGEDATAABSTRACTTEST_H_

#include"pch.h"

namespace HiddenButNotExposed {
namespace ILS {
    class IntLanguageDataAbstractTest {
    private:
        IntLanguageDataAbstract* m_intLanguage{ nullptr };
    public:
        IntLanguageDataAbstractTest() {
            m_intLanguage = new IntLanguageDataXML(DEFAULT_PATH);
        }
        ~IntLanguageDataAbstractTest() { delete m_intLanguage; }
    public:
        IntLanguageDataAbstract* getTestObject() { return m_intLanguage; }

    };

}//package
}//company




#endif // !INTLANGUAGEDATAABSTRACTTEST_H_


