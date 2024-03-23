# **IntLanguageDataAbstract** 测试编写



## 具体实现



#### 深层测试删除字符串

```c++
TEST(SECOND_DEEP, DEL_STRING)
	{
		IntLanguageDataAbstract* test;
		test = new IntLanguageDataXML();
		auto result = test->iniCom();

		IntLanguageDataAbstract::String s , s1 = "CBD",s2 = "abbb",s3;
		result = test->storeString("1", "CHN", s1);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";


		result = test->searchString("1", "CHN", s);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串模块失败";
		EXPECT_EQ(s, s1) << "查找字符串失败";

		result = test->delString("1", "CHN");

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中删除字符串失败";

		result = test->searchString("1", "CHN", s3);

		EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "删除模块错误";
		EXPECT_NE(s, s3) << "字符串删除失败";

		result = test->storeString("1", "CHN", s1);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串s1存储到文件中失败";

		result = test->storeString("1", "CHN", s2);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串s2存储到文件中失败";

		result = test->delString("1", "CHN");

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中删除字符串失败";

		result = test->searchString("1", "CHN", s);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未找到对应字符串";

		EXPECT_EQ(s, s1) << "删除的字符串是先存储的s1";

		EXPECT_EQ(s, s2) << "删除的字符串是后存储的s2";

		result = test->clearData();

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未能清空内存所有数据";
    	result = test->desCom();
    
    	delete test;
	}
```

此测试首先创建一个抽象基类对象 test并且对它初始化，然后通过ID、 language在文件中存储字符串s1中，并返回运行信息。将返回的运行信息编写一个断言验证字符串是否存储成功，若成功则继续，否则打印相关信息。

然后通过ID、 language在文件中查询字符串并存储在s中，并返回运行信息。我们同样为返回的信息编写一个断言判断程序是否能够查询相关字符串，毕竟这是找到字符串是删除此字符串的前提。

以上两步断言均通过后，通过ID、 language在文件中删除对应字符串，并返回运行信息，再次编写断言判断删除字符串是否正确执行。

正确执行了删除字符串模块后，再次通过ID、language查找相关字符串就不会返回SUCCESS，我们可以在执行删除字符串操作后再次查询字符串判断是否成功删除了。由于``searchString()``函数是将查询到的字符串存放在字符串引用中，我们这里只要比较查询后的字符串是否和原字符串相等即可判断成功删除与否。

**本测试提出当通过同一个ID、language在文件中存储两个或者多个不同的字符串时，文件是否可以成功保存，若可以被保存，那么执行删除字符串操作时，删除的又是哪一个字符串。**

> > 测试结果显示不能通过同一个ID、language在文件中存储两个或者多个不同的字符串，当用同一个id、language存储不同的字符串的时候会返回STORE_STRING_ERROR_ID的错误信息。
> >
> > 在执行完删除字符串之后在用同样的ID、language去查询字符串，返回的结果是SEARCH_STRING_ERROR_ID，说明第二次用同样的id、language存储字符串是失败的。

***



#### 深层测试搜索字符串

```c++
TEST(SECOND_DEEP,SEARCH_STRING )
	{
		IntLanguageDataAbstract* test;
		test = new IntLanguageDataXML();
		auto result = test->iniCom();

		IntLanguageDataAbstract::String s, s1 = "CBD", s2 = "abbb";
		result = test->searchString("1", "CHN", s);

		EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "请检查是否有未清空内存的异常情况";

		result = test->storeString("1", "CHN", s1);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "字符串存储失败";

		result = test->searchString("1", "CHN", s);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "字符串查找失败";

		EXPECT_EQ(s, s1) << "字符串查找错误";

		result = test->searchString("1", " ", s);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "无法查询空的国家字符串";

		EXPECT_EQ(s, s1) << "请检查查找的字符串是否正确";

		result = test->searchString(" ", "CHN", s);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "空的ID查询失败";

		EXPECT_EQ(s, s1) << "请检查查找的字符串是否正确";

		result = test->storeString("1", "CHN", s2);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "字符串存储失败";

		result = test->searchString("1", "CHN", s);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "字符串查找失败";

		EXPECT_EQ(s, s1) << "检索的字符串不是先存入的那个";

		EXPECT_EQ(s, s2) << "检索的字符串是先存入的那个";

		result = test->clearData();

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清空所有数据失败";
		
    	result = test->desCom();	
    
		delete test;

	}
```

此测试首先创建一个抽象基类对象 test并且对它初始化，既测试查找字符串功能，先在未存储字符串的情况下由一个任给的ID、language来查询字符串，预期结果不会返回SUCCESS，若返回确实查询到相关字符串，可能是某次测试未清空内存或者其他情况，由断言打印出错误信息。

然后通过ID、 language在文件中存储字符串s1中，并返回运行信息。将返回的运行信息编写一个断言验证字符串是否存储成功，若成功则继续，否则打印相关信息。

接着通过ID、 language在文件中查询字符串并存储在s中，并返回运行信息。我们同样为返回的信息编写一个断言判断程序是否能够查询相关字符串，这里通过比较查询后的字符串是否和原字符串相等即可判断成功添加和搜索与否。

测试分别给出空的language和空的id来进行搜索，期望的搜索结果是SUCCESS，但是这与``searchString()``函数的参数列表不符合，空的language返回的是SEARCH_STRING_ERROR_ID，空的id查询结果返回的是DES_ERROR。

**此测试中同样测试到提出当通过同一个ID、language在文件中存储两个或者多个不同的字符串时，文件是否可以成功保存，那么执行查找字符串操作时，查找的又是哪一个字符串**

> > 测试结果返回的是不能通过同一个ID、language在文件中存储两个或者多个不同的字符串，会返回STORE_STRING_ERROR_ID的错误信息。

***

### 深层测试存储字符串

```c++
TEST(SECOND_DEEP, STORE_STRING)
	{
		IntLanguageDataAbstract* test;
		test = new IntLanguageDataXML();
		auto result = test->iniCom();

		IntLanguageDataAbstract::String s,s1 = "CBD", s2 = "abbb";
		result = test->storeString("1", "CHN", s1);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "存储字符串失败";

		result = test->searchString("1", "CHN", s);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查询字符串失败";
		EXPECT_EQ(s,s1) << "请检查是否查询的字符串有误";

		result = test->storeString("1", "CHN", s2);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "存储字符串失败";

		result = test->searchString("1", "CHN", s);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查询字符串失败";

		EXPECT_EQ(s, s1) << "存储id与language相同的字符串会覆盖原字符串";
		EXPECT_EQ(s, s2) << "按照存储的顺序返回同输入参数的字符串";

		result = test->storeString(" ", " ", s1);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "不能为空id和language存入字符串";

		result = test->clearData();

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清空所有数据失败";
	

		result = test->desCom();

		delete test;

	}
```

此测试首先创建一个抽象基类对象 test并且对它初始化，然后通过ID、 language在文件中存储字符串s1中，并返回运行信息。将返回的运行信息编写一个断言验证字符串是否存储成功，若成功则继续，否则打印相关信息。

然后通过ID、 language在文件中查询字符串并存储在s中，并返回运行信息。我们同样为返回的信息编写一个断言判断程序是否能够查询相关字符串，能查询到相关字符串说明存储字符串成功。

当通过相同的id、language向文件中存储字符串的时候，第二次调用并不能成功存储，会返回STORE_STRING_ERROR_ID的错误信息。

即使对相同的id、language多次存储字符串，也只会保留第一次存入的字符串，查询字符串得到的结果也是第一次存入的字符串。

**当使用空的id和空的language存入字符串的时候，返回结果是SUCCESS，可以向文件中存储字符串。**

***



### 综合调用各个功能

```c++
TEST(DEEP, SOME)
	{
		IntLanguageDataAbstract* test;
		test = new IntLanguageDataXML();
		auto result = test->iniCom();

		IntLanguageDataAbstract::String  s1 = "CBD", s2 = "abbb", s3,s4,s;

		result = test->storeString("1", "CHN", s1);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串s1存储到文件中失败";

		result = test->searchString("1", "CHN", s3);

		EXPECT_EQ(s3, s1) << "查找字符串s1失败";

		result = test->storeString("1", "CHN", s2);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串s2存储到文件中失败";

		result = test->searchString("1", "CHN", s4);

		EXPECT_NE(s3, s4) << "对同一个id和language读入不同字符串的存储方式不同";

		result = test->delString("1", "CHN");

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中删除字符串失败";

		result = test->searchString("1", "CHN", s);

		EXPECT_EQ(s, s1) << "删除的是先存入的字符串";

		EXPECT_EQ(s, s2) << "删除的是后存入的字符串";

		result = test->changeString("1", "CHN", "okkkk");

		s = "0";

		result = test->searchString("1", "CHN", s);

		EXPECT_EQ(s, "okkkk")<<"未成功修改字符串";

		result = test->desCom();

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "销毁工作失败";

		result = test->clearData();

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未能清空内存所有数据";
	
		result = test->desCom();

		delete test;
	}
```

测试首先创建一个抽象基类对象 test并且对它初始化，然后通过ID、 language在文件中存储字符串s1中，并返回运行信息。将返回的运行信息编写一个断言验证字符串是否存储成功，若成功则继续，否则打印相关信息。

然后通过ID、 language在文件中查询字符串并存储在s中，并返回运行信息。我们同样为返回的信息编写一个断言判断程序是否能够查询相关字符串，能查询到相关字符串说明存储字符串成功。

这里测试仍然用到了上述通过同一个id、language来存储字符串是否能成功的测试用例，由于目前功能不明确，暂不下定论。

***

> > 以上四个模块是出现错误信息的测试用例编写,以下测试为通过测试的具体实现

### 浅层测试搜索字符串

```c++
TEST(FIRST_DEEP, SEARCH_STRING)
	{
		IntLanguageDataAbstract* test;
		test = new IntLanguageDataXML();
		auto result = test->iniCom();

		IntLanguageDataAbstract::String  s,s1,s2;

		result = test->searchString("1", "CHN", s);

		EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "请检查是否存在未清空内存数据的异常情况";

		s = "BCD";
		result = test->storeString("1", "CHN", s);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "存储字符串失败";

		result = test->searchString("1", "CHN", s1);
		//s1 = BCD
		EXPECT_EQ(s, s1) << "查找字符串失败";
		//EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串失败";

		result = test->searchString("2", "CHN", s2);

		EXPECT_NE(s, s2) << "查找字符串错误";
		//EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串失败";


		result = test->searchString("1", "chn", s2);

		EXPECT_NE(s, s2) << "查找字符串错误";
		//EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串失败";


		result = test->searchString("2", "chn", s2);

		EXPECT_NE(s, s2) << "查找字符串错误";
		//EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串失败";

		result = test->clearData();
		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清空所有数据失败";

		result = test->searchString("1", "CHN", s2);
		EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清空数据有误或者内存错误";

		result = test->desCom();


		delete test;

	}
```

### 浅层测试存储字符串

```c++
TEST(FIRST_DEEP, STORE_STRING)
	{
		IntLanguageDataAbstract* test;
		test = new IntLanguageDataXML();
		auto result = test->iniCom();

		IntLanguageDataAbstract::String s , s1;

		result = test->searchString("1", "CHN", s);

		EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "请检查是否存在未清空内存的异常情况";

		s = "CBD";
		result = test->storeString("1","CHN", s);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";

		result = test->searchString("1", "CHN", s1);

		EXPECT_EQ(s1, s) << "查找字符串失败或者存储字符串失败";
		//EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";
		
		 result = test->clearData();
		 EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未能清空内存所有数据";
	
		 result = test->desCom();


		 delete test;

	}
```

### 浅层测试修改字符串

```c++
TEST(FIRST_DEEP, CHANGE_STRING)
	{
		IntLanguageDataAbstract* test;
		test = new IntLanguageDataXML();
		auto result = test->iniCom();

		IntLanguageDataAbstract::String s{"CBD"},s1,s2 = "abbb",s3;
		result = test->storeString("1", "CHN", s);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";

		result = test->searchString("1", "CHN", s1);
		//s1 = cbd

		EXPECT_EQ(s1,s) <<"在文件中查找字符串失败";

		result = test->changeString("1","CHN", s2);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中更改字符串失败";

		result = test->searchString("1", "CHN", s3);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中查找字符串失败";
		EXPECT_EQ(s2,s3) << "字符串修改失败";

		test->clearData();

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未能清空内存所有数据";

		result = test->desCom();


		delete test;

	}
```

### 浅层测试删除字符串

```c++
TEST(FIRST_DEEP, DEL_STRING)
	{
		IntLanguageDataAbstract* test;
		test = new IntLanguageDataXML();
		auto result = test->iniCom();

		IntLanguageDataAbstract::String s = "CBDA",s1,s2;
		result = test->storeString("1", "CHN", s);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";


		result = test->searchString("1", "CHN", s1);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串模块失败";
		EXPECT_EQ(s, s1) << "查找字符串失败";

		result = test->delString("1","CHN");

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "在文件中删除字符串失败";

		result = test->searchString("1", "CHN", s2);

		EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "删除模块失败";
		EXPECT_NE(s,s2) << "字符串删除失败";

		result =test->clearData();

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未能清空内存所有数据";
	
		result = test->desCom();

		delete test;

	}
```

### 浅层测试清除所有数据

```c++
TEST(FIRST_DEEP, CLEAR_DATA)
	{
		IntLanguageDataAbstract* test;
		test = new IntLanguageDataXML();
		auto result = test->iniCom();

		IntLanguageDataAbstract::String s{"abbb"},s1,s2;
		result = test->storeString("1", "CHN", s);
		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "存储字符串失败";

		result = test->searchString("1", "CHN", s1);
		//s1 = abbb

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "查找字符串失败";
		EXPECT_EQ(s, s1) << "查找字符串失败";

		result = test->clearData();
		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清除所有数据失败";

		result = test->searchString("1", "CHN", s2);

		EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清除所有数据失败，任然能搜索相关字符串";
		EXPECT_NE(s, s2) << "清除数据删除失败";

		result = test->clearData();

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "未能清空内存所有数据";

		result = test->desCom();


		delete test;

	}
```

### 深层测试修改字符串

```c++
TEST(SECOND_DEEP, CHANGE_STRING)
	{
		IntLanguageDataAbstract* test;
		test = new IntLanguageDataXML();
		auto result = test->iniCom();

		IntLanguageDataAbstract::String s, s1{ "CBD" }, s2 = "abbb", s3;
		result = test->storeString("1", "CHN", s1);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "将字符串存储到文件中失败";

		result = test->searchString("1", "CHN", s);

		EXPECT_EQ(s1, s) << "在文件中查找字符串失败";

		result = test->changeString("1", "CHN", s2);

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "修改字符串失败";

		result = test->searchString("1", "CHN", s);

		EXPECT_NE(s1, s) << "修改字符串失败,仍然为原字符串";

		EXPECT_EQ(s2, s) << "修改字符串失败，没有更新为所给字符串";

		result = test->changeString("1", "chn", s2);

		EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "没有对应的id和language是否可以修改字符串";

		result = test->changeString(" ", " ", s2);

		EXPECT_NE(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "没有对应的id和language是否可以修改字符串";
	
		result = test->clearData();

		EXPECT_EQ(result, IntLanguageDataAbstract::ErrorInfo::SUCCESS) << "清空所有数据失败";

		result = test->desCom();


		delete test;

	}
```



