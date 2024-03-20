#include "pch.h"

#include "ILS_IntLanguageComTest.h"

namespace HiddenButNotExposed {
    namespace ILS {

        namespace ILS_INT_LANGUAGE_COM {
            TEST(INT_LAN_COM, INI_COM) {
                IntLanguageComTest testObject;
                auto test = testObject.getTestObject();

                auto result = test->iniCom();

                EXPECT_EQ(result, true) << "初始化失败";
            }

            TEST(INT_LAN_COM, DES_COM) {
                IntLanguageComTest testObject;
                auto test = testObject.getTestObject();

                auto result = test->iniCom();

                EXPECT_EQ(result, true) << "初始化失败";

                result = test->desCom();

                EXPECT_EQ(result, true) << "销毁内存数据失败";

            }

            TEST(INT_LAN_COM, SEARCH_STRING) {
                IntLanguageComTest testObject;
                auto test = testObject.getTestObject();

                auto result = test->iniCom();

                const IntLanguageCom::String s = "0";

                result = test->searchString("1", "2", s);

                EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "请查看是否内存未清空";
            }
        }

    }//package
}//company


//namespace HiddenButNotExposed {
//	namespace ILS {
//
//		namespace ILS_INT_LANGUAGE_COM {
//			TEST(INT_LAN_COM, INI_COM) {
//				IntLanguageCom* test;
//
//			}
//
//		}
//
//	}
//}