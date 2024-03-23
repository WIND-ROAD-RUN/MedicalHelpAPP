#include "ILS_IntLanguage.h"
#include"ILS_IntLanguageDataXML.h"

namespace HiddenButNotExposed {
    namespace ILS {

        IntLanguage::IntLanguage
        (IntLanguageDataAbstract* intLanguageData)
            :m_intLanData(intLanguageData)
        {
            if (m_intLanMap)delete m_intLanMap;
            m_intLanMap = new IntLanMap;
        }

        IntLanguage::~IntLanguage()
        {
            if (m_intLanMap)delete m_intLanMap;
        }

        void IntLanguage::setLanguageData(IntLanguageDataAbstract* intLanData)
        {
            if (m_intLanData) {
                delete m_intLanData;
            }
            //if (!intLanData)intLanData = new IntLanguageDataXML;
            m_intLanData = intLanData;
        }

        IntLanguageDataAbstract::ErrorInfo
            IntLanguage::iniCom()
        {
            auto iniResult = m_intLanData->iniCom();
            if (iniResult != ErrorInfo::SUCCESS) {
                return iniResult;
            }

            auto getIntLanMapResult = m_intLanData->getMap(m_intLanMap);
            if (getIntLanMapResult != ErrorInfo::SUCCESS) {
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
            IntLanguage::searchString(const String& id, const String& language, String& s)const
        {
            if (m_intLanMap->find(id) != m_intLanMap->end()) {
                if ((*m_intLanMap)[id].find(language) != (*m_intLanMap)[id].end()) {
                    s = (*m_intLanMap)[id][language];
                    return ErrorInfo::SUCCESS;
                }
                return ErrorInfo::SEARCH_STRING_ERROR_LANGUAGE;
            }
            m_intLanData->searchString(id, language, s);
            return ErrorInfo::SEARCH_STRING_ERROR_ID;
        }

        IntLanguageDataAbstract::ErrorInfo
            IntLanguage::storeString(const String& id, const String& language, const String& s)
        {
            if (m_intLanMap->find(id) != m_intLanMap->end()) {
                if ((*m_intLanMap)[id].find(language) != (*m_intLanMap)[id].end()) {
                    if ((*m_intLanMap)[id][language] == s)return ErrorInfo::SUCCESS;
                    else return ErrorInfo::STORE_STRING_ERROR_LANGUAGE;
                }
            }
            (*m_intLanMap)[id][language] = s;
            m_intLanData->storeString(id, language, s);
            return ErrorInfo::SUCCESS;
        }

        IntLanguageDataAbstract::ErrorInfo
            IntLanguage::changeString(const String& id, const String& language, const String& s)
        {
            if (m_intLanMap->find(id) != m_intLanMap->end()) {
                if ((*m_intLanMap)[id].find(language) != (*m_intLanMap)[id].end()) {
                    (*m_intLanMap)[id][language] = s;
                    return ErrorInfo::SUCCESS;
                }
                return ErrorInfo::CHANGE_STRING_ERROR_LANGUAGE;
            }
            m_intLanData->changeString(id, language, s);
            return ErrorInfo::CHANGE_STRING_ERROR_ID;
        }

        IntLanguageDataAbstract::ErrorInfo
            IntLanguage::delString(const String& id, const String& language)
        {
            if (m_intLanMap->find(id) != m_intLanMap->end()) {
                if ((*m_intLanMap)[id].find(language) != (*m_intLanMap)[id].end()) {
                    (*m_intLanMap)[id].erase(language);
                    return ErrorInfo::SUCCESS;
                }
                return ErrorInfo::DEL_STRING_ERROR_LANGUAGE;
            }
            m_intLanData->delString(id, language);
            return ErrorInfo::DEL_STRING_ERROR_ID;
        }

        IntLanguageDataAbstract::ErrorInfo
            IntLanguage::getMap(IntLanMap* intLanMap) const
        {
            if (!intLanMap)intLanMap = new IntLanMap;
            intLanMap->clear();
            *intLanMap = *m_intLanMap;
            m_intLanData->getMap(intLanMap);
            return ErrorInfo::SUCCESS;
        }

        IntLanguageDataAbstract::ErrorInfo
            IntLanguage::getMap(const String& language, LanStringMap* lanStringMap) const
        {
            if (!lanStringMap)lanStringMap = new LanStringMap;
            if (!m_intLanMap)return ErrorInfo::GET_MAP_ERROR;
            lanStringMap->clear();
            for (IntLanMap::iterator it = m_intLanMap->begin(); it != m_intLanMap->end(); ++it) {
                for (auto i : it->second) {
                    if (i.first == language)(*lanStringMap)[(*it).first] = i.second;
                }
            }
            if (lanStringMap->empty())return ErrorInfo::GET_MAP_ERROR_LANGUAGE;
            return ErrorInfo::SUCCESS;
        }

        IntLanguageDataAbstract::ErrorInfo
            IntLanguage::clearData()
        {
            m_intLanMap->clear();
            m_intLanData->clearData();
            return ErrorInfo::SUCCESS;
        }


    }//package
}//company

