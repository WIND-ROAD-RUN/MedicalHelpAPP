#include "ILS_IntLanguage.h"

IntLanguage::IntLanguage
(IntLanguageDataAbstract* intLanguageData)
    :m_intLanData(intLanguageData)
{
}

IntLanguage::~IntLanguage()
{
}

void IntLanguage::setLanguageData(IntLanguageDataAbstract* intLanData)
{
    if (m_intLanData) {
        delete m_intLanData;
    }

    m_intLanData = intLanData;
}

IntLanguageDataAbstract::ErrorInfo
IntLanguage::iniCom()
{
    auto iniResult=m_intLanData->iniCom();
    if (iniResult!=ErrorInfo::SUCCESS) {
        return iniResult;
    }

    auto getIntLanMapResult = m_intLanData->getMap(m_intLanMap);
    if (getIntLanMapResult!=ErrorInfo::SUCCESS) {
        return getIntLanMapResult;
    }

    return ErrorInfo::SUCCESS;
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguage::desCom()
{
    if (m_intLanMap) {
        delete m_intLanMap;
    }

    if (m_intLanData) {
        auto desComResult = m_intLanData->desCom();
        if (desComResult != ErrorInfo::SUCCESS) {
            return desComResult;
        }

        delete m_intLanData;
    }

    return ErrorInfo::SUCCESS;
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguage::searchString(const String& id, const String& language, String& s) const
{
    return ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguage::storeString(const String& id, const String& language, const String& s)
{


    return ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguage::changeString(const String& id, const String& language, const String& s)
{
    return ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguage::delString(const String& id, const String& language)
{
    return ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguage::getMap(IntLanMap* intLanMap) const
{
    return ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguage::getMap(const String& language, LanStringMap* lanStringMap) const
{
    return ErrorInfo();
}

IntLanguageDataAbstract::ErrorInfo 
IntLanguage::clearData()
{
    return ErrorInfo();
}
