#ifndef ILS_INTLANGUAGEDATAABSTRACT_H_
#define ILS_INTLANGUAGEDATAABSTRACT_H_

#include"ILS_IntlanguageData.h"

#include<string>
#include<vector>
#include<map>

namespace HiddenButNotExposed {
namespace ILS {


class IntLanguageDataAbstract {
public:
    using String = IntLanguageData::String;

    using ErrorInfo = IntLanguageData::ErrorInfo;

    template<typename T>
    using Vector = IntLanguageData::Vector<T>;

    template<typename T1, typename T2>
    using Map = IntLanguageData::Map<T1, T2>;

    template<typename T1, typename T2>
    using Pair = IntLanguageData::Pair<T1, T2>;

    using IntLanMap = Map<String, Map<String, String>>;

    using LanStringMap = Map<String, String>;

public:
    virtual ErrorInfo iniCom() = 0;

    virtual ErrorInfo desCom() = 0;

public:
    virtual ErrorInfo searchString(const String& id, const String& language, String& s)const = 0;

    virtual ErrorInfo storeString(const String& id, const String& language, const String& s) = 0;

    virtual ErrorInfo changeString(const String& id, const String& language, const String& s) = 0;

    virtual ErrorInfo delString(const String& id, const String& language) = 0;

    virtual ErrorInfo getMap(IntLanMap* intLanMap) const = 0;

    virtual ErrorInfo getMap(const String& language, LanStringMap* lanStringMap) const = 0;

    virtual ErrorInfo clearData() = 0;
};

} // Packages
} // Company



#endif // !ILS_INTLANGUAGEDATAABSTRACT_H_
