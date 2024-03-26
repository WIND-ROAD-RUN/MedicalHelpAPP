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
            if (!m_operatorDoc)return ErrorInfo::ERROR;
            for (auto tool : m_operatorDoc->child("ConfigLoaderString").children()) {
                if (tool.first_attribute().value() == name)return ErrorInfo::ADD_ERROR_NAME;
            }
            pugi::xml_node node = m_operatorDoc->child("ConfigLoaderString");
            node.append_child("String");
            node.last_child().append_attribute(name.c_str());
            node.last_child().text().set(value.c_str());
            return ErrorInfo::SUCCESS;
        }

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::deleteConfig(const String& name, const String& value)
        {
            if (!m_operatorDoc)return ErrorInfo::ERROR;
            for (auto& tool : m_operatorDoc->child("ConfigLoaderString").children()) {
                if (tool.first_attribute().value() == name) {
                    if (tool.text().get() == value) {
                        m_operatorDoc->child("ConfigLoaderString").remove_child(tool);
                        return ErrorInfo::SUCCESS;
                    }
                    return ErrorInfo::DELETE_ERROR_VALUE;
                }
            }
            return ErrorInfo::DELETE_ERROR_NAME;
        }

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::changeConfig(const String& name, const String& value)
        {
            if (!m_operatorDoc)return ErrorInfo::ERROR;
            for (auto& tool : m_operatorDoc->child("ConfigLoaderString").children()) {
                if (tool.first_attribute().value() == name) {
                    tool.text().set(value.c_str());
                    return ErrorInfo::SUCCESS;
                }
            }
            return ErrorInfo::CHANGE_ERROR_NAME;
        }

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::searchConfig(const String& name, String& value) const
        {
            
        }

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::getConfigMap(ConfigMap* map)
        {
            if (map == NULL)map = new ConfigMap;
            map->clear();
            if (!m_operatorDoc)return ErrorInfo::ERROR;
            for (auto tool : m_operatorDoc->child("ConfigLoaderString").children()) {
                (*map)[tool.first_attribute().value()] = tool.text().get();
            }
            return ErrorInfo::SUCCESS;
        }

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::clearData()
        {
            return ErrorInfo();
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
