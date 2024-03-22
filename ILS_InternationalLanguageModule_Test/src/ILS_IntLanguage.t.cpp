#include"pch.h"
//
//#include"ILS_IntLanguage.h"
//#include"ILS_IntLanguageDataAbstractTest.h"
//
//namespace HiddenButNotExposed {
//	namespace ILS {
//
//		namespace INT_LANGUAGE {
//			TEST(FIRST_SHALLOW, INI_COM) {
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "初始化失败";
//				result = test->desCom();
//
//			}
//
//			TEST(FIRST_SHALLOW, DES_COM)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//				result = test->desCom();
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未成功销毁";
//
//
//			}
//
//			TEST(FIRST_SHALLOW, SEARCH_STRING)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::String s;
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "请检查是否存在内存未清理的异常情况";
//				//result = test->clearData();
//
//				result = test->desCom();
//
//
//			}
//
//			TEST(FIRST_SHALLOW, STORE_STRING)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::String s = "ABABAB";
//				result = test->storeString("1", "CHN", s);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";
//
//				result = test->desCom();
//
//
//			}
//
//			TEST(FIRST_SHALLOW, CHANGE_STRING)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::String s = "BCS";
//				result = test->changeString("1", "CHN", s);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中更改字符串失败";
//
//				result = test->desCom();
//
//
//			}
//
//			TEST(FIRST_SHALLOW, DEL_STRING)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				result = test->delString("1", "CHN");
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::DES_ERROR) << "不必删除不存在的字符串";
//
//				result = test->desCom();
//
//			}
//
//			TEST(FIRST_SHALLOW, GET_MAP1)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::IntLanMap* intLanMap = new IntLanguageDataAbstract::IntLanMap();
//				result = test->getMap(intLanMap);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将所有的国际化语言字符串存放到intLanMap失败";
//
//				result = test->desCom();
//
//			}
//
//			TEST(FIRST_SHALLOW, GET_MAP2)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				const IntLanguageDataAbstract::String& language = "CHN";
//				IntLanguageDataAbstract::LanStringMap* lanStringMap = new IntLanguageDataAbstract::LanStringMap();
//				result = test->getMap(language, lanStringMap);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将language的国际化语言字符串存放到intLanMap失败";
//
//				result = test->desCom();
//
//
//			}
//
//			TEST(FIRST_SHALLOW, CLEAR_DATA)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				result = test->clearData();
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清除所有数据失败";
//
//				result = test->desCom();
//
//
//			}
//
//
//			TEST(FIRST_DEEP, SEARCH_STRING)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::String  s, s1, s2;
//
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "请检查是否存在未清空内存数据的异常情况";
//
//				s = "BCD";
//				result = test->storeString("1", "CHN", s);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "存储字符串失败";
//
//				result = test->searchString("1", "CHN", s1);
//				//s1 = BCD
//				EXPECT_EQ(s, s1) << "查找字符串失败";
//				//EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串失败";
//
//				result = test->searchString("2", "CHN", s2);
//
//				EXPECT_NE(s, s2) << "查找字符串错误";
//				//EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串失败";
//
//
//				result = test->searchString("1", "chn", s2);
//
//				EXPECT_NE(s, s2) << "查找字符串错误";
//				//EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串失败";
//
//
//				result = test->searchString("2", "chn", s2);
//
//				EXPECT_NE(s, s2) << "查找字符串错误";
//				//EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串失败";
//
//				result = test->clearData();
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清空所有数据失败";
//
//				result = test->searchString("1", "CHN", s2);
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清空数据有误或者内存错误";
//
//				result = test->desCom();
//
//			}
//
//			TEST(FIRST_DEEP, STORE_STRING)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::String s, s1;
//
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "请检查是否存在未清空内存的异常情况";
//
//				s = "CBD";
//				result = test->storeString("1", "CHN", s);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";
//
//				result = test->searchString("1", "CHN", s1);
//
//				EXPECT_EQ(s1, s) << "查找字符串失败或者存储字符串失败";
//				//EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";
//
//				result = test->clearData();
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未能清空内存所有数据";
//
//				result = test->desCom();
//
//
//			}
//
//
//			TEST(FIRST_DEEP, CHANGE_STRING)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::String s{ "CBD" }, s1, s2 = "abbb", s3;
//				result = test->storeString("1", "CHN", s);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";
//
//				result = test->searchString("1", "CHN", s1);
//				//s1 = cbd
//
//				EXPECT_EQ(s1, s) << "在文件中查找字符串失败";
//
//				result = test->changeString("1", "CHN", s2);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中更改字符串失败";
//
//				result = test->searchString("1", "CHN", s3);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中查找字符串失败";
//				EXPECT_EQ(s2, s3) << "字符串修改失败";
//
//				test->clearData();
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未能清空内存所有数据";
//
//				result = test->desCom();
//
//			}
//
//			TEST(FIRST_DEEP, DEL_STRING)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::String s = "CBDA", s1, s2;
//				result = test->storeString("1", "CHN", s);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";
//
//
//				result = test->searchString("1", "CHN", s1);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串模块失败";
//				EXPECT_EQ(s, s1) << "查找字符串失败";
//
//				result = test->delString("1", "CHN");
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中删除字符串失败";
//
//				result = test->searchString("1", "CHN", s2);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "删除模块失败";
//				EXPECT_NE(s, s2) << "字符串删除失败";
//
//				result = test->clearData();
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未能清空内存所有数据";
//
//				result = test->desCom();
//
//			}
//
//			/*TEST(FIRST_DEEP, GET_MAP1)
//			{
//				IntLanguageDataAbstract* test;
//				test = new IntLanguageDataXML();
//
//				IntLanguageDataAbstract::IntLanMap* intLanMap;
//				auto result = test->getMap(intLanMap);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将所有的国际化语言字符串存放到intLanMap失败";
//
//				IntLanguageDataAbstract::String& s{"000"};
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将所有的国际化语言字符串存放到intLanMap失败";
//
//			}
//
//			TEST(FIRST_DEEP, GET_MAP2)
//			{
//				IntLanguageDataAbstract* test;
//				test = new IntLanguageDataXML();
//
//				const IntLanguageDataAbstract::String& language = "CHN";
//				IntLanguageDataAbstract::LanStringMap* lanStringMap;
//				IntLanguageDataAbstract::String& s{"BCD"};
//				auto result = test->searchString("1",language, s);
//
//				result = test->getMap(language, lanStringMap);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将language的国际化语言字符串存放到intLanMap失败";
//			}*/
//
//			TEST(FIRST_DEEP, CLEAR_DATA)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::String s{ "abbb" }, s1, s2;
//				result = test->storeString("1", "CHN", s);
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "存储字符串失败";
//
//				result = test->searchString("1", "CHN", s1);
//				//s1 = abbb
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串失败";
//				EXPECT_EQ(s, s1) << "查找字符串失败";
//
//				result = test->clearData();
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清除所有数据失败";
//
//				result = test->searchString("1", "CHN", s2);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清除所有数据失败，任然能搜索相关字符串";
//				EXPECT_NE(s, s2) << "清除数据删除失败";
//
//				result = test->clearData();
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未能清空内存所有数据";
//
//				result = test->desCom();
//
//			}
//
//			TEST(SECOND_DEEP, SEARCH_STRING)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::String s, s1 = "CBD", s2 = "abbb";
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "请检查是否有未清空内存的异常情况";
//
//				result = test->storeString("1", "CHN", s1);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "字符串存储失败";
//
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "字符串查找失败";
//
//				EXPECT_EQ(s, s1) << "字符串查找错误";
//
//				result = test->searchString("1", " ", s);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "无法查询空的国家字符串";
//
//
//				result = test->searchString(" ", "CHN", s);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "空的ID查询失败";
//
//				//EXPECT_EQ(s, s1) << "请检查查找的字符串是否正确";
//
//				result = test->storeString("1", "CHN", s2);
//
//				//	//EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "字符串存储失败";
//
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "字符串查找失败";
//
//				EXPECT_EQ(s, s1) << "检索的字符串不是先存入的那个";
//
//				//	EXPECT_EQ(s, s2) << "检索的字符串是先存入的那个";
//
//				result = test->clearData();
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清空所有数据失败";
//
//				result = test->desCom();
//
//			}
//
//			TEST(SECOND_DEEP, STORE_STRING)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::String s, s1 = "CBD", s2 = "abbb";
//				result = test->storeString("1", "CHN", s1);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "存储字符串s1失败";
//
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查询字符串失败";
//				EXPECT_EQ(s, s1) << "请检查是否查询的字符串有误";
//
//				result = test->storeString("1", "CHN", s2);
//
//				//EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "存储字符串失败";
//
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查询字符串失败";
//
//				EXPECT_EQ(s, s1) << "存储id与language相同的字符串会覆盖原字符串";
//				//EXPECT_EQ(s, s2) << "按照存储的顺序返回同输入参数的字符串";
//
//				result = test->storeString(" ", " ", s1);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "不能为空id和language存入字符串";
//
//				result = test->clearData();
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清空所有数据失败";
//
//
//				result = test->desCom();
//
//			}
//
//
//			TEST(SECOND_DEEP, CHANGE_STRING)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::String s, s1{ "CBD" }, s2 = "abbb", s3;
//				result = test->storeString("1", "CHN", s1);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";
//
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_EQ(s1, s) << "在文件中查找字符串失败";
//
//				result = test->changeString("1", "CHN", s2);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "修改字符串失败";
//
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_NE(s1, s) << "修改字符串失败,仍然为原字符串";
//
//				EXPECT_EQ(s2, s) << "修改字符串失败，没有更新为所给字符串";
//
//				result = test->changeString("1", "chn", s2);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "没有对应的id和language是否可以修改字符串";
//
//				result = test->changeString(" ", " ", s2);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "没有对应的id和language是否可以修改字符串";
//
//				result = test->clearData();
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清空所有数据失败";
//
//				result = test->desCom();
//
//			}
//
//			TEST(SECOND_DEEP, DEL_STRING)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::String s, s1 = "CBD", s2 = "abbb", s3;
//				result = test->storeString("1", "CHN", s1);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";
//
//
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串模块失败";
//				EXPECT_EQ(s, s1) << "查找字符串失败";
//
//				result = test->delString("1", "CHN");
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中删除字符串失败";
//
//				result = test->searchString("1", "CHN", s3);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "删除模块错误";
//				EXPECT_NE(s, s3) << "字符串删除失败";
//
//				result = test->storeString("1", "CHN", s1);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串s1存储到文件中失败";
//
//				result = test->storeString("1", "CHN", s2);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串s2存储到文件中失败";
//
//				result = test->delString("1", "CHN");
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中删除字符串失败";
//
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未找到对应字符串";
//
//				//EXPECT_EQ(s, s1) << "删除的字符串是先存储的s1";
//
//				//EXPECT_EQ(s, s2) << "删除的字符串是后存储的s2";
//
//				result = test->clearData();
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未能清空内存所有数据";
//
//				result = test->desCom();
//
//			}
//
//			TEST(DEEP, SOME)
//			{
//				IntLanguageTest testObject;
//				auto test = testObject.getTestObject();
//
//				auto result = test->iniCom();
//
//				IntLanguageDataAbstract::String  s1 = "CBD", s2 = "abbb", s3, s4, s;
//
//				result = test->storeString("1", "CHN", s1);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串s1存储到文件中失败";
//
//				result = test->searchString("1", "CHN", s3);
//
//				EXPECT_EQ(s3, s1) << "查找字符串s1失败";
//
//				result = test->storeString("1", "CHN", s2);
//
//				//	//EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串s2存储到文件中失败";
//
//				result = test->searchString("1", "CHN", s4);
//
//				EXPECT_EQ(s3, s4) << "对同一个id和language读入不同字符串可以实现";
//
//				result = test->delString("1", "CHN");
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中删除字符串失败";
//
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_NE(s, s1) << "删除的是先存入的字符串";
//
//				//EXPECT_EQ(s, s2) << "删除的是后存入的字符串";
//
//				result = test->storeString("1", "CHN", s1);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串s1存储到文件中失败";
//
//				result = test->changeString("1", "CHN", "okkkk");
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中将字符串s1修改失败";
//
//				result = test->searchString("1", "CHN", s);
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中搜索字符串失败";
//
//				EXPECT_EQ(s, "okkkk") << "未成功修改字符串";
//
//				result = test->clearData();
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未能清空内存所有数据";
//
//				result = test->desCom();
//
//				EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "销毁工作失败";
//
//
//			}
//		}
//
//	}//package
//}//company
//
