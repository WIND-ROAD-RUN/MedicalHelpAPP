#ifndef ILS_INTLANGUAGEMANAGER_H_
#define ILS_INTLANGUAGEMANAGER_H_

#include"ILS_IntLanguageDataAbstract.h"

namespace HiddenButNotExposed {
    namespace ILS {

        class IntLanguageManagerManager {
        public:
            using String = IntLanguageDataAbstract::String;

        private:
            IntLanguageManagerManager(IntLanguageDataAbstract* intLanguageDataAbstract)
                :m_intLanguageData(intLanguageDataAbstract) {}

        private:
            static IntLanguageManagerManager* m_instance;

        public:
            ~IntLanguageManagerManager() {}

            static IntLanguageManagerManager*
                getInstance(IntLanguageDataAbstract* intLanguageDataAbstract) {
                if (!m_instance) {
                    return new IntLanguageManagerManager(intLanguageDataAbstract);
                }

                return m_instance;
            }

        private:
            IntLanguageDataAbstract* m_intLanguageData{ nullptr };

        public:
            bool iniCom();

            bool desCom();

        public:

            IntLanguageDataAbstract::ErrorInfo searchString(const String& id, const String& language, String& s)const;

            IntLanguageDataAbstract::ErrorInfo storeString(const String& id, const String& language, const String& s);

            IntLanguageDataAbstract::ErrorInfo delString(const String& id, const String& language);

            IntLanguageDataAbstract::ErrorInfo getMap(IntLanguageDataAbstract::IntLanMap* intLanMap) const;

            IntLanguageDataAbstract::ErrorInfo getMap(const String& language, IntLanguageDataAbstract::LanStringMap* lanStringMap) const;
        
            bool clearData();
        };

    }
}




#endif // !ILS_INTLANGUAGEMANAGER_H_
