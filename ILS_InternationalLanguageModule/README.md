# IntLanguageData模块手册


这是一个用于存储国际化语言字符串的模块。

先给出抽象基类头文件ILS_IntLanguageDatabaseAbstract_H_

```cpp
#ifndef ILS_INTLANGUAGEDATAABSTRACT_H_
#define ILS_INTLANGUAGEDATAABSTRACT_H_

#include<string>
#include<vector>
#include<map>

struct IntLanguageData
{
    enum ErrorInfo {
        INI_ERROR,
        DES_ERROR,
        SEARCH_STRING_ERROR_ID,
        SEARCH_STRING_ERROR_LANGUAGE,
        STORE_STRING_ERROR_ID,
        STORE_STRING_ERROR_LANGUAGE,
        CHANGE_STRING_ERROR_ID,
        CHANGE_STRING_ERROR_LANGUAGE,
        DEL_STRING_ERROR_ID,
        DEL_STRING_ERROR_LANGUAGE,
        GET_MAP_ERROR,
        GET_MAP_ERROR_LANGUAGE,
        ERROR,
        CLEAR_ERROR,
        SUCCESS
    };

    using String = std::string;

    template<typename T>
    using Vector = std::vector<T>;
    
    template<typename T1,typename T2>
    using Map = std::map<T1, T2>;

    template<typename T1,typename T2>
    using Pair = std::pair<T1, T2>;

};

class IntLanguageDataAbstract {
public:
    using String = IntLanguageData::String;
    using ErrorInfo = IntLanguageData::ErrorInfo;
    
    template<typename T>
    using Vector = IntLanguageData::Vector<T>;

    template<typename T1, typename T2>
    using Map = IntLanguageData::Map<T1,T2>;

    template<typename T1, typename T2>
    using Pair = IntLanguageData::Pair<T1,T2>;
    
    using IntLanMap = Map<String, Map<String, String>>;
    using LanStringMap = Map<String, String>;

public:
    virtual ErrorInfo iniCom() = 0;

    virtual ErrorInfo desCom() = 0;

public:
    virtual ErrorInfo searchString(const String& id,const String& language, String& s )const = 0 ;

    virtual ErrorInfo storeString(const String& id,const String& language,const String& s) = 0;

    virtual ErrorInfo changeString(const String& id,const String& language,const String& s)=0;

    virtual ErrorInfo delString(const String& id,const String& language,const String& s)=0;
     
    virtual ErrorInfo getMap(IntLanMap * intLanMap) const = 0;

    virtual ErrorInfo getMap(const String & language, LanStringMap * lanStringMap) const = 0;

    virtual ErrorInfo clearData() = 0;
};

#endif // !ILS_INTLANGUAGEDATAABSTRACT_H_

```

# 结构体`IntLanguageData`

头文件第一部分为结构体`IntlanguageData`，它是一个外部实体，用于包装一些枚举变量和类型别名。

```cpp
struct IntLanguageData
{
    enum ErrorInfo {
        INI_ERROR,
        DES_ERROR,
        SEARCH_STRING_ERROR_ID,
        SEARCH_STRING_ERROR_LANGUAGE,
        STORE_STRING_ERROR_ID,
        STORE_STRING_ERROR_LANGUAGE,
        CHANGE_STRING_ERROR_ID,
        CHANGE_STRING_ERROR_LANGUAGE,
        DEL_STRING_ERROR_ID,
        DEL_STRING_ERROR_LANGUAGE,
        GET_MAP_ERROR,
        GET_MAP_ERROR_LANGUAGE,
        ERROR,
        CLEAR_ERROR,
        SUCCESS
    };

    using String = std::string;

    template<typename T>
    using Vector = std::vector<T>;
    
    template<typename T1,typename T2>
    using Map = std::map<T1, T2>;

    template<typename T1,typename T2>
    using Pair = std::pair<T1, T2>;

};
```

## 枚举变量`ErrorInfo`

```cpp
enum ErrorInfo {
    INI_ERROR,
    DES_ERROR,
    SEARCH_STRING_ERROR_ID,
    SEARCH_STRING_ERROR_LANGUAGE,
    STORE_STRING_ERROR_ID,
    STORE_STRING_ERROR_LANGUAGE,
    CHANGE_STRING_ERROR_ID,
    CHANGE_STRING_ERROR_LANGUAGE,
    DEL_STRING_ERROR_ID,
    DEL_STRING_ERROR_LANGUAGE,
    GET_MAP_ERROR,
    GET_MAP_ERROR_LANGUAGE,
    CLEAR_ERROR,
    ERROR,
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

template<typename T1,typename T2>
using Map = std::map<T1, T2>;

template<typename T1,typename T2>
using Pair = std::pair<T1, T2>;
```
对一组将会使用的类型取了别名，方便后期替换。

-----

# 抽象基类`IntLanguageDataAbstract`

```cpp
class IntLanguageDataAbstract {
public:
    using String = IntLanguageData::String;
    using ErrorInfo = IntLanguageData::ErrorInfo;
    
    template<typename T>
    using Vector = IntLanguageData::Vector<T>;

    template<typename T1, typename T2>
    using Map = IntLanguageData::Map<T1,T2>;

    template<typename T1, typename T2>
    using Pair = IntLanguageData::Pair<T1,T2>;
    
    using IntLanMap = Map<String, Map<String, String>>;
    using LanStringMap = Map<String, String>;

public:
    virtual ErrorInfo iniCom() = 0;

    virtual ErrorInfo desCom() = 0;

public:
    virtual ErrorInfo searchString(const String& id,const String& language, String& s )const = 0 ;

    virtual ErrorInfo storeString(const String& id,const String& language,const String& s) = 0;

    virtual ErrorInfo changeString(const String& id,const String& language,const String& s)=0;

    virtual ErrorInfo delString(const String& id,const String& language,const String& s)=0;
     
    virtual ErrorInfo getMap(IntLanMap * intLanMap) const = 0;

    virtual ErrorInfo getMap(const String & language, LanStringMap * lanStringMap) const = 0;

    virtual ErrorInfo clearData() = 0;
};
```
定义了国际化语言字符串使用的通用接口

## 类型别名

```cpp
using String = IntLanguageData::String;
using ErrorInfo = IntLanguageData::ErrorInfo;

template<typename T>
using Vector = IntLanguageData::Vector<T>;

template<typename T1, typename T2>
using Map = IntLanguageData::Map<T1,T2>;

template<typename T1, typename T2>
using Pair = IntLanguageData::Pair<T1,T2>;

using IntLanMap = Map<String, Map<String, String>>;
using LanStringMap = Map<String, String>;
```

在类继承体系以及实现中请使用相关类型的时候请用该上述别名。

> 注意当有其他类型属于标准库的时候请向抽象基类编写人员反应，并作出相应更新。

下面对一些别名做出解释

- `IntLanMap = Map<String, Map<String, String>>`:存储的是所有的字符串，其中外层`Map`的第一个`String`表示为字符串`id`，第二个`Map`表示该`id`字符串对应的<国家,字串>。也即第二个`Map`的第一个`String`表示国家缩写，第二个`String`表示对应的字符串。
- `LanStringMap = Map<String, String>`:存储的一个国家对应的所有字符串，第一个`String`表示`id`,第二个`String`表示对应的字符串。

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
virtual ErrorInfo searchString(const String& id,const String& language, String& s )const = 0 ;

virtual ErrorInfo storeString(const String& id,const String& language,const String& s) = 0;

virtual ErrorInfo changeString(const String& id,const String& language,const String& s)=0;

virtual ErrorInfo delString(const String& id,const String& language,const String& s)=0;
 
virtual ErrorInfo getMap(IntLanMap * intLanMap) const = 0;

virtual ErrorInfo getMap(const String & language, LanStringMap * lanStringMap) const = 0;

virtual ErrorInfo clearData() = 0;
```
上述定义了一组实现的接口

- `searchString(const String& id,const String& language, String& s )`:通过ID、language直接在文件中查询字符串并存储在s中，并返回运行信息。
- `storeString(const String& id,const String& language,const String& s)`:通过ID、language直接在文件中存储s字符串，并返回运行信息。
- `changeString(const String& id,const String& language,const String& s)`:通过ID、language直接在文件中更改相应字符串为s，并返回运行信息。
- `delString(const String& id,const String& language,const String& s)`:通过ID、language直接在文件中删除对应字符串，并返回运行信息。
- `getMap(IntLanMap * intLanMap)`:将所有的国际化语言字符串存储到`intLanMap`中
- `getMap(const String & language, LanStringMap * lanStringMap)`:将`language`的国际化语言字符串存储到`lanStringMap`中。
- `clearData()`:清除文件中所有的数据。

---

# `IntLanguageDataXML`XML实现法的子类
