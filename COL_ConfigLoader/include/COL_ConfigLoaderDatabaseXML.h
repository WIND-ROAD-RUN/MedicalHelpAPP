#ifndef COL_CONFIGLOADERDATABASEXML_H_
#define COL_CONFIGLOADERDATABASEXML_H_

#include<COL_ConfigLoaderDatabaseAbstract.h>
#include<COL_ConfigLoaderUtility.h>
#include<pugixml.hpp>

namespace HiddenButNotExposed {
    namespace COL {

        class ConfigLoaderDatabaseXML
            :public ConfigLoaderDatabaseAbstract{
        public:
            ConfigLoaderDatabaseXML(const String& filePath = "") :m_filePath(filePath) {};
            ~ConfigLoaderDatabaseXML() {};

        public:
            // 通过 ConfigLoaderDatabaseAbstract 继承
            inline ErrorInfo iniCom() override;

            inline ErrorInfo desCom() override;

            ErrorInfo addConfig(const String& name, const String& value) override;

            ErrorInfo deleteConfig(const String& name, const String& value) override;

            ErrorInfo changeConfig(const String& name, const String& value) override;

            ErrorInfo searchConfig(const String& name, String& value) const override;

            ErrorInfo getConfigMap(ConfigMap* map) override;

            ErrorInfo clearData() override;

            ErrorInfo saveData() override;

        private:
            pugi::xml_document* m_operatorDoc{nullptr};
            String m_filePath;

        };
        
//=================================================================================
//                      INLINE  FUNCTION DEFINITIONS
//=================================================================================

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
            return ErrorInfo::SUCCESS;
        }


    }//package
}//Company


#endif // !COL_CONFIGLOADERDATABASEXML_H_
