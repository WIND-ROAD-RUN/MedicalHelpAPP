#ifndef ILS_INTLANGUAGEDATA_H_
#define ILS_INTLANGUAGEDATA_H_

#include<string>
#include<vector>
#include<map>

namespace HiddenButNotExposed {
    namespace ILS {
        struct IntLanguageData
        {
            enum ErrorInfo {
                INI_ERROR,
                DES_ERROR,
                SEARCH_STRING_ERROR_ID,
                SEARCH_STRING_ERROR_LANGUAGE,
                STORE_STRING_ERROR_ID,
                STORE_STRING_ERROR_LANGUAGE,
                CHANGE_STRING_ERROR_ID,
                CHANGE_STRING_ERROR_LANGUAGE,
                DEL_STRING_ERROR_ID,
                DEL_STRING_ERROR_LANGUAGE,
                GET_MAP_ERROR,
                GET_MAP_ERROR_LANGUAGE,
                CLEAR_ERROR,
                ERROR,
                SUCCESS
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
}//company

#endif // !ILS_INTLANGUAGEDATA_H_
