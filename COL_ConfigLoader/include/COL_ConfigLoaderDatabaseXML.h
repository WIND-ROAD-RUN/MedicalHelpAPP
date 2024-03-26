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
            ErrorInfo iniCom() override;

            ErrorInfo desCom() override;

            ErrorInfo addConfig(const String& name, const String& value) override;

            ErrorInfo deleteConfig(const String& name, const String& value) override;

            ErrorInfo changeConfig(const String& name, const String& value) override;

            ErrorInfo searchConfig(const String& name, String& value) const override;

            ErrorInfo getConfigMap(ConfigMap* map) override;

            ErrorInfo clearData() override;

            ErrorInfo saveData() override;

        private:
            pugi::xml_document* m_operatorDoc;
            String m_filePath;

        };
        
    }//package
}//Company


#endif // !COL_CONFIGLOADERDATABASEXML_H_
