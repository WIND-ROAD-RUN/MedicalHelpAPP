#include "ILS_IntLanguageCom.h"
#include"ILS_IntLanguageDataXML.h"

bool IntLanguageCom::iniCom()
{
    m_intLanguageData = new IntLanguageDataXML();
    auto result = m_intLanguageData->iniCom();

    if (result != IntLanguageDataAbstract::ErrorInfo::SUCCESS) {
        return false;
    }

    return true;
}

bool IntLanguageCom::desCom()
{
    auto result=m_intLanguageData->desCom();

    if (result!=IntLanguageDataAbstract::ErrorInfo::SUCCESS) {
        return false;
    }

    delete m_intLanguageData;

    return false;
}
