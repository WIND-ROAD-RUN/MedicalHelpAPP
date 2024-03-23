#include "ILS_IntLanguageManager.h"
#include"ILS_IntLanguageDataXML.h"

namespace HiddenButNotExposed {
    namespace ILS {
        IntLanguageManagerManager* IntLanguageManagerManager::m_instance = nullptr;

        bool IntLanguageManagerManager::iniCom()
        {
            auto result = m_intLanguageData->iniCom();

            if (result != IntLanguageDataAbstract::ErrorInfo::SUCCESS) {
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

            if (m_intLanguageData) {
                delete m_intLanguageData;
            }

            return false;
        }

        IntLanguageDataAbstract::ErrorInfo IntLanguageManagerManager::searchString(const String& id, const String& language, String& s) const
        {
            auto result = m_intLanguageData->searchString(id, language, s);

            return result;
        }

        IntLanguageDataAbstract::ErrorInfo IntLanguageManagerManager::storeString(const String& id, const String& language, const String& s)
        {
            auto result = m_intLanguageData->storeString(id, language, s);

            return result;
        }

        IntLanguageDataAbstract::ErrorInfo IntLanguageManagerManager::delString(const String& id, const String& language)
        {
            auto result = m_intLanguageData->delString(id, language);

            return result;
        }

        IntLanguageDataAbstract::ErrorInfo IntLanguageManagerManager::getMap(IntLanguageDataAbstract::IntLanMap* intLanMap) const
        {
            auto result = m_intLanguageData->getMap(intLanMap);

            return result;
        }

        IntLanguageDataAbstract::ErrorInfo IntLanguageManagerManager::getMap(const String& language, IntLanguageDataAbstract::LanStringMap* lanStringMap) const
        {
            auto result = m_intLanguageData->getMap(language, lanStringMap);

            return result;
        }


    }
}

