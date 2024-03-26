# ConfigLoader模块手册

# `ConfigLoader`组件

先给出`COL_ConfigLoader.h`的头文件
```cpp
#ifndef COL_CONFIGLOADER_H_
#define COL_CONFIGLOADER_H_

#include<COL_ConfigLoaderUtility.h>
#include<COL_ConfigLoaderDatabaseAbstract.h>
#include<COL_ConfigLoaderDatabaseXML.h>

namespace HiddenButNotExposed {
    namespace COL {

        class ConfigLoader_Database {
        public:
            using ErrorInfo = ConfigLoaderDataUtility::ErrorInfo;

            using String = ConfigLoaderDataUtility::String;

        private:
            ConfigLoader_Database();

            ~ConfigLoader_Database();

            friend class ConfigLoader;
  
        private:
            ConfigLoaderDatabaseAbstract* m_database{ nullptr };

            ConfigLoaderDatabaseAbstract::ConfigMap* m_configMap{nullptr};

        public:
            inline ErrorInfo iniCom();

            inline ErrorInfo desCom();

        public:
            ErrorInfo addConfig(const String& name, const String& value);

            ErrorInfo deleteConfig(const String& name, const String& value);

            ErrorInfo changeConfig(const String& name, const String& value);

            ErrorInfo searchConfig(const String& name, String& value) const;

            ErrorInfo clearData();

        };


        class ConfigLoader {
        public:
            using ErrorInfo = ConfigLoaderDataUtility::ErrorInfo;
            using String = ConfigLoaderDataUtility::String;

        private:
            ConfigLoader() {}

            static ConfigLoader* m_instance;

        public:
            inline static ConfigLoader* getInstance();

            ~ConfigLoader() {}

        private:
            ConfigLoader_Database* m_databaseLoader{ nullptr };

        public:
            inline ErrorInfo iniCom();

            inline ErrorInfo desCom();

        public:
            ErrorInfo addConfig(const String& name, const String& value);

            ErrorInfo deleteConfig(const String& name, const String& value) ;

            ErrorInfo changeConfig(const String& name, const String& value) ;

            ErrorInfo searchConfig(const String& name, String& value) const ;

            ErrorInfo clearData();

        };

      
//=================================================================================
//                      INLINE  FUNCTION DEFINITIONS
//=================================================================================
        ConfigLoader_Database::ErrorInfo 
            ConfigLoader_Database::iniCom() {
            if (!m_database) {
                m_database = new ConfigLoaderDatabaseXML();
            }

            auto iniDatabaseResult = m_database->iniCom();
            if (iniDatabaseResult != ErrorInfo::SUCCESS) {
                return iniDatabaseResult;
            }

            auto iniConfigMapResult = m_database->getConfigMap(m_configMap);
            if (iniConfigMapResult!=ErrorInfo::SUCCESS) {
                return iniConfigMapResult;
            }

            return ErrorInfo::SUCCESS;
        }

        ConfigLoader_Database::ErrorInfo
            ConfigLoader_Database::desCom() {
            auto desDatabaseResult = m_database->desCom();
            if (desDatabaseResult != ErrorInfo::SUCCESS) {
                return desDatabaseResult;
            }

            if (m_configMap) {
                delete m_configMap;
            }

            if (m_database) {
                delete m_database;
            }
          
            return ErrorInfo::SUCCESS;
        }

        ConfigLoader::ErrorInfo
            ConfigLoader::iniCom() {
            if (!m_databaseLoader) {
                m_databaseLoader = new ConfigLoader_Database();
            }

            auto iniDatabaseLoaderResult = m_databaseLoader->iniCom();
            if (iniDatabaseLoaderResult!=ErrorInfo::SUCCESS) {
                return iniDatabaseLoaderResult;
            }

            return ErrorInfo::SUCCESS;
        }

        ConfigLoader::ErrorInfo
            ConfigLoader::desCom() {

            auto desDatabaseLoaderResult = m_databaseLoader->desCom();
            if (desDatabaseLoaderResult != ErrorInfo::SUCCESS) {
                return desDatabaseLoaderResult;
            }

            if (m_databaseLoader) {
                delete m_databaseLoader;
            }

            return ErrorInfo::SUCCESS;
        }


        ConfigLoader* ConfigLoader::getInstance() {
            if (!m_instance) {
                m_instance = new ConfigLoader();
            }
            return m_instance;
        }

    }//package
}//Company

#endif // !COL_CONFIGLOADER_H_

```

## `ConfigLoader_Database`
`ConfigLoader_Database`是组件`ConfigLoader`的私有类，它封装了`ConfigLoaderDatabaseAbstract`类族，并且提供了对内存进行存取的操作。

以下是它的类声明：
```cpp
class ConfigLoader_Database {
public:
    using ErrorInfo = ConfigLoaderDataUtility::ErrorInfo;

    using String = ConfigLoaderDataUtility::String;

private:
    ConfigLoader_Database();

    ~ConfigLoader_Database();

    friend class ConfigLoader;
  
private:
    ConfigLoaderDatabaseAbstract* m_database{ nullptr };

    ConfigLoaderDatabaseAbstract::ConfigMap* m_configMap{nullptr};

public:
    inline ErrorInfo iniCom();

    inline ErrorInfo desCom();

public:
    ErrorInfo addConfig(const String& name, const String& value);

    ErrorInfo deleteConfig(const String& name, const String& value);

    ErrorInfo changeConfig(const String& name, const String& value);

    ErrorInfo searchConfig(const String& name, String& value) const;

    ErrorInfo clearData();

};
```

## `ConfigLoader`

`ConfigLoader`是组件的门户，它实现为一个单例模式，封装了模块的所有操作。
以下是它的类定义：

```cpp
class ConfigLoader {
public:
    using ErrorInfo = ConfigLoaderDataUtility::ErrorInfo;
    using String = ConfigLoaderDataUtility::String;

private:
    ConfigLoader() {}

    static ConfigLoader* m_instance;

public:
    inline static ConfigLoader* getInstance();

    ~ConfigLoader() {}

private:
    ConfigLoader_Database* m_databaseLoader{ nullptr };

public:
    inline ErrorInfo iniCom();

    inline ErrorInfo desCom();

public:
    ErrorInfo addConfig(const String& name, const String& value);

    ErrorInfo deleteConfig(const String& name, const String& value) ;

    ErrorInfo changeConfig(const String& name, const String& value) ;

    ErrorInfo searchConfig(const String& name, String& value) const ;

    ErrorInfo clearData();

};
```


# `ConfigLoaderDatabaseAbstract`存储实现族

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

## 结构体`ConfigLoaderDataUtility`

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

### 枚举变量`ErrorInfo` 

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

## 抽象基类`ConfigLoaderDatabaseAbstract`

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

### 类型别名

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


### 抽象接口

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

- `addConfig(const String& name, const String& value)`:添加名为`name`,值为`value`的配置信息，并返回运行信息。
- `deleteConfig(const String& name, const String& value)`:删除名为`name`,值为`value`的配置信息，并返回运行信息。
- `changeConfig(const String& name, const String& value)`:更改名为`name`,值为`value`的配置信息，并返回运行信息。
- `searchConfig(const String& name, String& value)const`:查找名为`name`的配置信息,将结果存储在`value`中，并返回运行信息。
- `getConfigMap(ConfigMap* map)`：返回所有的配置信息。
- `clearData()`:清除所有的配置信息。

---

## `ConfigLoaderDatabaseXML`XML实现法的子类

### 更新

**在子类ConfigLoadorDatabaseXML中添加了两个私有变量：**

```c++

        pugi::xml_document* m_operatorDoc;
        String m_filePath;
```
其中operatorDoc变量用于指向操作的文件，filePath用于指向操作文件的相对路径。

创建了一个新的名为database的文件夹，在其中新建一个xmlFile.xml文件。



### XML文件存储风格：

如下





### inicom函数

```c++
ConfigLoaderDatabaseXML::ErrorInfo 
    ConfigLoaderDatabaseXML::iniCom()
{
    if (m_filePath.empty())return ErrorInfo::INI_ERROR;
    if (!m_operatorDoc)m_operatorDoc = new pugi::xml_document;
    auto result = m_operatorDoc->load_file(m_filePath.c_str());
    if (!result)return ErrorInfo::INI_ERROR;
    if (m_operatorDoc->child("ConfigLoaderString") == NULL)
        m_operatorDoc->append_child("ConfigLoaderString");
    return ErrorInfo::SUCCESS;
}
```

如果文件路径为空，那么返回INI_ERROR；利用rusult变量查看是否加载成功，如果没有加载成功，则返回INI_ERROR，如果我们的根节点ConfigLoaderString为空，那我们则新建一个根节点。如果不为空，则返回SUCCESS；

### descom函数

```c++
ConfigLoaderDatabaseXML::ErrorInfo 
    ConfigLoaderDatabaseXML::desCom()
{
    m_filePath.clear();
    if (m_operatorDoc)delete m_operatorDoc;
    return ErrorInfo::SUCCESS;
}
```

首先清空文件路径，如果操作文件不为空，则删除该操作的文件，并且返回SUCCESS。

### addConfig函数

```c++
ConfigLoaderDatabaseXML::ErrorInfo 
    ConfigLoaderDatabaseXML::addConfig(const String& name, const String& value)
{
    if (!m_operatorDoc)return ErrorInfo::ERROR;
    for (auto tool : m_operatorDoc->child("ConfigLoaderString").children()) {
        if (tool.first_attribute().value() == name)return ErrorInfo::ADD_ERROR_NAME;
    }
    pugi::xml_node node = m_operatorDoc->child("ConfigLoaderString");
    node.append_child("String");
    node.last_child().append_attribute("id").set_value(name.c_str());
    node.last_child().text().set(value.c_str());
    return ErrorInfo::SUCCESS;
}
```

首先如果操作文件为空，则返回ERROR；然后我们从根节点的子节点遍历，如果如果第一个子节点的属性的值与我们给出的值相同，则返回ADD_ERROR_NAME；

如果没有找到与我们给出的值相同的则新建一个string类型元素，同时存储text，并且返回SUCCESS。

### deleteConfig函数

```c++
ConfigLoaderDatabaseXML::ErrorInfo 
    ConfigLoaderDatabaseXML::deleteConfig(const String& name, const String& value)
{
    if (!m_operatorDoc)return ErrorInfo::ERROR;
    for (auto& tool : m_operatorDoc->child("ConfigLoaderString").children()) {
        if (tool.first_attribute().value() == name) {
            if (tool.text().get() == value) {
                m_operatorDoc->child("ConfigLoaderString").remove_child(tool);
                return ErrorInfo::SUCCESS;
            }
            return ErrorInfo::DELETE_ERROR_VALUE;
        }
    }
    return ErrorInfo::DELETE_ERROR_NAME;
}
```

首先如果操作文件为空，则返回ERROR；其次我们从根节点开始遍历根节点的子节点，如果第一个子节点的属性的值与我们给出的相同，并且存在value这个值，则删除根节点的子节点，并返回DELETE_ERROR_VALUE。如果第一个子节点的属性的值与我们给出的不同，则返回DELETE_ERROR_NAME；

### changeConfig函数

```c++
 ConfigLoaderDatabaseXML::ErrorInfo 
     ConfigLoaderDatabaseXML::changeConfig(const String& name, const String& value)
 {
     if (!m_operatorDoc)return ErrorInfo::ERROR;
     for (auto& tool : m_operatorDoc->child("ConfigLoaderString").children()) {
         if (tool.first_attribute().value() == name) {
             tool.text().set(value.c_str());
             return ErrorInfo::SUCCESS;
         }
     }
     return ErrorInfo::CHANGE_ERROR_NAME;
 }
```

首先如果操作文件为空，则返回ERROR；其次我们从根节点开始遍历根节点的子节点，如果我的第一个属性的值与我们的name相同，则储存text，对该值进行更改，并返回SUCCESS，否则返回CHANGE_ERROR_NAME。

### searchConfig函数

```c++
ConfigLoaderDatabaseXML::ErrorInfo 
    ConfigLoaderDatabaseXML::searchConfig(const String& name, String& value) const
{
    if (!m_operatorDoc)return ErrorInfo::ERROR;
    for (pugi::xml_node& tool : m_operatorDoc->child("ConfigLoaderString")) {
        if (tool.first_attribute().value() == name) {
            if (tool.text().get() == value)return ErrorInfo::SUCCESS;
            return ErrorInfo::SEARCH_ERROR_VALUE;
        }
    }
    return ErrorInfo::SEARCH_ERROR_NAME;
}
```

首先如果操作文件为空，则返回ERROR；其次我们从根节点开始遍历根节点的子节点，如果我的第一个属性的值与我们的name相同，并且我的value值也相同，则返回SUCCESS，否则返回SEARCH_ERROR_NAME。

### getConfigMap函数

```c++
ConfigLoaderDatabaseXML::ErrorInfo 
    ConfigLoaderDatabaseXML::getConfigMap(ConfigMap* map)
{
    if (map == NULL)map = new ConfigMap;
    map->clear();
    if (!m_operatorDoc)return ErrorInfo::ERROR;
    for (auto tool : m_operatorDoc->child("ConfigLoaderString").children()) {
        (*map)[tool.first_attribute().value()] = tool.text().get();
    }
    return ErrorInfo::SUCCESS;
}

```

首先判断指针是否为空，是否为他开辟新的空间。如果操作文件为空，则返回ERROR，其次我们从根节点开始遍历根节点的子节点，童书记将子节点第一个的属性的值存储text，同时返回SUCCESS。

### clearData函数

```c++
ConfigLoaderDatabaseXML::ErrorInfo 
    ConfigLoaderDatabaseXML::clearData()
{
    if (!m_operatorDoc)return ErrorInfo::ERROR;
    m_operatorDoc->child("ConfigLoaderString").remove_children();
    return ErrorInfo::CLEAR_ERROR;
}
```

首先如果操作文件为空，则返回SAVE_ERROR；如果不为空，那么我将会清除操作文件的根节点的子节点，并返回CLEAR_ERROR。

### saveData函数

```c++
ConfigLoaderDatabaseXML::ErrorInfo 
    ConfigLoaderDatabaseXML::saveData()
{
    if (!m_operatorDoc)return ErrorInfo::SAVE_ERROR;
    if (m_filePath == "")return ErrorInfo::SAVE_ERROR;
    m_operatorDoc->save_file(m_filePath.c_str());
    return ErrorInfo::SUCCESS;
}
```

首先如果操作文件为空，则返回SAVE_ERROR；如果我的文件路径为空，则返回SAVE_ERROR；否则，就保存文件路径，并返回SUCCESS。



































