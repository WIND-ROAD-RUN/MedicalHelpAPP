#ifndef ILS_INTLANGUAGE_H_
#define ILS_INTLANGUAGE_H_

#include<ILS_IntLanguageDataAbstract.h>

#include<ILS_IntLanguageUtility.h>

namespace HiddenButNotExposed {
    namespace ILS {


        class IntLanguage_Database
            :public IntLanguageDataAbstract {
        private:
            IntLanguageDataAbstract* m_intLanData{ nullptr };

        private:
            IntLanMap* m_intLanMap{ nullptr };

        public:
            IntLanguage_Database(IntLanguageDataAbstract* intLanguageData);
            IntLanguage_Database() = default;

            ~IntLanguage_Database();
        public:
            void setLanguageData(IntLanguageDataAbstract* intLanData);

        public:
            // 通过 IntLanguageDataAbstract 继承
            ErrorInfo iniCom() override;

            ErrorInfo desCom() override;

            ErrorInfo searchString(const String& id, const String& language, String& s) const override;

            ErrorInfo storeString(const String& id, const String& language, const String& s) override;

            ErrorInfo changeString(const String& id, const String& language, const String& s) override;

            ErrorInfo delString(const String& id, const String& language) override;

            ErrorInfo getMap(IntLanMap* intLanMap) const override;

            ErrorInfo getMap(const String& language, LanStringMap* lanStringMap) const override;

            ErrorInfo clearData() override;

        };

    } //Packages 


} //Company







#endif // !ILS_INTLANGUAGE_H_
