#ifndef COL_CONFIGLOADERABSTRACT_H_
#define COL_CONFIGLOADERABSTRACT_H_

#include<COL_ConfigLoaderUtility.h>

namespace HiddenButNotExposed {
namespace COL {

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
        virtual ErrorInfo iniCom() = 0;

        virtual ErrorInfo desCom() = 0;

    public:
        virtual ErrorInfo addConfig(const String & name, const String & value);

        virtual ErrorInfo deleteConfig(const String& name, const String& value);

        virtual ErrorInfo changeConfig(const String & name,const String & value);

        virtual ErrorInfo searchConfig(const String & name,String & value)const;

        virtual ErrorInfo getConfigMap(ConfigMap * map);



    };
    

}//package
}//Company






#endif // !COL_CONFIGLOADERABSTRACT_H_
