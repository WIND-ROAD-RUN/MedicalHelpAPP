#include <COL_ConfigLoaderDatabaseXML.h>

namespace HiddenButNotExposed {
    namespace COL {

        ConfigLoaderDatabaseXML::ErrorInfo 
            ConfigLoaderDatabaseXML::addConfig(const String& name, const String& value)
        {
            if (!m_operatorDoc)return ErrorInfo::ERROR;
            for (auto tool : m_operatorDoc->child("ConfigLoaderString").children()) {
                if (tool.first_attribute().value() == name)return ErrorInfo::ADD_ERROR_NAME;
            }
            pugi::xml_node node = m_operatorDoc->child("ConfigLoaderString");
            node.append_child("String");
            node.last_child().append_attribute("id").set_value(name.c_str());
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
            if (!m_operatorDoc)return ErrorInfo::ERROR;
            for (pugi::xml_node& tool : m_operatorDoc->child("ConfigLoaderString")) {
                if (tool.first_attribute().value() == name) {
                    value = tool.text().get();
                    return ErrorInfo::SUCCESS;
                }
            }
            return ErrorInfo::SEARCH_ERROR_NAME;
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
            if (!m_operatorDoc)return ErrorInfo::ERROR;
            m_operatorDoc->child("ConfigLoaderString").remove_children();
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
