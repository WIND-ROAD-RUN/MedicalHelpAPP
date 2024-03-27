#ifndef COL_CONFIGLOADERDATABASEXML_H_
#define COL_CONFIGLOADERDATABASEXML_H_

#include<COL_ConfigLoaderDatabaseAbstract.h>
#include<COL_ConfigLoaderUtility.h>

namespace pugi {
    class xml_document;
}

namespace HiddenButNotExposed {
    namespace COL {

        class ConfigLoaderDatabaseXML
            :public ConfigLoaderDatabaseAbstract{
        public:
            ConfigLoaderDatabaseXML(const String& filePath) :m_filePath(filePath) {};
            ConfigLoaderDatabaseXML()=default;
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
        public:
            inline void setFilePath(const String & filePath);

        private:
            pugi::xml_document* m_operatorDoc{nullptr};
            String m_filePath{};

        };
        
//=================================================================================
//                      INLINE  FUNCTION DEFINITIONS
//=================================================================================

        
    }//package
}//Company


#endif // !COL_CONFIGLOADERDATABASEXML_H_
