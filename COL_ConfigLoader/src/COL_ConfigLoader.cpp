#include<COL_ConfigLoader.h>

namespace HiddenButNotExposed {
    namespace COL {

        ConfigLoader* ConfigLoader::m_instance = nullptr;


        //==================================================================
        //          ConfigLoader_Database  FUNCTION RELIZE
        //==================================================================

        ConfigLoader_Database::ErrorInfo
            ConfigLoader_Database::addConfig
            (const String& name, const String& value) {

            auto addConfigResult = m_database->addConfig(name, value);
            if (addConfigResult != ErrorInfo::SUCCESS) {
                return addConfigResult;
            }
            //内存方法实现

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

            return ErrorInfo::SUCCESS;
        }

        ConfigLoader_Database::ErrorInfo
            ConfigLoader_Database::searchConfig
            (const String& name, String& value) const {

            //内存方法实现
            return ErrorInfo::SUCCESS;
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




    }//package
}//Company
