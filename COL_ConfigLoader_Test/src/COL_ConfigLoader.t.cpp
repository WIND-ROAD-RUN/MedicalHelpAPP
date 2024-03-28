#include "pch.h"
#include "COL_ConfigLoader.h"

namespace HiddenButNotExposed {
    namespace COL {

        namespace COL_CONFIG_LOADER {
             const static ConfigLoaderDatabaseAbstract ::String DEFAULT_PATH = R"(G:\project\code_place\vs_code_place\MedicalHelp\COL_ConfigLoader_Test\database\dataFile.xml)";

            TEST(INI_COM, FIRST_LAYER)
            {
                ConfigLoader* test =
                    ConfigLoader::getInstance();

                auto result = test->iniCom();

                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "初始化失败";

                result = test->clearData();
                result = test->desCom();

                delete test;
            }

            TEST(DES_COM, FIRST_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                auto result = test->iniCom();

                result = test->desCom();

                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "销毁内存准备工作失败";

                delete test;
            }

            TEST(ADD_CONFIG, FIRST_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                auto result = test->iniCom();

                result = test->addConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->addConfig("BBQ", "GOOD TASTE");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->addConfig("USA", "$$$$$");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->clearData();
                result = test->saveData();
                result = test->desCom();

                delete test;
            }

            TEST(ADD_CONFIG, SECOND_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                ConfigLoader::String s;

                auto result = test->iniCom();

                result = test->addConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->addConfig("CHN", "People");
                EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "同一个name可以添加不同的值";

                result = test->addConfig("", "ABBB");
                EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "可以向为空的name添加非空的值";

                result = test->addConfig("USA", "");
                EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "可以向非空的name添加为空的值";

                result = test->addConfig("", "");
                EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "可以向为空的name添加为空的值";

                result = test->searchConfig("CHN", s);
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";

                EXPECT_EQ(s, "THRIVE") << "未成功添加CHN的配置信息";

                result = test->clearData();
                result = test->saveData();

                result = test->desCom();

                delete test;
            }

            TEST(DEL_CONFIG, FIRST_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                ConfigLoader::String s;

                auto result = test->iniCom();

                result = test->addConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->searchConfig("CHN", s);
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";

                result = test->deleteConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "删除配置信息失败";
                result = test->saveData();


                result = test->searchConfig("CHN", s);
                EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "删除配置信息失败";

                result = test->clearData();
                result = test->saveData();

                result = test->desCom();

                delete test;

            }

            TEST(DEL_CONFIG, SECOND_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                ConfigLoader::String s;

                auto result = test->iniCom();

                result = test->addConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->searchConfig("CHN",s);

                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "查询配置信息失败";
                EXPECT_EQ(s, "THRIVE") << "查询配置信息错误";

                result = test->deleteConfig("chn", "THRIVE");
                EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "name错误可以异常删除配置信息";

                result = test->searchConfig("CHN", s);
                EXPECT_EQ(s, "THRIVE") << "配置信息错误";

                result = test->deleteConfig("CHN", "thrive");
                EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "value错误可以异常删除配置信息";
                
                result = test->searchConfig("CHN", s);
                EXPECT_EQ(s, "THRIVE") << "配置信息错误";

                result = test->deleteConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "删除配置信息失败";
                result = test->saveData();


                result = test->searchConfig("CHN", s);
                //EXPECT_NE(s, "THRIVE") << "配置信息未被成功删除";

                result = test->clearData();
                result = test->saveData();

                result = test->desCom();

                delete test;

            }

            TEST(CHANGE_CONFIG, FIRST_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                ConfigLoader::String s;

                auto result = test->iniCom();

                result = test->addConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->searchConfig("CHN", s);
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";
                EXPECT_EQ(s, "THRIVE")<<"搜索配置信息错误";

                result = test->changeConfig("CHN", "STRONGER");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "修改配置信息失败";
                result = test->saveData();


                result = test->searchConfig("CHN", s);
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";
                EXPECT_NE(s, "THRIVE") << "配置信息未被修改";
                EXPECT_EQ(s, "STRONGER") << "配置信息未被修改";

                result = test->clearData();
                result = test->saveData();

                result = test->desCom();

                delete test;
            }

            TEST(CHANGE_CONFIG, SECOND_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                ConfigLoader::String s1, s2;

                auto result = test->iniCom();

                result = test->addConfig("USA", "STRONG");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->searchConfig("USA", s1);
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";
                EXPECT_EQ(s1, "STRONG") << "搜索配置信息错误";

                result = test->changeConfig("UK", "STRONG");
                EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "错误根据value修改name的值";
                
                result = test->searchConfig("UK", s2);
                EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "根据value修改name的值错误实现";
                EXPECT_NE(s2, "STRONG") << "根据value修改name的值错误实现";

                result = test->changeConfig("USA", "RECESSION");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "修改配置信息失败";
                result = test->saveData();


                result = test->searchConfig("USA", s1);
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";
                EXPECT_EQ(s1, "RECESSION")<<"配置信息修改失败";
                EXPECT_NE(s1, "STRONG") << "USA的配置信息未被修改";

                result = test->changeConfig("USA", "");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "可以将name对应的值修改为空";
                result = test->saveData();


                result = test->searchConfig("USA", s1);
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";

                result = test->clearData();
                result = test->saveData();

                result = test->desCom();

                delete test;
            }

            TEST(SEARCH_CONFIG, FIRST_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                ConfigLoader::String s;

                auto result = test->iniCom();

                result = test->searchConfig("CHN", s);
                EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "请检查是否存在内存未清理的异常情况";
                
                result = test->addConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->searchConfig("CHN", s);
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";
                EXPECT_EQ(s, "THRIVE") << "搜索配置信息错误";

                result = test->clearData();
                result = test->saveData();

                result = test->desCom();

                delete test;
            }

            TEST(SEARCH_CONFIG, SECOND_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                ConfigLoader::String s1,s2;

                auto result = test->iniCom();

                result = test->addConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->searchConfig("CHN", s1);
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "查询配置信息失败";
                EXPECT_EQ(s1, "THRIVE")<<"搜索配置信息错误";

                result = test->searchConfig("chn", s2);
                EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "name错误可以查询到配置信息";
                
                result = test->searchConfig("", s2);
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "name为空可以查询到配置信息";

                result = test->deleteConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "删除配置信息失败";
                result = test->saveData();


                result = test->searchConfig("CHN", s2);
                EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "配置信息未被成功删除";

                result = test->clearData();
                result = test->saveData();

                result = test->desCom();

                delete test;
            }

            TEST(SAVE_DATA, FIRST_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                auto result = test->iniCom();

                result = test->saveData();
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "保存配置信息失败";

                result = test->clearData();
                result = test->saveData();

                result = test->desCom();

                delete test;
            }

            TEST(SAVE_DATA, SECOND_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                ConfigLoader::String s;

                auto result = test->iniCom();

                result = test->addConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->saveData();
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "保存配置信息失败";

                result = test->searchConfig("CHN", s);
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "查询配置信息失败";
                EXPECT_EQ(s, "THRIVE") << "配置信息未保存";

                result = test->clearData();
                result = test->saveData();

                result = test->desCom();

                delete test;
            }

            TEST(CLEAR_DATA, FIRST_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                auto result = test->iniCom();

                result = test->clearData();
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "清除文件中的配置信息失败";

                result = test->desCom();

                delete test;
            }

            TEST(CLEAR_DATA, SECOND_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                ConfigLoader::String s;

                auto result = test->iniCom();

                result = test->addConfig("CHN","THRIVE");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->searchConfig("CHN", s);
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";
                EXPECT_EQ(s, "THRIVE") << "配置信息错误";

                result = test->changeConfig("CHN", "STRONGER");
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "修改配置信息失败";

                result = test->saveData();
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "保存文件中的配置信息失败";

                result = test->searchConfig("CHN", s);
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";
                EXPECT_EQ(s, "STRONGER") << "配置信息错误";

                result = test->clearData();
                EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "清除文件中的配置信息失败";

                result = test->searchConfig("CHN", s);
                EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "文件中的配置信息未清空";

                result = test->clearData();
                result = test->saveData();

                result = test->desCom();

                delete test;
            }

            TEST(SYNTHESISE, FIRST_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                ConfigLoader::String s1, s2;

                auto result = test->iniCom();
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "初始化错误";

                result = test->addConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->addConfig("CHN", "STRONGER");
                EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "错误地为同一个name配置不同的value";

                result = test->addConfig("USA", "$$$$");
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->searchConfig("CHN", s1);
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "查询CHN的配置信息失败";
                EXPECT_EQ(s1,"THRIVE") << "查询的配置信息错误";

                result = test->searchConfig("USA", s2);
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "查询USA的配置信息失败";
                EXPECT_EQ(s2, "$$$$") << "查询的配置信息错误";

                result = test->changeConfig("CHN", "PEOPLE'S COUNTRY");
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "修改配置信息失败";
                result = test->saveData();


                result = test->searchConfig("CHN", s1);
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "查询配置信息失败";
                EXPECT_NE(s1, "THRIVE")<<"CHN的配置信息未被成功修改";

                result = test->deleteConfig("USA", "$$$");
                EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "value错误name正确可以删除配置信息";

                result = test->searchConfig("USA", s2);
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "查询USA的配置信息失败";
                EXPECT_EQ(s2, "$$$$") << "查询的配置信息错误";

                result = test->deleteConfig("USA", "$$$$");
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "删除USA的配置信息失败";
                result = test->saveData();


                result = test->searchConfig("USA", s2);
                EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "USA的配置信息未被成功删除";

                result = test->clearData();

                result = test->searchConfig("CHN", s1);
                EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "清空文件中的配置信息失败";

                result = test->searchConfig("USA", s2);
                EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "清空文件中的配置信息失败";
            
                result = test->clearData();
                result = test->saveData();

                result = test->desCom();

                delete test;
            }

            TEST(SYNTHESISE, SECOND_LAYER)
            {
                ConfigLoader* test = ConfigLoader::getInstance();

                ConfigLoader::String s1, s2,s3;

                auto result = test->iniCom();
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "初始化错误";

                result = test->addConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->searchConfig("CHN", s1);
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "查询CHN的配置信息失败";
                EXPECT_EQ(s1, "THRIVE") << "查询的配置信息错误";

                result = test->addConfig("chn", "THRIVE");
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "添加配置信息失败";
                result = test->saveData();


                result = test->searchConfig("chn", s2);
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "查询CHN的配置信息失败";
                EXPECT_EQ(s2, "THRIVE") << "查询的配置信息错误";

                result = test->changeConfig("CHN", "THRIVE");
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "修改配置信息为原值失败";

                result = test->changeConfig("chn", "STRONGER");
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "修改配置信息失败";
                result = test->saveData();


                result = test->searchConfig("CHN", s1);
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "查询CHN的配置信息失败";
                EXPECT_EQ(s1, "THRIVE") << "查询的配置信息错误";

                result = test->searchConfig("chn", s2);
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "查询CHN的配置信息失败";
                EXPECT_NE(s2, "THRIVE") << "查询的配置信息错误";

                result = test->deleteConfig("chn", "THRIVE");
                EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "chn的value错误可以删除对应配置信息";

                result = test->searchConfig("chn", s2);
                EXPECT_EQ(s2, "STRONGER") << "查询的配置信息错误";

                result = test->deleteConfig("CHN", "THRIVE");
                EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "删除CHN的配置信息失败";
                result = test->saveData();


                result = test->searchConfig("CHN", s1);
                EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "删除CHN的配置信息失败";

                result = test->clearData();
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "清空文件中的配置信息失败";

                result = test->saveData();

                result = test->searchConfig("chn", s2);
                EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "文件中的配置信息未被全部清空";

                result = test->addConfig("USA", "$$$$$");
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "添加配置信息失败";

                result = test->changeConfig("BBQ", "$$$$$");
                EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "未添加的配置信息也可被修改，文件是否清空异常";

                result = test->searchConfig("UK", s3);
                EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "未添加的配置信息也可被查询，文件是否清空异常";

                result = test->deleteConfig("USAA", "$$$$$");
                EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "name错误的配置信息可以被异常删除";

                result = test->searchConfig("USA", s3);
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "查询配置信息失败";
                EXPECT_EQ(s3, "$$$$$") << "查询到错误的配置信息";

                result = test->changeConfig("USA", "!@#$%");
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "修改配置信息失败";

                result = test->searchConfig("USA", s3);
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "查询配置信息失败";
                EXPECT_EQ(s3, "!@#$%") << "USA的配置信息未被成功修改";

                result = test->clearData();
                EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "清空文件中的配置信息失败";

                result = test->searchConfig("USA", s3);
                EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "清空文件中的配置信息失败";

                result = test->clearData();
                result = test->saveData();

                result = test->desCom();

                delete test;
            }
        }
    }
}