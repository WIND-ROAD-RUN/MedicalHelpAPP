#include "ITS_IntLanguageDataXML.h"

IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::iniCom()
{
    return IntLanguageDataAbstract::ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::desCom()
{
    return IntLanguageDataAbstract::ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::searchString
(const IntLanguageDataAbstract::String& id, const IntLanguageDataAbstract::String& language, IntLanguageDataAbstract::String& s )const
{
    return IntLanguageDataAbstract::ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::storeString
(const IntLanguageDataAbstract::String& id, const IntLanguageDataAbstract::String& language, const IntLanguageDataAbstract::String& s)
{
    return IntLanguageDataAbstract::ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::changeString
(const IntLanguageDataAbstract::String& id, const IntLanguageDataAbstract::String& language, const IntLanguageDataAbstract::String& s)
{
    return IntLanguageDataAbstract::ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::delString
(const IntLanguageDataAbstract::String& id, const IntLanguageDataAbstract::String& language, const IntLanguageDataAbstract::String& s)
{
    return IntLanguageDataAbstract::ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::getMap
(IntLanguageDataAbstract::IntLanMap* intLanMap) const
{
    return IntLanguageDataAbstract::ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::getMap
(const IntLanguageDataAbstract::String& language, IntLanguageDataAbstract::LanStringMap* lanStringMap )const
{
    return IntLanguageDataAbstract::ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguageDataXML::clearData()
{
    return IntLanguageDataAbstract::ErrorInfo();
}
