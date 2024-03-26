#include "COL_ConfigLoaderDatabaseXML.h"


namespace HiddenButNotExposed {
    namespace COL {
        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::iniCom()
        {
            if (m_filePath.empty())return ErrorInfo::INI_ERROR;
            if (!m_operatorDoc)m_operatorDoc = new pugi::xml_document;
            auto result = m_operatorDoc->load_file(m_filePath.c_str());
            if (!result)return ErrorInfo::INI_ERROR;
            if (m_operatorDoc->child("ConfigLoaderString") == NULL)
                m_operatorDoc->append_child("ConfigLoaderString");
            return ErrorInfo::SUCCESS;
        }

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::desCom()
        {
            m_filePath.clear();
            if (m_operatorDoc)delete m_operatorDoc;
            return ErrorInfo();
        }

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::addConfig(const String& name, const String& value)
        {

            return ErrorInfo();
        }

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::deleteConfig(const String& name, const String& value)
        {
            return ErrorInfo();
        }

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::changeConfig(const String& name, const String& value)
        {



            return ErrorInfo();
        }

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::searchConfig(const String& name, String& value) const
        {
            for (pugi::xml_node& tool : m_operatorDoc->child("ConfigLoaderString")) {
                if (tool.first_attribute().value() == name) {
                    for (pugi::xml_node& tools : tool.child("country").children()) {
                        if (tools.first_attribute().value() == value) {
                            return ErrorInfo::SUCCESS;
                        }
                    }
                    return ErrorInfo::SEARCH_ERROR_VALUE;
                }
            }
            return ErrorInfo::SEARCH_ERROR_NAME;
        }

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::getConfigMap(ConfigMap* map)
        {
            return ErrorInfo();
        }

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::clearData()
        {
            m_operatorDoc->remove_children();
            return ErrorInfo::CLEAR_ERROR;
        }

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::saveData()
        {
            if (!m_operatorDoc)return ErrorInfo::SAVE_ERROR;
            if (m_filePath == "")return ErrorInfo::SAVE_ERROR;
            m_operatorDoc->save_file(m_filePath.c_str());
            return ErrorInfo::SUCCESS;
        }

    }//package
}//Company
