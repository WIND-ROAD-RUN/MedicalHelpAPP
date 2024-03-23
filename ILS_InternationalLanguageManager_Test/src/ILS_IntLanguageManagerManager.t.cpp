#include "pch.h"
#include "ILS_IntLanguageDataAbstract.h"

static const std::string DEFAULT_PATH = R"(.\database\dataFile.xml)";

namespace HiddenButNotExposed {
    namespace ILS {

        namespace ILS_INT_LANGUAGE_MANAGER_MANAGER {
            TEST(FIRST_CASE, INT_COM)
            {
                IntLanguageManagerManager* test =
                    IntLanguageManagerManager::getInstance(new IntLanguageDataXML(DEFAULT_PATH));

                auto result = test->iniCom();
				EXPECT_EQ(result, true) << "初始化失败";

				delete test;
            }
			TEST(FIRST_SHALLOW, DES_COM)
			{
				IntLanguageManagerManager* test =
					IntLanguageManagerManager::getInstance(new IntLanguageDataXML(DEFAULT_PATH));

				auto result = test->iniCom();
				result = test->desCom();

				EXPECT_EQ(result, true) << "未成功销毁";

				delete test;

			}

			TEST(FIRST_SHALLOW, SEARCH_STRING)
			{
				IntLanguageManagerManager* test =
					IntLanguageManagerManager::getInstance(new IntLanguageDataXML(DEFAULT_PATH));

				auto iniDesResult = test->iniCom();

				IntLanguageManagerManager::String s;
				auto CRUDResult = test->searchString("1", "CHN", s);

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "请检查是否存在内存未清理的异常情况";

				CRUDResult = test->storeString("1", "CHN", "CBD");

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";

				CRUDResult = test->searchString("1", "CHN", s);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "字符串搜索失败";

				CRUDResult = test->delString("1", "CHN");

				iniDesResult = test->clearData();


				iniDesResult = test->desCom();

				delete test;

			}

			TEST(FIRST_SHALLOW, STORE_STRING)
			{
				IntLanguageManagerManager* test =
					IntLanguageManagerManager::getInstance(new IntLanguageDataXML(DEFAULT_PATH));

				auto iniDesResult = test->iniCom();

				IntLanguageManagerManager::String s = "ABABAB";
				auto CRUDResult = test->storeString("1", "CHN", s);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";
				EXPECT_EQ(s, "ABABAB");

				CRUDResult = test->delString("1", "CHN");

				iniDesResult = test->clearData();

				iniDesResult = test->desCom();

				delete test;

			}

			TEST(FIRST_SHALLOW, DEL_STRING)
			{
				IntLanguageManagerManager* test =
					IntLanguageManagerManager::getInstance(new IntLanguageDataXML(DEFAULT_PATH));

				auto iniDesResult = test->iniCom();

				auto CRUDResult = test->delString("1", "CHN");

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未存储的字符串应当不能被删除";

				iniDesResult = test->clearData();

				iniDesResult = test->desCom();

				delete test;

			}

			TEST(FIRST_SHALLOW, GET_MAP1)
			{
				IntLanguageManagerManager* test =
					IntLanguageManagerManager::getInstance(new IntLanguageDataXML(DEFAULT_PATH));

				auto iniDesResult = test->iniCom();

				IntLanguageDataAbstract::IntLanMap* intLanMap = new IntLanguageDataAbstract::IntLanMap();
				auto CRUDResult = test->getMap(intLanMap);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将所有的国际化语言字符串存放到intLanMap失败";

				iniDesResult = test->clearData();

				iniDesResult = test->desCom();

				delete test;

			}


			TEST(FIRST_DEEP, SEARCH_STRING)
			{
				IntLanguageManagerManager* test =
					IntLanguageManagerManager::getInstance(new IntLanguageDataXML(DEFAULT_PATH));

				auto iniDesResult = test->iniCom();

				IntLanguageManagerManager::String  s, s1, s2;

				auto CRUDResult = test->searchString(" ", " ", s);

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "请查看id和language都为空是存储的字符串";

				CRUDResult = test->searchString("1", "CHN", s);

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "请检查是否存在未清空内存数据的异常情况";

				s = "BCD";
				CRUDResult = test->storeString("1", "CHN", s);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "存储字符串失败";

				CRUDResult = test->searchString("1", "CHN", s1);

				EXPECT_EQ(s, s1) << "查找字符串失败";

				CRUDResult = test->searchString("CHN", "1", s2);

				EXPECT_NE(s, s2) << "查找字符串错误";

				CRUDResult = test->searchString("2", "CHN", s2);

				EXPECT_NE(s, s2) << "查找字符串错误";

				CRUDResult = test->searchString("1", "chn", s2);

				EXPECT_NE(s, s2) << "查找字符串错误";

				CRUDResult = test->searchString("2", "chn", s2);

				EXPECT_NE(s, s2) << "查找字符串错误";

				CRUDResult = test->delString("1", "CHN");

				iniDesResult = test->clearData();

				iniDesResult = test->desCom();

				delete test;


			}

			TEST(FIRST_DEEP, STORE_STRING)
			{
				IntLanguageManagerManager* test =
					IntLanguageManagerManager::getInstance(new IntLanguageDataXML(DEFAULT_PATH));

				auto iniDesResult = test->iniCom();

				IntLanguageManagerManager::String s, s1;

				auto CRUDResult = test->searchString("1", "CHN", s);

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "请检查是否存在未清空内存的异常情况";

				s = "CBD";
				CRUDResult = test->storeString("1", "CHN", s);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";

				CRUDResult = test->searchString("1", "CHN", s1);

				EXPECT_EQ(s1, s) << "查找字符串失败或者存储字符串失败";
				//EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";

				CRUDResult = test->delString("1", "CHN");

				iniDesResult = test->clearData();

				iniDesResult = test->desCom();

				delete test;

			}

			TEST(FIRST_DEEP, DEL_STRING)
			{
				IntLanguageManagerManager* test =
					IntLanguageManagerManager::getInstance(new IntLanguageDataXML(DEFAULT_PATH));

				auto iniDesResult = test->iniCom();

				IntLanguageManagerManager::String s = "CBDA", s1, s2;
				auto CRUDResult = test->storeString("1", "CHN", s);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";

				CRUDResult = test->searchString("1", "CHN", s1);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串模块失败";

				EXPECT_EQ(s, s1) << "查找字符串失败";

				CRUDResult = test->delString("1", "CHN");

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中删除字符串失败";

				CRUDResult = test->searchString("1", "CHN", s2);

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "删除模块失败";
				EXPECT_NE(s, s2) << "字符串删除失败";

				iniDesResult = test->clearData();

				iniDesResult = test->desCom();

				delete test;

			}

			TEST(SECOND_DEEP, SEARCH_STRING)
			{
				IntLanguageManagerManager* test =
					IntLanguageManagerManager::getInstance(new IntLanguageDataXML(DEFAULT_PATH));

				auto iniDesResult = test->iniCom();

				IntLanguageManagerManager::String s, s1 = "CBD", s2 = "abbb";
				auto CRUDResult = test->searchString("1", "CHN", s);

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "请检查是否有未清空内存的异常情况";

				CRUDResult = test->storeString("1", "CHN", s1);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "字符串s1存储失败";

				CRUDResult = test->searchString("1", "CHN", s);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "字符串查找失败";

				EXPECT_EQ(s, s1) << "字符串查找错误";

				CRUDResult = test->searchString("1", " ", s);

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "可以通过提供的id和空的language查询字符串";

				CRUDResult = test->searchString(" ", "CHN", s);

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "可以通过空的ID与一个被提供的language查询字符串";

				CRUDResult = test->searchString("1", "CHN", s);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "字符串查找失败";

				EXPECT_EQ(s, s1) << "字符串被错误修改";

				CRUDResult = test->delString("1", "CHN");

				iniDesResult = test->clearData();

				iniDesResult = test->desCom();

				delete test;

			}

			TEST(SECOND_DEEP, STORE_STRING)
			{
				IntLanguageManagerManager* test =
					IntLanguageManagerManager::getInstance(new IntLanguageDataXML(DEFAULT_PATH));

				auto iniDesResult = test->iniCom();

				IntLanguageManagerManager::String s, s1 = "CBD", s2 = "abbb";
				auto CRUDResult = test->storeString("1", "CHN", s1);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "存储字符串s1失败";

				CRUDResult = test->searchString("1", "CHN", s);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查询字符串失败";
				EXPECT_EQ(s, s1) << "请检查是否查询的字符串有误";

				CRUDResult = test->storeString("1", "CHN", s2);

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "可以通过同一id和language存储不同字符串";

				CRUDResult = test->searchString("1", "CHN", s);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查询字符串失败";

				EXPECT_EQ(s, s1) << "请查看字符串是否被错误修改";

				CRUDResult = test->storeString(" ", " ", s1);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "不能为空id和language存入字符串";

				CRUDResult = test->delString("1", "CHN");

				iniDesResult = test->clearData();

				iniDesResult = test->desCom();

				delete test;

			}

			TEST(SECOND_DEEP, DEL_STRING)
			{
				IntLanguageManagerManager* test =
					IntLanguageManagerManager::getInstance(new IntLanguageDataXML(DEFAULT_PATH));

				auto iniDesResult  = test->iniCom();

				IntLanguageManagerManager::String s, s1 = "CBD", s2 = "abbb", s3;
				auto CRUDResult = test->storeString("1", "CHN", s1);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串s1存储到文件中失败";


				CRUDResult = test->searchString("1", "CHN", s);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串模块失败";
				EXPECT_EQ(s, s1) << "查找字符串失败";

				CRUDResult = test->delString("1", "CHN");

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中删除字符串失败";

				CRUDResult = test->searchString("1", "CHN", s3);

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "删除模块错误";

				CRUDResult = test->storeString("1", "CHN", s1);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串s1存储到文件中失败";

				CRUDResult = test->delString("CHN", "1");

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "id错误也可以删除字符串";

				CRUDResult = test->searchString("1", "CHN", s);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未找到对应字符串";

				CRUDResult = test->delString("1", "chn");

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "language错误也可以删除字符串";

				CRUDResult = test->delString("1", "CHN");

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中删除字符串失败";

				iniDesResult = test->clearData();

				iniDesResult = test->desCom();

				delete test;

			}

			TEST(DEEP, SOME)
			{
				IntLanguageManagerManager* test =
					IntLanguageManagerManager::getInstance(new IntLanguageDataXML(DEFAULT_PATH));

				auto iniDesResult = test->iniCom();

				IntLanguageManagerManager::String  s1 = "CBD", s2 = "abbb", s3, s4, s;

				auto CRUDResult = test->storeString("1", "CHN", s1);

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串s1存储到文件中失败";

				CRUDResult = test->searchString("1", "CHN", s3);

				EXPECT_EQ(s3, s1) << "查找字符串s1失败";

				CRUDResult = test->storeString("1", "CHN", s2);

				EXPECT_NE(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串s2存储到文件中失败";

				CRUDResult = test->searchString("1", "CHN", s4);

				EXPECT_EQ(s3, s4) << "对同一个id和language读入不同字符串可以实现";

				CRUDResult = test->delString("1", "CHN");

				EXPECT_EQ(CRUDResult, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中删除字符串失败";

				CRUDResult = test->searchString("1", "CHN", s);

				EXPECT_NE(s, s1) << "删除字符串失败";

				iniDesResult = test->clearData();

				iniDesResult = test->desCom();

				EXPECT_EQ(iniDesResult,true) << "销毁工作失败";

				delete test;
			}
            
        }

    }//package
}//company