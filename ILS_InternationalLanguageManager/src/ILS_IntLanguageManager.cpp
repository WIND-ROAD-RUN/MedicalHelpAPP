#include "ILS_IntLanguageManager.h"
#include"ILS_IntLanguageDataXML.h"

namespace HiddenButNotExposed {
    namespace ILS {
        IntLanguageManager* IntLanguageManager::m_instance = nullptr;

        bool IntLanguageManager::iniCom()
        {
            auto result = m_intLanguageData->iniCom();

            if (result != IntLanguageDataAbstract::ErrorInfo::SUCCESS) {
                return false;
            }

            return true;
        }

        bool IntLanguageManager::desCom()
        {
            auto result = m_intLanguageData->desCom();

            if (result != IntLanguageDataAbstract::ErrorInfo::SUCCESS) {
                return false;
            }

            if (m_intLanguageData) {
                delete m_intLanguageData;
            }

            return true;
        }

        IntLanguageDataAbstract::ErrorInfo IntLanguageManager::searchString(const String& id, const String& language, String& s) const
        {
            auto result = m_intLanguageData->searchString(id, language, s);

            return result;
        }

        IntLanguageDataAbstract::ErrorInfo IntLanguageManager::storeString(const String& id, const String& language, const String& s)
        {
            auto result = m_intLanguageData->storeString(id, language, s);

            return result;
        }

        IntLanguageDataAbstract::ErrorInfo IntLanguageManager::delString(const String& id, const String& language)
        {
            auto result = m_intLanguageData->delString(id, language);

            return result;
        }

        IntLanguageDataAbstract::ErrorInfo IntLanguageManager::getMap(IntLanguageDataAbstract::IntLanMap* intLanMap) const
        {
            auto result = m_intLanguageData->getMap(intLanMap);

            return result;
        }

        IntLanguageDataAbstract::ErrorInfo IntLanguageManager::getMap(const String& language, IntLanguageDataAbstract::LanStringMap* lanStringMap) const
        {
            auto result = m_intLanguageData->getMap(language, lanStringMap);

            return result;
        }

        bool IntLanguageManager::clearData()
        {
            auto result = m_intLanguageData->clearData();

            return result;
        }


    }
}

