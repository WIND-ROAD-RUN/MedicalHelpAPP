#include<COL_ConfigLoader.h>

namespace HiddenButNotExposed {
    namespace COL {

        ConfigLoader* ConfigLoader::m_instance = nullptr;


        //==================================================================
        //          ConfigLoader_Database  FUNCTION RELIZE
        //==================================================================

        ConfigLoader_Database::ConfigLoader_Database
        (ConfigLoaderDatabaseAbstract* database):m_database(database) {}
        ConfigLoader_Database::~ConfigLoader_Database() {}

        ConfigLoader_Database::ErrorInfo
            ConfigLoader_Database::addConfig
            (const String& name, const String& value) {

            auto addConfigResult = m_database->addConfig(name, value);
            if (addConfigResult != ErrorInfo::SUCCESS) {
                return addConfigResult;
            }
            //内存方法实现
            if (m_configMap->find(name) != m_configMap->end())return ErrorInfo::ADD_ERROR_NAME;
            (*m_configMap)[name] = value;
            return ErrorInfo::SUCCESS;
        }

        ConfigLoader_Database::ErrorInfo
            ConfigLoader_Database::deleteConfig
            (const String& name, const String& value) {

            auto addConfigResult = m_database->deleteConfig(name, value);
            if (addConfigResult != ErrorInfo::SUCCESS) {
                return addConfigResult;
            }
            //内存方法实现
            if (m_configMap->find(name) == m_configMap->end())return ErrorInfo::DELETE_ERROR_NAME;
            if ((*m_configMap)[name] != value)return ErrorInfo::DELETE_ERROR_VALUE;
            (*m_configMap).erase(name);

            return ErrorInfo::SUCCESS;
        }

        ConfigLoader_Database::ErrorInfo
            ConfigLoader_Database::changeConfig
            (const String& name, const String& value) {

            auto addConfigResult = m_database->changeConfig(name, value);
            if (addConfigResult != ErrorInfo::SUCCESS) {
                return addConfigResult;
            }
            //内存方法实现
            if (m_configMap->find(name) == m_configMap->end())return ErrorInfo::CHANGE_ERROR_NAME;
            (*m_configMap)[name] = value;

            return ErrorInfo::SUCCESS;
        }

        ConfigLoader_Database::ErrorInfo
            ConfigLoader_Database::searchConfig
            (const String& name, String& value) const {

            //内存方法实现
            if (m_configMap->find(name) == m_configMap->end())return ErrorInfo::SEARCH_ERROR_NAME;
            value = (*m_configMap)[name];
            return ErrorInfo::SUCCESS;
        }

        ConfigLoader_Database::ErrorInfo 
            ConfigLoader_Database::clearData() {
            auto clearDataResult = m_database->clearData();
            if (clearDataResult != ErrorInfo::SUCCESS) {
                return clearDataResult;
            }
            //内存实现
            m_configMap->clear();
            return ErrorInfo::SUCCESS;
        }

        ConfigLoader_Database::ErrorInfo ConfigLoader_Database::saveData() {
            auto saveDataResult = m_database->saveData();
            return saveDataResult;
        }

        //==================================================================
        //          ConfigLoader FUNCTION RELIZE
        //==================================================================

        ConfigLoader::ErrorInfo 
            ConfigLoader::addConfig
            (const String& name, const String& value) {

            auto addConfigResult = m_databaseLoader->addConfig(name, value);

            return addConfigResult;
        }

        ConfigLoader::ErrorInfo 
            ConfigLoader::deleteConfig
            (const String& name, const String& value) {

            auto deleteConfigResult = m_databaseLoader->deleteConfig(name, value);

            return deleteConfigResult;
        }

        ConfigLoader::ErrorInfo 
            ConfigLoader::changeConfig
            (const String& name, const String& value) {

            auto changeConfigResult = m_databaseLoader->changeConfig(name, value);

            return changeConfigResult;
        }

        ConfigLoader::ErrorInfo 
            ConfigLoader::searchConfig
            (const String& name, String& value) const {

            auto searchConfigResult = m_databaseLoader->searchConfig(name, value);

            return searchConfigResult;
        }

        ConfigLoader::ErrorInfo
            ConfigLoader::clearData() {
            auto clearDataResult = m_databaseLoader->clearData();
            return clearDataResult;
        }

        ConfigLoader::ErrorInfo 
            ConfigLoader::saveData() {
            auto saveDataResult = m_databaseLoader->saveData();
            return saveDataResult;
        }



        ConfigLoader_Database::ErrorInfo
            ConfigLoader_Database::iniCom() {
            if (!m_database) {
                m_database = new ConfigLoaderDatabaseXML();
            }

            if (!m_configMap)m_configMap = new ConfigLoaderDatabaseAbstract::ConfigMap;

            auto iniDatabaseResult = m_database->iniCom();
            if (iniDatabaseResult != ErrorInfo::SUCCESS) {
                return iniDatabaseResult;
            }

            auto iniConfigMapResult = m_database->getConfigMap(m_configMap);
            if (iniConfigMapResult != ErrorInfo::SUCCESS) {
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
            if (iniDatabaseLoaderResult != ErrorInfo::SUCCESS) {
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


        ConfigLoader* ConfigLoader::getInstance(ConfigLoaderDatabaseAbstract* database ) {
            if (!m_instance) {
                m_instance = new ConfigLoader(database);
            }

            return m_instance;
        }

    }//package
}//Company
