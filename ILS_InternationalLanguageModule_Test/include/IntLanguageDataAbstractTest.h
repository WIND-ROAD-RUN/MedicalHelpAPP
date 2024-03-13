#ifndef INTLANGUAGEDATAABSTRACTTEST_H_
#define INTLANGUAGEDATAABSTRACTTEST_H_

#include"pch.h"

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


#endif // !INTLANGUAGEDATAABSTRACTTEST_H_


