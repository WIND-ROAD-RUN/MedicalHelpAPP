#ifndef COL_CONFIGLOADERUTILITY_H_
#define COL_CONFIGLOADERUTILITY_H_
#include<string>
#include<vector>
#include<map>

namespace HiddenButNotExposed {
    namespace COL {

        struct ConfigLoaderDataUtility
        {
            enum ErrorInfo {
                INI_ERROR,
                DES_ERROR,
                SEARCH_ERROR_NAME,
                SEARCH_ERROR_VALUE,
                ADD_ERROR_NAME,
                ADD_ERROR_VALUE,
                DELETE_ERROR_NAME,
                DELETE_ERROR_VALUE,
                CHANGE_ERROR_NAME,
                CHANGE_ERROR_VALUE,
                GET_CONFIGMAP_ERROR,
                CLEAR_ERROR,
                SAVE_ERROR,
                ERROR,
                SUCCESS,
            };

            using String = std::string;

            template<typename T>
            using Vector = std::vector<T>;

            template<typename T1, typename T2>
            using Map = std::map<T1, T2>;

            template<typename T1, typename T2>
            using Pair = std::pair<T1, T2>;


        };





    }//package
}//Company


#endif // !COL_CONFIGLOADERUTILITY_H_
