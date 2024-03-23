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
            ConfigLoader_Database();

            ~ConfigLoader_Database();

            friend class ConfigLoader;
  
        private:
            ConfigLoaderDatabaseAbstract* m_database{ nullptr };

            ConfigLoaderDatabaseAbstract::ConfigMap* m_configMap{nullptr};

        public:
            inline ErrorInfo iniCom();

            inline ErrorInfo desCom();

        public:
            ErrorInfo addConfig(const String& name, const String& value);

            ErrorInfo deleteConfig(const String& name, const String& value);

            ErrorInfo changeConfig(const String& name, const String& value);

            ErrorInfo searchConfig(const String& name, String& value) const;

        };


        class ConfigLoader {
        public:
            using ErrorInfo = ConfigLoaderDataUtility::ErrorInfo;
            using String = ConfigLoaderDataUtility::String;

        private:
            ConfigLoader() {}

            static ConfigLoader* m_instance;

        public:
            inline static ConfigLoader* getInstance();

            ~ConfigLoader() {}

        private:
            ConfigLoader_Database* m_databaseLoader{ nullptr };

        public:
            inline ErrorInfo iniCom();

            inline ErrorInfo desCom();

        public:
            ErrorInfo addConfig(const String& name, const String& value);

            ErrorInfo deleteConfig(const String& name, const String& value) ;

            ErrorInfo changeConfig(const String& name, const String& value) ;

            ErrorInfo searchConfig(const String& name, String& value) const ;

        };

      
//=================================================================================
//                      INLINE  FUNCTION DEFINITIONS
//=================================================================================
        ConfigLoader_Database::ErrorInfo 
            ConfigLoader_Database::iniCom() {
            if (!m_database) {
                m_database = new ConfigLoaderDatabaseXML();
            }

            auto iniDatabaseResult = m_database->iniCom();
            if (iniDatabaseResult != ErrorInfo::SUCCESS) {
                return iniDatabaseResult;
            }

            auto iniConfigMapResult = m_database->getConfigMap(m_configMap);
            if (iniConfigMapResult!=ErrorInfo::SUCCESS) {
                return iniConfigMapResult;
            }

            return ErrorInfo::SUCCESS;
        }

        ConfigLoader_Database::ErrorInfo
            ConfigLoader_Database::desCom() {
            auto desDatabaseResult = m_database->desCom();
            if (desDatabaseResult != ErrorInfo::SUCCESS) {
                return desDatabaseResult;
            }

            if (m_configMap) {
                delete m_configMap;
            }

            if (m_database) {
                delete m_database;
            }
          
            return ErrorInfo::SUCCESS;
        }

        ConfigLoader::ErrorInfo
            ConfigLoader::iniCom() {
            if (!m_databaseLoader) {
                m_databaseLoader = new ConfigLoader_Database();
            }

            auto iniDatabaseLoaderResult = m_databaseLoader->iniCom();
            if (iniDatabaseLoaderResult!=ErrorInfo::SUCCESS) {
                return iniDatabaseLoaderResult;
            }

            return ErrorInfo::SUCCESS;
        }

        ConfigLoader::ErrorInfo
            ConfigLoader::desCom() {

            auto desDatabaseLoaderResult = m_databaseLoader->desCom();
            if (desDatabaseLoaderResult != ErrorInfo::SUCCESS) {
                return desDatabaseLoaderResult;
            }

            if (m_databaseLoader) {
                delete m_databaseLoader;
            }

            return ErrorInfo::SUCCESS;
        }


        ConfigLoader* ConfigLoader::getInstance() {
            if (!m_instance) {
                m_instance = new ConfigLoader();
            }
            return m_instance;
        }

    }//package
}//Company

#endif // !COL_CONFIGLOADER_H_
