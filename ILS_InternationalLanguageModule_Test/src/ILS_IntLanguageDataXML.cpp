#include"pch.h"

#include"IntLanguageDataAbstractTest.h"

namespace Test {

    TEST(TEST,TEST1) {
        IntLanguageDataAbstractTest test;
        
        auto test1 = test.getTestObject();
        test1->iniCom();
        test1->storeString("1","Test","Hello");
        test1->desCom();

        EXPECT_EQ(1,1);
    }



}