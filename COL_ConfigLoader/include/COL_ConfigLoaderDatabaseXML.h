#ifndef COL_CONFIGLOADERDATABASEXML_H_
#define COL_CONFIGLOADERDATABASEXML_H_

#include<COL_ConfigLoaderDatabaseAbstract.h>
#include<COL_ConfigLoaderUtility.h>

namespace HiddenButNotExposed {
    namespace COL {

        class ConfigLoaderDatabaseXML
            :public ConfigLoaderDatabaseAbstract{
        public:
            ConfigLoaderDatabaseXML(const String & filePath="");
            ~ConfigLoaderDatabaseXML();

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

        };
        
    }//package
}//Company


#endif // !COL_CONFIGLOADERDATABASEXML_H_
