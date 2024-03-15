#include"pch.h"

#include"ILS_IntLanguageDataAbstractTest.h"

namespace HiddenButNotExposed {
    namespace ILS {
        namespace Test {

            TEST(TEST, TEST1) {
                IntLanguageDataAbstractTest test;

                auto test1 = test.getTestObject();
                test1->iniCom();
                test1->storeString("1", "Test", "Hello");
                test1->desCom();

                EXPECT_EQ(1, 1);
            }



        }

    }//package
}//company

