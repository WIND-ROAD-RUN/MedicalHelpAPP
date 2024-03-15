#include "ILS_IntLanguageCom.h"
#include"ILS_IntLanguageDataXML.h"

namespace HiddenButNotExposed {
    namespace ILS {
        bool IntLanguageCom::iniCom()
        {
            auto result = m_intLanguageData->iniCom();

            if (result != IntLanguageDataAbstract::ErrorInfo::SUCCESS) {
                return false;
            }

            return true;
        }

        bool IntLanguageCom::desCom()
        {
            auto result = m_intLanguageData->desCom();

            if (result != IntLanguageDataAbstract::ErrorInfo::SUCCESS) {
                return false;
            }

            delete m_intLanguageData;

            return false;
        }

        IntLanguageDataAbstract::ErrorInfo
            IntLanguageCom::searchString
            (const String& id, const String& language, String& s)
        {
            auto result = m_intLanguageData->searchString(id, language, s);

            return result;
        }

    }
}


