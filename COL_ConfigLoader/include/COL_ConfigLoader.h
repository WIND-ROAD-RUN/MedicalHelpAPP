#ifndef COL_CONFIGLOADER_H_
#define COL_CONFIGLOADER_H_

#include<COL_ConfigLoaderUtility.h>
#include<COL_ConfigLoaderDatabaseAbstract.h>
#include<COL_ConfigLoaderDatabaseXML.h>

namespace HiddenButNotExposed {
    namespace COL {

        class ConfigLoader_Database {
        public:
            using ErrorInfo = ConfigLoaderDataUtility::ErrorInfo;

            using String = ConfigLoaderDataUtility::String;

        private:
            ConfigLoaderDatabaseAbstract* m_database{ nullptr };

            ConfigLoaderDatabaseAbstract::ConfigMap* m_configMap{ nullptr };

        public:
            ConfigLoader_Database(ConfigLoaderDatabaseAbstract * database=new ConfigLoaderDatabaseXML);

            ~ConfigLoader_Database();

        public:
             ErrorInfo iniCom();

             ErrorInfo desCom();

        public:
            ErrorInfo addConfig(const String& name, const String& value);

            ErrorInfo deleteConfig(const String& name, const String& value);

            ErrorInfo changeConfig(const String& name, const String& value);

            ErrorInfo searchConfig(const String& name, String& value) const;

            ErrorInfo saveData() ;

            ErrorInfo clearData();

        };


        class ConfigLoader {
        public:
            using ErrorInfo = ConfigLoaderDataUtility::ErrorInfo;
            using String = ConfigLoaderDataUtility::String;

        private:
            ConfigLoader(ConfigLoaderDatabaseAbstract* database = new ConfigLoaderDatabaseXML):
                m_databaseLoader(new ConfigLoader_Database(database)) {}

            static ConfigLoader* m_instance;

        public:
             static ConfigLoader* getInstance
             (ConfigLoaderDatabaseAbstract* database = new ConfigLoaderDatabaseXML);

            ~ConfigLoader() {}

        private:
            ConfigLoader_Database* m_databaseLoader{ nullptr };

        public:
             ErrorInfo iniCom();

             ErrorInfo desCom();

        public:
            ErrorInfo addConfig(const String& name, const String& value);

            ErrorInfo deleteConfig(const String& name, const String& value) ;

            ErrorInfo changeConfig(const String& name, const String& value) ;

            ErrorInfo searchConfig(const String& name, String& value) const ;

            ErrorInfo saveData() ;

            ErrorInfo clearData();

        };

      
//=================================================================================
//                      INLINE  FUNCTION DEFINITIONS
//=================================================================================
        

    }//package
}//Company

#endif // !COL_CONFIGLOADER_H_
