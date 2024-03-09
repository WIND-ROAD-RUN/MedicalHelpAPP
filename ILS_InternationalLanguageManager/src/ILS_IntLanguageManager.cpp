#include "ILS_IntLanguageManager.h"
#include"ILS_IntLanguageDataXML.h"

bool IntLanguageManagerManager::iniCom()
{
    m_intLanguageData = new IntLanguageDataXML();
    auto result=m_intLanguageData->iniCom();

    if (result!=IntLanguageDataAbstract::ErrorInfo::SUCCESS) {
        return false;
    }

    return true;
}

bool IntLanguageManagerManager::desCom()
{
    auto result = m_intLanguageData->desCom();

    if (result != IntLanguageDataAbstract::ErrorInfo::SUCCESS) {
        return false;
    }

    delete m_intLanguageData;

    return false;
}
