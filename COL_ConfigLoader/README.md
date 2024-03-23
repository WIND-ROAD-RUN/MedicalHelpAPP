# ConfigLoader模块手册


这是一个用于存储配置文件的模块。

先给出抽象基类头文件COL_ConfigLoaderDatabaseAbstract.h 和实用体构件COL_ConfigLoaderUtility.h

```cpp
#ifndef COL_CONFIGLOADERDATABASEXML_H_
#define COL_CONFIGLOADERDATABASEXML_H_

#include<COL_ConfigLoaderDatabaseAbstract.h>
#include<COL_ConfigLoaderUtility.h>

namespace HiddenButNotExposed {
    namespace COL {

        class ConfigLoaderDatabaseXML
            :public ConfigLoaderDatabaseAbstract{
        public:
            ConfigLoaderDatabaseXML(const String & filePath="");
            ~ConfigLoaderDatabaseXML();

        public:
            // 通过 ConfigLoaderDatabaseAbstract 继承
            inline ErrorInfo iniCom() override;

            inline ErrorInfo desCom() override;

            ErrorInfo addConfig(const String& name, const String& value) override;

            ErrorInfo deleteConfig(const String& name, const String& value) override;

            ErrorInfo changeConfig(const String& name, const String& value) override;

            ErrorInfo searchConfig(const String& name, String& value) const override;

            ErrorInfo getConfigMap(ConfigMap* map) override;

        };
        
    }//package
}//Company


#endif // !COL_CONFIGLOADERDATABASEXML_H_

```

```cpp
#ifndef COL_CONFIGLOADERUTILITY_H_
#define COL_CONFIGLOADERUTILITY_H_

#include<string>
#include<vector>
#include<map>

namespace HiddenButNotExposed {
    namespace COL {

        struct ConfigLoaderDataUtility
        {
            enum ErrorInfo {
                SUCCESS,

            };

            using String = std::string;

            template<typename T>
            using Vector = std::vector<T>;

            template<typename T1, typename T2>
            using Map = std::map<T1, T2>;

            template<typename T1, typename T2>
            using Pair = std::pair<T1, T2>;


        };





    }//package
}//Company


#endif // !COL_CONFIGLOADERUTILITY_H_

```

# 结构体`ConfigLoaderDataUtility`

头文件第一部分为结构体`ConfigLoaderDataUtility`，它是一个外部实体，用于包装一些枚举变量和类型别名。

```cpp
struct ConfigLoaderDataUtility
{
    enum ErrorInfo {
        SUCCESS,

    };

    using String = std::string;

    template<typename T>
    using Vector = std::vector<T>;

    template<typename T1, typename T2>
    using Map = std::map<T1, T2>;

    template<typename T1, typename T2>
    using Pair = std::pair<T1, T2>;


};
```

## 枚举变量`ErrorInfo` 

```cpp
enum ErrorInfo {
    SUCCESS
};
```

每一个枚举变量都标识了这个模块的错误代码信息，通过接口的返回值提供，在没有错误（正常运行）的时候返回`SUCCESS`，在发生了未知的错误时返回`ERROR`。
>当错误情况已知，但是没有枚举时，请向抽象基类编写人员反应，并做出更新。

## 类型别名

```cpp
 using String = std::string;

 template<typename T>
 using Vector = std::vector<T>;

 template<typename T1, typename T2>
 using Map = std::map<T1, T2>;

 template<typename T1, typename T2>
 using Pair = std::pair<T1, T2>;

```
对一组将会使用的类型取了别名，方便后期替换。

-----

# 抽象基类`ConfigLoaderDatabaseAbstract`

```cpp
class ConfigLoaderDatabaseAbstract {
public:
    using String = ConfigLoaderDataUtility::String;

    using ErrorInfo = ConfigLoaderDataUtility::ErrorInfo;

    template<typename T>
    using Vector = ConfigLoaderDataUtility::Vector<T>;

    template<typename T1, typename T2>
    using Map = ConfigLoaderDataUtility::Map<T1, T2>;

    template<typename T1, typename T2>
    using Pair = ConfigLoaderDataUtility::Pair<T1, T2>;

    using ConfigMap = Map<String, String>;

public:
    inline virtual ErrorInfo iniCom() = 0;

    inline virtual ErrorInfo desCom() = 0;

public:
    virtual ErrorInfo addConfig(const String& name, const String& value) = 0;

    virtual ErrorInfo deleteConfig(const String& name, const String& value) = 0;

    virtual ErrorInfo changeConfig(const String& name, const String& value) = 0;

    virtual ErrorInfo searchConfig(const String& name, String& value)const = 0;

    virtual ErrorInfo getConfigMap(ConfigMap* map) = 0;



};
```
定义了配置文件使用的通用接口

## 类型别名

```cpp
using String = ConfigLoaderDataUtility::String;

using ErrorInfo = ConfigLoaderDataUtility::ErrorInfo;

template<typename T>
using Vector = ConfigLoaderDataUtility::Vector<T>;

template<typename T1, typename T2>
using Map = ConfigLoaderDataUtility::Map<T1, T2>;

template<typename T1, typename T2>
using Pair = ConfigLoaderDataUtility::Pair<T1, T2>;

using ConfigMap = Map<String, String>;
```

在类继承体系以及实现中请使用相关类型的时候请用该上述别名。

> 注意当有其他类型属于标准库的时候请向抽象基类编写人员反应，并作出相应更新。

下面对一些别名做出解释

- `ConfigMap = Map<String, String>`:存储的是所有的配置信息，第一个`String`为配置信息名，第二个`String`为配置信息值。


## 抽象接口

```cpp
virtual ErrorInfo iniCom() = 0;

virtual ErrorInfo desCom() = 0;

```

这一组定义了组件的运行时必须运行的接口。

- `iniCom()`:在运行前进行初始化（加载、分配内存指针等）
- `desCom()`:在销毁前进行销毁前的准备工作（销毁指针等）

> 注意！当需要在`iniCom()`前做相关设置工作时，请在实现文档中做出相应阐述。供使用者明白使用过程。

```cpp
virtual ErrorInfo addConfig(const String& name, const String& value) = 0;

virtual ErrorInfo deleteConfig(const String& name, const String& value) = 0;

virtual ErrorInfo changeConfig(const String& name, const String& value) = 0;

virtual ErrorInfo searchConfig(const String& name, String& value)const = 0;

virtual ErrorInfo getConfigMap(ConfigMap* map) = 0;

virtual ErrorInfo clearData() = 0;
```
上述定义了一组实现的接口

- `searchString(const String& id,const String& language, String& s )`:通过ID、language直接在文件中查询字符串并存储在s中，并返回运行信息。
- `storeString(const String& id,const String& language,const String& s)`:通过ID、language直接在文件中存储s字符串，并返回运行信息。
- `changeString(const String& id,const String& language,const String& s)`:通过ID、language直接在文件中更改相应字符串为s，并返回运行信息。
- `delString(const String& id,const String& language,const String& s)`:通过ID、language直接在文件中删除对应字符串，并返回运行信息。
- `getMap(IntLanMap * intLanMap)`:将所有的国际化语言字符串存储到`intLanMap`中
- `getMap(const String & language, LanStringMap * lanStringMap)`:将`language`的国际化语言字符串存储到`lanStringMap`中。
- `clearData()`:清除当前实现所对应的所有存储数据（文件\内存）。

---

# `IntLanguageDataXML`XML实现法的子类
<h2>更新</h2>

- 在子类IntLanguageDataXML中添加了两个私有变量：

  ```C++
  pugi::xml_document operatorDoc;
  String filePath;
  ```

	其中operatorDoc变量用于指向操作的文件，filePath用于指向操作文件的相对路径

- 创建了一个名为新的文件夹，存储在ILS_InternationalLanguageModule文件中，文件中新建了一个dataFile.xml文件

- 在ILS_IntLanguageDataXML.cpp文件中添加了 一个宏

  ```C++
  #define DEFAULT_PATH R"(.\database\dataFile.xml)"
  ```

  该宏主要用来指向xml文件的地址

- 将searchString，两个getMap函数的const属性移除

<h2>XML文件存储风格</h2>

形如下图

```c++
<?xml version="1.0"?>
<LanguageTranslate>
	<String id="1">
		<Country>
			<language language="USA">Hello</language>
			<language language="CHN">你好</language>
		</Country>
	</String>
</LanguageTranslate>
```



<h2>iniCom函数</h2>

```C++
IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::iniCom()
{
    m_filePath = DEFAULT_PATH;
    m_operatorDoc = new pugi::xml_document;
    auto result = m_operatorDoc->load_file(m_filePath.c_str());
    /*if (!result) {
        return IntLanguageDataAbstract::ErrorInfo::INI_ERROR;
    }*/
    if (!(m_operatorDoc->child("LanguageTranslate"))) {
        m_operatorDoc->append_child("LanguageTranslate");
    }
    return IntLanguageDataAbstract::ErrorInfo::SUCCESS;
}
```

初始化m_filePath变量指向修改文件，利用result变量查看文件是否加载成功。这里注释掉了result的判断是因为在测试过程中发现了result的异常（即result不能准确判断是否加载成功这一状态，例如当result为false时任能正常运行）。在XML文件中我们有根节点LanguageTranslate，当我们检查根节点没有时我们新建根节点并保存修改。函数执行成功返回SUCCESS。

<h2>desCom函数</h2>

```C++
IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::desCom()
{
    if (m_operatorDoc != NULL) {
        //std::cout << "YES" << '\n';
        m_operatorDoc->save_file(m_filePath.c_str());
        delete m_operatorDoc;
    }
    m_filePath.clear();
    return IntLanguageDataAbstract::ErrorInfo::SUCCESS;
}
```

一个函数执行结束的时候，执行desCom函数。当指向文件不为空时保存修改的文件，为空则视为DES_ERROR，同时清空文件路径，执行成功返回SUCCESS。

<h2>searchString函数</h2>

```C++
IntLanguageDataAbstract::ErrorInfo
IntLanguageDataXML::searchString
(const IntLanguageDataAbstract::String& id,
    const IntLanguageDataAbstract::String& language,
    IntLanguageDataAbstract::String& s)const
{
    for (pugi::xml_node& tool : m_operatorDoc->child("LanguageTranslate")) {
        if (tool.first_attribute().value() == id) {
            for (pugi::xml_node& tools : tool.child("Country").children()) {
                if (tools.first_attribute().value() == language) {
                    s = tools.text().get();
                    return ErrorInfo::SUCCESS;
                }
            }
            return ErrorInfo::SEARCH_STRING_ERROR_LANGUAGE;
        }
    }
    return IntLanguageDataAbstract::ErrorInfo::SEARCH_STRING_ERROR_ID;
}
```

首先判断初始化函数的正确性。其次从根节点开始遍历根节点的子节点，当子节点属性值为我们给出的id值时我们进入该子节点的子节点，进入子节点后我们查询子节点属性(language)的值是否与我们给定的一样，如果找到一样则将子节点的text存入字符串，未找到返回SEARCH_STRING_ERROR_LANGUAGE。

<h2>storeString函数</h2>

```C++
IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::storeString
(const IntLanguageDataAbstract::String& id, 
    const IntLanguageDataAbstract::String& language, 
    const IntLanguageDataAbstract::String& s)
{
    for (pugi::xml_node& tool : m_operatorDoc->child("LanguageTranslate")) {
        if (tool.first_attribute().value() == id) {
            for (pugi::xml_node& tools : tool.child("Country").children()) {
                if (tools.first_attribute().value() == language) {
                    if (tools.text().get() == s)return ErrorInfo::SUCCESS;
                    else return ErrorInfo::STORE_STRING_ERROR_LANGUAGE;
                }
            }
            auto node = tool.child("Country");
            node.append_child("language").append_attribute("language");
            node.last_child().first_attribute().set_value(language.c_str());
            node.last_child().text().set(s.c_str());
            return ErrorInfo::SUCCESS;
        }
    }
    auto node = m_operatorDoc->child("LanguageTranslate");
    node.append_child("String");
    node.last_child().append_attribute("id").set_value(id.c_str());
    node = node.last_child();
    node = node.append_child("Country");
    node.append_child("language").append_attribute("language").set_value(language.c_str());
    node.last_child().text().set(s.c_str());
    return IntLanguageDataAbstract::ErrorInfo::SUCCESS;
}
```

首先判断初始化函数的正确性。其次从根节点开始遍历根节点的子节点(即遍历string类型的元素)，当属性(id)值与给出的id值相同的时候，我们遍历其子节点(即language类型的元素)，当我们发现其存在，且和存在的字符串相等的时候，返回SUCCESS，不等返回STORE_STRING_ERROR_LANGUAGE，如果我们没有找到该language，我们新建一个language元素，同时存储text。当我们id都没有找到，我们在后面新建一个string类型元素存储新的元素，返回SUCCESS。

<h2>changeString函数</h2>

```C++
IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::changeString
(const IntLanguageDataAbstract::String& id, 
    const IntLanguageDataAbstract::String& language, 
    const IntLanguageDataAbstract::String& s)
{
    for (pugi::xml_node& tool : m_operatorDoc->child("LanguageTranslate")) {
        if (tool.first_attribute().value() == id) {
            for (pugi::xml_node& tools : tool.child("Country").children()) {
                if (tools.first_attribute().value() == language) {
                    tools.text().set(s.c_str());
                    return ErrorInfo::SUCCESS;
                }
            }
            return ErrorInfo::CHANGE_STRING_ERROR_LANGUAGE;
        }
    }
    return IntLanguageDataAbstract::ErrorInfo::CHANGE_STRING_ERROR_ID;
}
```

首先判断初始化函数的正确性。其次从根节点开始遍历根节点的子节点(即遍历string类型的元素)，当属性(id)值与给出的id值相同的时候，我们遍历其子节点(即language类型的元素)，当我们寻找到id与language都相同的元素时，我们将text值进行修改。当找到了id没找到language时，我们返回CHANGE_STRING_ERROR_LANGUAGE，当没找到id时，返回CHANGE_STRING_ERROR_ID。

<h2>delString</h2>

```C++
IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::delString
(const IntLanguageDataAbstract::String& id, const IntLanguageDataAbstract::String& language)
{
    for (pugi::xml_node& tool : m_operatorDoc->child("LanguageTranslate")) {
        if (tool.first_attribute().value() == id) {
            for (pugi::xml_node& tools : tool.child("Country").children()) {
                if (tools.first_attribute().value() == language) {
                    tool.child("Country").remove_child(tools);
                    return ErrorInfo::SUCCESS;
                }
            }
            return ErrorInfo::DEL_STRING_ERROR_LANGUAGE;
        }
    }
    return IntLanguageDataAbstract::ErrorInfo::DEL_STRING_ERROR_ID;
}
```

首先判断初始化函数的正确性。其次从根节点开始遍历根节点的子节点(即遍历string类型的元素)，当属性(id)值与给出的id值相同的时候，我们遍历其子节点(即language类型的元素)，当我们寻找到id与language都相同的元素时，我们将该元素进行删除。当找到了id没找到language时，我们返回DEL_STRING_ERROR_LANGUAGE，当没找到id时，返回DEL_STRING_ERROR_ID。

<h2>getMap函数</h2>

```C++
IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::getMap
(IntLanguageDataAbstract::IntLanMap* intLanMap)const
{
    if (!intLanMap)intLanMap = new IntLanMap;
    intLanMap->clear();
    for (pugi::xml_node tool : m_operatorDoc->child("LanguageTranslate")) {
        String id = tool.first_attribute().value();
        for (pugi::xml_node tools : tool.child("Country")) {
            String language = tools.first_attribute().value();
            (*intLanMap)[id][language] = tools.text().get();
        }
    }
    return IntLanguageDataAbstract::ErrorInfo::SUCCESS;
}
```

首先如果指针为空，则开辟new IntLanMap  。之后遍历所有元素结点以及所有子节点，将所有id和language可能出现的组合存储到intLanMap中。

<h2>getMap函数</h2>

```C++
IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::getMap
(const IntLanguageDataAbstract::String& language, 
    IntLanguageDataAbstract::LanStringMap* lanStringMap )const
{
    if (!lanStringMap)lanStringMap = new LanStringMap;
    lanStringMap->clear();
    for (pugi::xml_node tool : m_operatorDoc->child("LanguageTranslate")) {
        String id = tool.first_attribute().value();
        for (pugi::xml_node tools : tool.child("Country")) {
            String language_ = tools.first_attribute().value();
            if (language_ == language)(*lanStringMap)[id] = tools.text().get();
        }
    }
    return IntLanguageDataAbstract::ErrorInfo::SUCCESS;
}
```

首先判断初始化函数的正确性。遍历所有元素结点中包含language属性的结点，对比language属性，当属性相同时候，添加到LanStringMap中。

<h2>clearDate函数</h2>

```C++
IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::clearData()
{
    m_operatorDoc->remove_children();
    return IntLanguageDataAbstract::ErrorInfo::SUCCESS;
}
```

首先判断初始化函数的正确性。一键调用删除所有信息。