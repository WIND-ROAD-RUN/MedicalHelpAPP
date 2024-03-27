# ConfigLoader模块测试代码编写



## ``ConfigLoader`` 接口

### iniCom()

~~~c++
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
~~~

测试用例编写一个断言判断在运行前进行初始化（加载、分配内存指针等）是否成功进行，期望返回信息为SUCCESS，否则表明初始化失败。

***



### desCom()

```c++
TEST(DES_COM, FIRST_LAYER)
{
    ConfigLoader* test = ConfigLoader::getInstance();

    auto result = test->iniCom();

    result = test->desCom();

    EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "销毁内存准备工作失败";

    delete test;
}
```

测试用例编写一个断言判断在销毁前进行销毁前的准备工作（销毁指针等）是否成功实现，若成功销毁则期望返回信息为UCCESS，否则表明销毁内存准备工作失败。

***



### addConfig(const String& name, const String& value)

+ #### 第一层测试

  ```c++
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
      result = test->desCom();
  
      delete test;
  }
  ```

  测试对创建的ConfigLoader类对象初始化之后，向文件中分别添加三个配置信息，期望能成功添加返回SUCCESS，否则说明添加配置信息失败，断言由返回的实际信息判别。

  

+ #### 第二层测试

  ```c++
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
      result = test->desCom();
  
      delete test;
  }
  ```

  测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加返回SUCCESS，否则说明添加配置信息失败。

  第二层测试在第一层的基础上测试能否通过同一个name向文件中添加不同的配置信息，期望返回值不是SUCCESS，否则说明同一个name可以添加不同的值，与需求相违背。

  测试套件中编写两个测试用例判断能否在name和value分别有一个为空和都为空的条件下向文件中添加配置信息，期望返回不是SUCCESS，否则说明可以向为空的name添加非空的值，不符合需求。

  第六第七个断言则是在添加配置信息成功的条件下进行的查找配置信息，期望查找的返回信息为SUCCESS，且查找的value存放s中，期望s的值与添加配置信息的值一致，否则说明搜索配置信息失败。

  

  ### deleteConfig(const String& name, const String& value) 

  + #### 第一层测试

    ```c++
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
    
        result = test->searchConfig("CHN", s);
        EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "删除配置信息失败";
    
        result = test->clearData();
        result = test->desCom();
    
        delete test;
    
    }
    ```

    测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加返回SUCCESS，否则说明添加配置信息失败。

    第二个断言是在添加配置信息成功后搜索该配置信息的值，期望返回值为SUCCESS，否则表明搜索配置信息失败。

    第三个断言则是删除已添加的配置信息，期望删除成功返回SUCCESS，否则表明删除配置信息失败。

    第四个断言是判断删除配置信息后能否查询到相关配置信息，期望返回值不是SUCCESS，若返回SUCCESS说明删除配置信息失败。

  + #### 第二层测试

    ```c++
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
    
        result = test->searchConfig("CHN", s);
        EXPECT_NE(s, "THRIVE") << "配置信息未被成功删除";
    
        result = test->clearData();
        result = test->desCom();
    
        delete test;
    
    }
    ```

    测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS。

    第二三个断言则是在添加配置信息之后对配置信息的搜索，期望搜索返回信息为SUCCESS，并且将查询到的结果存储到s中，期望s的值与添加的配置信息的值一致，否则说明查询配置信息失败或查询信息错误。

    第四个断言是判断能否在name错误value正确的条件下成功删除配置信息，期望返回值不是SUCCESS。

    第五个断言再次查询配置信息是否被删除或更改,期望未被修改，否则说明配置信息错误。

    第六第七断言则是判断在name正确value错误的条件下能否删除配置信息，期望返回值不是SUCCESS且搜索的配置信息未被删除或更改。

    第八个断言是在name和value都正确的条件下删除配置信息，期望成功删除返回SUCCESS，再次搜索配置信息查询结果与原来不一致，否则说明配置信息未被成功删除。

    ***

    ### changeConfig(const String& name, const String& value) 

    + 第一层测试

      ```c++
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
      
          result = test->searchConfig("CHN", s);
          EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";
          EXPECT_NE(s, "THRIVE") << "配置信息未被修改";
          EXPECT_EQ(s, "STRONGER") << "配置信息未被修改";
      
          result = test->clearData();
          result = test->desCom();
      
          delete test;
      }
      ```

      测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS。

      第二三个断言则是在添加配置信息之后对配置信息的搜索，期望搜索返回信息为SUCCESS，并且将查询到的结果存储到s中，期望s的值与添加的配置信息的值一致，否则说明查询配置信息失败或查询信息错误。

      第四个断言是将配置信息的值修改，期望修改成功并且返回SUCCESS，否则说明修改配置信息失败。

      第五个断言是修改后再次查询配置信息的值，期望查询的结果与原来的值不一致而与修改后的值一致，否则表明配置信息未被修改。

    + 第二层测试

      ```c++
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
      
           result = test->searchConfig("USA", s1);
           EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";
           EXPECT_EQ(s1, "RECESSION")<<"配置信息修改失败";
           EXPECT_NE(s1, "STRONG") << "USA的配置信息未被修改";
      
           result = test->changeConfig("USA", "");
           EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "可以将name对应的值修改为空";
      
           result = test->searchConfig("USA", s1);
           EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";
           EXPECT_EQ(s1, "RECESSION") << "配置信息修改失败";
      
           result = test->clearData();
           result = test->desCom();
      
           delete test;
       }
      ```

      测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS，否则说明添加配置信息失败。

      第二三个断言则是在添加配置信息之后对配置信息的搜索，期望搜索返回信息为SUCCESS，并且将查询到的结果存储到s中，期望s的值与添加的配置信息的值一致。

      第四个断言判断能否为未添加配置信息的配置器修改值，期望返回值不是SUCCESS。

      第五个断言是在修改未添加配置信息的配置器后，搜索该配置信息，期望搜索失败不返回SUCCESS。

      第五个断言是为正确的name修改配置信息，期望修改成功且返回信息为SUCCESS。

      第六个断言搜索修改过后的配置信息的值，期望搜索成功返回SUCCESS且查询到的配置信息存储于变量s中，期望s的值于原始配置信息不一致，与修改后的配置信息一致。

      接下来的断言判断能否将配置信息的值修改为空，期望不能修改为空，返回信息不是SUCCESS，编写断言测试。

      最后再次查询配置信息查看配置信息是否被修改，期望未被修改为空。

      ***

      ### searchConfig(const String& name, String& value)const

      + 第一层测试

        ```c++
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
            result = test->desCom();
        
            delete test;
        }
        ```

        测试对创建的ConfigLoader类对象初始化之后,第一个断言判断能否在未添加配置信息的条件下查询到配置信息，期望查询失败，返回值不是SUCCESS，否则存在内存未清空的异常情况。

        第二层断言是向文件中添加配置信息，期望添加成功返回SUCCESS，否则说明添加配置信息失败。

        第三层断言是查询添加的配置信息的值，期望查询成功返回SUCCESS，并且查询的结果存放于变量s中，期望s的值与添加的配置信息的值一致，否则说明搜索配置信息失败或搜索的信息错误。

      + 第二层测试

        ```c++
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
        
             result = test->searchConfig("CHN", s2);
             EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "配置信息未被成功删除";
        
             result = test->clearData();
             result = test->desCom();
        
             delete test;
         }
        ```

        测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS。

        第二个断言查询添加的配置信息的值，期望查询成功并且返回值SUCCESS,查询到的结果存放于变量s中，期望s的值与添加值配置信息的值一致。

        第四个断言判断能否在name错误的条件下查询到配置信息的值，期望查询失败返回值不是SUCCESS，否则说明name错误可以查询到配置信息，不符合需求。

        第五个断言判断能否在name为空的条件下查询到配置信息的值，期望查询失败返回值不是SUCCESS，否则说明name为空可以查询到配置信息，不符合需求。

        第六个断言是删除配置信息，期望删除成功且返回的值为SUCCESS，否则说明删除配置信息失败。

        第七个断言是删除配置信息后再次查询配置信息，期望查询不到配置信息，返回结果不是SUCCESS。

        ***

        ### clearData()

        + 第一层测试

          ```c++
          TEST(CLEAR_DATA, FIRST_LAYER)
          {
              ConfigLoader* test = ConfigLoader::getInstance();
          
              auto result = test->iniCom();
          
              result = test->clearData();
              EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "清除文件中的配置信息失败";
          
              result = test->desCom();
          
              delete test;
          }
          ```

          测试对创建的ConfigLoader类对象初始化之后，即清除文件中的配置信息，期望清除成功，返回值为SUCCESS。

        + 第二层测试

          ```c++
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
               result = test->desCom();
          
               delete test;
           }
          ```

          测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS。

          第二个断言是判断能否查询到已添加的配置信息，期望查询成功返回信息为SUCCESS且查询的结果存放于s中，s的值与添加的配置信息的值一致。

          第四个断言判断能否将已添加的配置信息值修改，期望修改成功返回信息为SUCCESS，否则说明修改配置信息失败。

          第五个断言判断对文件的修改能否成功保存，期望成功保存返回信息为SUCCESS。

          第六个断言搜索配置信息，期望搜索成功返回SUCCESS，第七个断言判断查询的结果与修改过后的值是否一致，期望是一致的，否则说明搜索配置信息失败或搜索的信息错误。

          第八个断言判断文件是否能被成功清空，期望清理成功返回信息SUCCESS，否则说明清除文件中的配置信息失败。

          第九个断言判断清空文件后能否再次查询到配置信息，期望查询失败返回值不是SUCCESS，否则说明文件中的配置信息未清空。

          ***

          ### 综合测试

          ```c++
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
          
               result = test->searchConfig("USA", s2);
               EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "USA的配置信息未被成功删除";
               EXPECT_NE(s2, "$$$$") << "USA的配置信息未被成功删除";
          
               result = test->clearData();
          
               result = test->searchConfig("CHN", s1);
               EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "清空文件中的配置信息失败";
          
               result = test->searchConfig("USA", s2);
               EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "清空文件中的配置信息失败";
           
               result = test->clearData();
               result = test->desCom();
          
               delete test;
           }
          ```

          测试对创建的ConfigLoader类对象初始化，期望初始化成功返回SUCCESS。

          第二个断言判断能否成功向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS。

          第三个断言判断能否为向文件中为同一个name的装载器配置不同的配置信息，期望不能添加成功，返回信息不是SUCCESS。

          第四个断言判断能否再次向文件中添加不同的配置信息，期望添加成功返回信息SUCCESS。

          第五六七八个断言则是分别查询添加的配置信息，期望查询成功返回SUCCESS，并且期望查询的结果与添加配置时的信息一致。

          第九个断言修改配置信息，期望成功修改并返回信息为SUCCESS。

          第十和十一个断言是搜索修改后的配置信息，期望查询成功并且返回结果为SUCCESS，期望查询的结果不是修改之前的配置信息。

          第十二个断言判断能否在name正确value错误的条件下删除配置信息，期望删除失败，返回信息不是SUCCESS。

          第十三个断言再次查询配置信息，期望查询成功返回信息为SUCCESS，且期望查询的结果与预期一致。

          第十五个断言判断是否成功删除了配置信息，期望删除成功，返回信息为SUCCESS。

          第十六个断言查询已被删除的配置信息，期望查询失败，返回信息不是SUCCESS，查询结果也不是添加配置信息的结果。

          接下来执行清空文件配置信息的操作。

          第十八第十九个断言分别查询文件中的配置信息，期望查询失败，返回结果不是SUCCESS。

          ```c++
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
          
              result = test->searchConfig("chn", s2);
              EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "查询CHN的配置信息失败";
              EXPECT_EQ(s2, "THRIVE") << "查询的配置信息错误";
          
              result = test->changeConfig("CHN", "THRIVE");
              EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "修改配置信息为原值失败";
          
              result = test->changeConfig("chn", "STRONGER");
              EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "修改配置信息失败";
          
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
          
              result = test->searchConfig("CHN", s1);
              EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "删除CHN的配置信息失败";
          
              result = test->clearData();
              EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "清空文件中的配置信息失败";
          
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
              EXPECT_NE(s3, "!@#$%") << "文件中的配置信息未被全部清除";
          
              result = test->clearData();
              result = test->desCom();
          
              delete test;
          }
          ```

          测试对创建的ConfigLoader类对象初始化，期望初始化成功返回SUCCESS。

          第二个断言判断能否成功向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS。

          第三四个断言则是分别查询添加的配置信息，期望查询成功返回SUCCESS，并且期望查询的结果与添加配置时的信息一致。

          第五个断言判断为两个不同name的装载器配置相同的value能否实现，期望可以成功添加，返回信息为SUCCESS。

          第六第七个断言实现查询添加的配置信息，期望查询成功返回SUCCESS，并且期望查询的结果与第二个添加的配置信息一致。

          第八个断言判断将配置信息修改为和自己相同的值能否实现，期望可以修改且返回信息为SUCCESS。

          第九个断言判断修改配置信息能否正确执行，期望修改成功并且返回信息是SUCCESS。

          第十十一、十二十三个断言则是分别查询添加的配置信息，期望查询成功返回SUCCESS，并且期望查询的结果与添加配置时的信息一致。

          第十四个断言判断在name正确value错误时能否成功删除配置信息，期望不能成功删除，返回信息不是SUCCESS。

          第十五个断言是再次对上一个装载器的配置信息查询，期望查询成功并且查询到的配置信息是经过一次修改后的期望值。

          第十六个断言判断删除文件中的配置信息能否实现，期望删除成功且返回SUCCESS。

          第十七个断言则是对删除的配置信息进行查询，期望查询失败，返回值不是SUCCESS。

          接下来对文件实行清空操作，期望文件清空成功且返回信息为SUCCESS。

          第十八个断言在清空文件后判断能否查询到配置信息，期望查询失败，返回信息不是SUCCESS。

          第十九个断言判断清空文件后能否再次向文件中添加配置信息，期望添加成功，返回信息SUCCESS。

          第二十个断言判断能否在文件中修改未添加配置信息的装载器，期望修改失败，返回信息不是SUCCESS。

          第二十一个断言判断能否在文件中查询未添加的配置信息，期望查询失败，返回信息不是SUCCESS。

          第二十二个断言判断在name错误但value正确的条件下能否成功删除配置信息，期望删除失败，返回信息不是SUCCESS。

          第二十三个断言判断能否在文件中查询到添加的配置信息，期望查询成功且返回信息是SUCCESS。

          第二十四个断言判断查询到的配置信息是否正确，期望查询的配置信息在未被修改时与添加时的信息一致。

          第二十五个断言判断在文件中修改配置信息能否成功实现，期望可以成功修改返回信息SUCCESS。

          第二十六个断言查询修改后的配置信息，期望查询成功，返回信息为SUCCESS，第二十七个断言判断查询到的配置信息是否与修改后的配置信息一致，期望是一致的，否则说明配置信息未被成功修改。

          第二十八个断言判断再次将文件清空是否成功实现，期望能成功清空，返回信息是SUCCESS，否则说明清空文件中的配置信息失败。

          第二十九个断言判断清空文件后能否查询到相关配置信息，期望查询失败，返回信息不是SUCCESS，否则说明清空文件中的配置信息失败。

          第三十个断言则是期望查询的结果为空而不是添加配置信息时的值，期望不相等，否则说明件中的配置信息未被全部清除。

          

    



***



# COL_ConfigLoaderDatabaseXML测试文档



## ``COL_ConfigLoaderDatabaseXML``XML测试实现的类

```c++
namespace HiddenButNotExposed {
	namespace COL {
		const static ConfigLoaderDatabaseAbstract::String DEFAULT_PATH 
            = R"(D:\code\Repo\COL_ConfigLoader_Test\database\dataFile.xml)";
	
		class ConfigLoaderDatabaseXMLTest {
		private:
			ConfigLoaderDatabaseAbstract* m_intconfigloader{ nullptr };
		public:
			ConfigLoaderDatabaseXMLTest()
			{
				m_intconfigloader = new ConfigLoaderDatabaseXML(DEFAULT_PATH);
			}

			~ConfigLoaderDatabaseXMLTest()
			{
				delete m_intconfigloader;
			}

		public:
			ConfigLoaderDatabaseAbstract* getTestObject()
			{
				return m_intconfigloader;
			}
		};
	}
}
```

在命名空间HiddenButNotExposed::COL中定义database的绝对路径，并用抽象基类 ConfigLoaderDatabaseAbstract中封装的String类型的变量存储此文件路径。

## ``ConfigLoaderDatabaseDataXML`` 接口测试

### iniCom()

~~~c++
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
~~~

测试用例编写一个断言判断在运行前进行初始化（加载、分配内存指针等）是否成功进行，期望返回信息为SUCCESS，否则表明初始化失败。

***



### desCom()

```c++
TEST(DES_COM, FIRST_LAYER)
{
    ConfigLoader* test = ConfigLoader::getInstance();

    auto result = test->iniCom();

    result = test->desCom();

    EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "销毁内存准备工作失败";

    delete test;
}
```

测试用例编写一个断言判断在销毁前进行销毁前的准备工作（销毁指针等）是否成功实现，若成功销毁则期望返回信息为UCCESS，否则表明销毁内存准备工作失败。

***



### addConfig(const String& name, const String& value)

+ #### 第一层测试

  ```c++
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
      result = test->desCom();
  
      delete test;
  }
  ```

  测试对创建的ConfigLoader类对象初始化之后，向文件中分别添加三个配置信息，期望能成功添加返回SUCCESS，否则说明添加配置信息失败，断言由返回的实际信息判别。

  

+ #### 第二层测试

  ```c++
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
      result = test->desCom();
  
      delete test;
  }
  ```

  测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加返回SUCCESS，否则说明添加配置信息失败。

  第二层测试在第一层的基础上测试能否通过同一个name向文件中添加不同的配置信息，期望返回值不是SUCCESS，否则说明同一个name可以添加不同的值，与需求相违背。

  测试套件中编写两个测试用例判断能否在name和value分别有一个为空和都为空的条件下向文件中添加配置信息，期望返回不是SUCCESS，否则说明可以向为空的name添加非空的值，不符合需求。

  第六第七个断言则是在添加配置信息成功的条件下进行的查找配置信息，期望查找的返回信息为SUCCESS，且查找的value存放s中，期望s的值与添加配置信息的值一致，否则说明搜索配置信息失败。

  ***

  ### deleteConfig(const String& name, const String& value) 

  + #### 第一层测试

    ```c++
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
    
        result = test->searchConfig("CHN", s);
        EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "删除配置信息失败";
    
        result = test->clearData();
        result = test->desCom();
    
        delete test;
    
    }
    ```

    测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加返回SUCCESS，否则说明添加配置信息失败。

    第二个断言是在添加配置信息成功后搜索该配置信息的值，期望返回值为SUCCESS，否则表明搜索配置信息失败。

    第三个断言则是删除已添加的配置信息，期望删除成功返回SUCCESS，否则表明删除配置信息失败。

    第四个断言是判断删除配置信息后能否查询到相关配置信息，期望返回值不是SUCCESS，若返回SUCCESS说明删除配置信息失败。

  + #### 第二层测试

    ```c++
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
    
        result = test->searchConfig("CHN", s);
        EXPECT_NE(s, "THRIVE") << "配置信息未被成功删除";
    
        result = test->clearData();
        result = test->desCom();
    
        delete test;
    
    }
    ```

    测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS。

    第二三个断言则是在添加配置信息之后对配置信息的搜索，期望搜索返回信息为SUCCESS，并且将查询到的结果存储到s中，期望s的值与添加的配置信息的值一致，否则说明查询配置信息失败或查询信息错误。

    第四个断言是判断能否在name错误value正确的条件下成功删除配置信息，期望返回值不是SUCCESS。

    第五个断言再次查询配置信息是否被删除或更改,期望未被修改，否则说明配置信息错误。

    第六第七断言则是判断在name正确value错误的条件下能否删除配置信息，期望返回值不是SUCCESS且搜索的配置信息未被删除或更改。

    第八个断言是在name和value都正确的条件下删除配置信息，期望成功删除返回SUCCESS，再次搜索配置信息查询结果与原来不一致，否则说明配置信息未被成功删除。

    ***

    ### changeConfig(const String& name, const String& value) 

    + 第一层测试

      ```c++
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
      
          result = test->searchConfig("CHN", s);
          EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";
          EXPECT_NE(s, "THRIVE") << "配置信息未被修改";
          EXPECT_EQ(s, "STRONGER") << "配置信息未被修改";
      
          result = test->clearData();
          result = test->desCom();
      
          delete test;
      }
      ```

      测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS。

      第二三个断言则是在添加配置信息之后对配置信息的搜索，期望搜索返回信息为SUCCESS，并且将查询到的结果存储到s中，期望s的值与添加的配置信息的值一致，否则说明查询配置信息失败或查询信息错误。

      第四个断言是将配置信息的值修改，期望修改成功并且返回SUCCESS，否则说明修改配置信息失败。

      第五个断言是修改后再次查询配置信息的值，期望查询的结果与原来的值不一致而与修改后的值一致，否则表明配置信息未被修改。

    + 第二层测试

      ```c++
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
      
           result = test->searchConfig("USA", s1);
           EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";
           EXPECT_EQ(s1, "RECESSION")<<"配置信息修改失败";
           EXPECT_NE(s1, "STRONG") << "USA的配置信息未被修改";
      
           result = test->changeConfig("USA", "");
           EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "可以将name对应的值修改为空";
      
           result = test->searchConfig("USA", s1);
           EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "搜索配置信息失败";
           EXPECT_EQ(s1, "RECESSION") << "配置信息修改失败";
      
           result = test->clearData();
           result = test->desCom();
      
           delete test;
       }
      ```

      测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS，否则说明添加配置信息失败。

      第二三个断言则是在添加配置信息之后对配置信息的搜索，期望搜索返回信息为SUCCESS，并且将查询到的结果存储到s中，期望s的值与添加的配置信息的值一致。

      第四个断言判断能否为未添加配置信息的配置器修改值，期望返回值不是SUCCESS。

      第五个断言是在修改未添加配置信息的配置器后，搜索该配置信息，期望搜索失败不返回SUCCESS。

      第五个断言是为正确的name修改配置信息，期望修改成功且返回信息为SUCCESS。

      第六个断言搜索修改过后的配置信息的值，期望搜索成功返回SUCCESS且查询到的配置信息存储于变量s中，期望s的值于原始配置信息不一致，与修改后的配置信息一致。

      接下来的断言判断能否将配置信息的值修改为空，期望不能修改为空，返回信息不是SUCCESS，编写断言测试。

      最后再次查询配置信息查看配置信息是否被修改，期望未被修改为空。

      ***

      ### searchConfig(const String& name, String& value)const

      + 第一层测试

        ```c++
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
            result = test->desCom();
        
            delete test;
        }
        ```

        测试对创建的ConfigLoader类对象初始化之后,第一个断言判断能否在未添加配置信息的条件下查询到配置信息，期望查询失败，返回值不是SUCCESS，否则存在内存未清空的异常情况。

        第二层断言是向文件中添加配置信息，期望添加成功返回SUCCESS，否则说明添加配置信息失败。

        第三层断言是查询添加的配置信息的值，期望查询成功返回SUCCESS，并且查询的结果存放于变量s中，期望s的值与添加的配置信息的值一致，否则说明搜索配置信息失败或搜索的信息错误。

      + 第二层测试

        ```c++
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
        
             result = test->searchConfig("CHN", s2);
             EXPECT_NE(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "配置信息未被成功删除";
        
             result = test->clearData();
             result = test->desCom();
        
             delete test;
         }
        ```

        测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS。

        第二个断言查询添加的配置信息的值，期望查询成功并且返回值SUCCESS,查询到的结果存放于变量s中，期望s的值与添加值配置信息的值一致。

        第四个断言判断能否在name错误的条件下查询到配置信息的值，期望查询失败返回值不是SUCCESS，否则说明name错误可以查询到配置信息，不符合需求。

        第五个断言判断能否在name为空的条件下查询到配置信息的值，期望查询失败返回值不是SUCCESS，否则说明name为空可以查询到配置信息，不符合需求。

        第六个断言是删除配置信息，期望删除成功且返回的值为SUCCESS，否则说明删除配置信息失败。

        第七个断言是删除配置信息后再次查询配置信息，期望查询不到配置信息，返回结果不是SUCCESS。

        ***

        ### getConfigMap(ConfigMap* map)

        ```c++
         TEST(GET_CONFIG_MAP, FIRST_LAYER)
         {
             ConfigLoaderDatabaseXMLTest testObject;
             auto test = testObject.getTestObject();
        
             auto result = test->iniCom();
        
             ConfigLoaderDatabaseAbstract::ConfigMap* configMap = new ConfigLoaderDatabaseAbstract::ConfigMap();
        
             result = test->getConfigMap(configMap);
             EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "获取文件中所有配置信息失败";
        
             result = test->desCom();
         }
        ```

        测试对创建的ConfigLoader类对象初始化之后，获取内存中的所有配置信息，期望返回SUCCESS，否则说明获取文件中的配置信息失败。

        ### clearData()

        + 第一层测试

          ```c++
          TEST(CLEAR_DATA, FIRST_LAYER)
          {
              ConfigLoader* test = ConfigLoader::getInstance();
          
              auto result = test->iniCom();
          
              result = test->clearData();
              EXPECT_EQ(result, ConfigLoaderDataUtility::ErrorInfo::SUCCESS) << "清除文件中的配置信息失败";
          
              result = test->desCom();
          
              delete test;
          }
          ```

          测试对创建的ConfigLoader类对象初始化之后，即清除文件中的配置信息，期望清除成功，返回值为SUCCESS。

        + 第二层测试

          ```c++
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
               result = test->desCom();
          
               delete test;
           }
          ```

          测试对创建的ConfigLoader类对象初始化之后，向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS。

          第二个断言是判断能否查询到已添加的配置信息，期望查询成功返回信息为SUCCESS且查询的结果存放于s中，s的值与添加的配置信息的值一致。

          第四个断言判断能否将已添加的配置信息值修改，期望修改成功返回信息为SUCCESS，否则说明修改配置信息失败。

          第五个断言判断对文件的修改能否成功保存，期望成功保存返回信息为SUCCESS。

          第六个断言搜索配置信息，期望搜索成功返回SUCCESS，第七个断言判断查询的结果与修改过后的值是否一致，期望是一致的，否则说明搜索配置信息失败或搜索的信息错误。

          第八个断言判断文件是否能被成功清空，期望清理成功返回信息SUCCESS，否则说明清除文件中的配置信息失败。

          第九个断言判断清空文件后能否再次查询到配置信息，期望查询失败返回值不是SUCCESS，否则说明文件中的配置信息未清空。

          ***

          ### 综合测试

          ```c++
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
          
               result = test->searchConfig("USA", s2);
               EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "USA的配置信息未被成功删除";
               EXPECT_NE(s2, "$$$$") << "USA的配置信息未被成功删除";
          
               result = test->clearData();
          
               result = test->searchConfig("CHN", s1);
               EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "清空文件中的配置信息失败";
          
               result = test->searchConfig("USA", s2);
               EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "清空文件中的配置信息失败";
           
               result = test->clearData();
               result = test->desCom();
          
               delete test;
           }
          ```

          测试对创建的ConfigLoader类对象初始化，期望初始化成功返回SUCCESS。

          第二个断言判断能否成功向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS。

          第三个断言判断能否为向文件中为同一个name的装载器配置不同的配置信息，期望不能添加成功，返回信息不是SUCCESS。

          第四个断言判断能否再次向文件中添加不同的配置信息，期望添加成功返回信息SUCCESS。

          第五六七八个断言则是分别查询添加的配置信息，期望查询成功返回SUCCESS，并且期望查询的结果与添加配置时的信息一致。

          第九个断言修改配置信息，期望成功修改并返回信息为SUCCESS。

          第十和十一个断言是搜索修改后的配置信息，期望查询成功并且返回结果为SUCCESS，期望查询的结果不是修改之前的配置信息。

          第十二个断言判断能否在name正确value错误的条件下删除配置信息，期望删除失败，返回信息不是SUCCESS。

          第十三个断言再次查询配置信息，期望查询成功返回信息为SUCCESS，且期望查询的结果与预期一致。

          第十五个断言判断是否成功删除了配置信息，期望删除成功，返回信息为SUCCESS。

          第十六个断言查询已被删除的配置信息，期望查询失败，返回信息不是SUCCESS，查询结果也不是添加配置信息的结果。

          接下来执行清空文件配置信息的操作。

          第十八第十九个断言分别查询文件中的配置信息，期望查询失败，返回结果不是SUCCESS。

          ```c++
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
          
              result = test->searchConfig("chn", s2);
              EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "查询CHN的配置信息失败";
              EXPECT_EQ(s2, "THRIVE") << "查询的配置信息错误";
          
              result = test->changeConfig("CHN", "THRIVE");
              EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "修改配置信息为原值失败";
          
              result = test->changeConfig("chn", "STRONGER");
              EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "修改配置信息失败";
          
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
          
              result = test->searchConfig("CHN", s1);
              EXPECT_NE(result, ConfigLoader::ErrorInfo::SUCCESS) << "删除CHN的配置信息失败";
          
              result = test->clearData();
              EXPECT_EQ(result, ConfigLoader::ErrorInfo::SUCCESS) << "清空文件中的配置信息失败";
          
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
              EXPECT_NE(s3, "!@#$%") << "文件中的配置信息未被全部清除";
          
              result = test->clearData();
              result = test->desCom();
          
              delete test;
          }
          ```

          测试对创建的ConfigLoader类对象初始化，期望初始化成功返回SUCCESS。

          第二个断言判断能否成功向文件中添加一个配置信息，期望能成功添加并返回值SUCCESS。

          第三四个断言则是分别查询添加的配置信息，期望查询成功返回SUCCESS，并且期望查询的结果与添加配置时的信息一致。

          第五个断言判断为两个不同name的装载器配置相同的value能否实现，期望可以成功添加，返回信息为SUCCESS。

          第六第七个断言实现查询添加的配置信息，期望查询成功返回SUCCESS，并且期望查询的结果与第二个添加的配置信息一致。

          第八个断言判断将配置信息修改为和自己相同的值能否实现，期望可以修改且返回信息为SUCCESS。

          第九个断言判断修改配置信息能否正确执行，期望修改成功并且返回信息是SUCCESS。

          第十十一、十二十三个断言则是分别查询添加的配置信息，期望查询成功返回SUCCESS，并且期望查询的结果与添加配置时的信息一致。

          第十四个断言判断在name正确value错误时能否成功删除配置信息，期望不能成功删除，返回信息不是SUCCESS。

          第十五个断言是再次对上一个装载器的配置信息查询，期望查询成功并且查询到的配置信息是经过一次修改后的期望值。

          第十六个断言判断删除文件中的配置信息能否实现，期望删除成功且返回SUCCESS。

          第十七个断言则是对删除的配置信息进行查询，期望查询失败，返回值不是SUCCESS。

          接下来对文件实行清空操作，期望文件清空成功且返回信息为SUCCESS。

          第十八个断言在清空文件后判断能否查询到配置信息，期望查询失败，返回信息不是SUCCESS。

          第十九个断言判断清空文件后能否再次向文件中添加配置信息，期望添加成功，返回信息SUCCESS。

          第二十个断言判断能否在文件中修改未添加配置信息的装载器，期望修改失败，返回信息不是SUCCESS。

          第二十一个断言判断能否在文件中查询未添加的配置信息，期望查询失败，返回信息不是SUCCESS。

          第二十二个断言判断在name错误但value正确的条件下能否成功删除配置信息，期望删除失败，返回信息不是SUCCESS。

          第二十三个断言判断能否在文件中查询到添加的配置信息，期望查询成功且返回信息是SUCCESS。

          第二十四个断言判断查询到的配置信息是否正确，期望查询的配置信息在未被修改时与添加时的信息一致。

          第二十五个断言判断在文件中修改配置信息能否成功实现，期望可以成功修改返回信息SUCCESS。

          第二十六个断言查询修改后的配置信息，期望查询成功，返回信息为SUCCESS，第二十七个断言判断查询到的配置信息是否与修改后的配置信息一致，期望是一致的，否则说明配置信息未被成功修改。

          第二十八个断言判断再次将文件清空是否成功实现，期望能成功清空，返回信息是SUCCESS，否则说明清空文件中的配置信息失败。

          第二十九个断言判断清空文件后能否查询到相关配置信息，期望查询失败，返回信息不是SUCCESS，否则说明清空文件中的配置信息失败。

          第三十个断言则是期望查询的结果为空而不是添加配置信息时的值，期望不相等，否则说明件中的配置信息未被全部清除。

          

    