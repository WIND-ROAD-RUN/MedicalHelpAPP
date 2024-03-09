#ifndef ITS_INTLANGUAGEDATAABSTRACT_H_
#define ITS_INTLANGUAGEDATAABSTRACT_H_

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

#endif // !ITS_INTLANGUAGEDATAABSTRACT_H_
