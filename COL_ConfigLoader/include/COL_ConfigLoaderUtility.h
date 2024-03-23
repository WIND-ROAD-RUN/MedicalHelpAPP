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
