#include"pch.h"

const static IntLanguageDataAbstract::String 
DEFAULT_PATH = R"(.\database\dataFile.xml)";

namespace Test {

    class IntlanguageDataAbstractTest {
    private:
        IntLanguageDataAbstract* m_intLanguage{ nullptr };
    public:
        IntlanguageDataAbstractTest() {
            m_intLanguage = new IntLanguageDataXML(DEFAULT_PATH);
        }
        ~IntlanguageDataAbstractTest() { delete m_intLanguage; }
    public:
        IntLanguageDataAbstract* getTestObject() { return m_intLanguage; }

    };


    TEST(TEST,TEST1) {
        IntlanguageDataAbstractTest test;
        
        auto test1 = test.getTestObject();
        test1->iniCom();
        test1->storeString("1","Test","Hello");
        test1->desCom();

        EXPECT_EQ(1,1);
    }



}