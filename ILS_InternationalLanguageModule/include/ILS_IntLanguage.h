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


        class IntLanguageCom {
        public:
            using String = IntLanguageDataAbstract::String;

        private:
            IntLanguageCom(IntLanguageDataAbstract* intLanguageDataAbstract)
                :m_intLanguageData(intLanguageDataAbstract) {}

        private:
            static IntLanguageCom* m_instance;

        public:
            ~IntLanguageCom() {}

            static IntLanguageCom*
                getInstance(IntLanguageDataAbstract* intLanguageDataAbstract) {
                if (!m_instance) {
                    return new IntLanguageCom(intLanguageDataAbstract);
                }

                return m_instance;
            }

        private:
            IntLanguageDataAbstract* m_intLanguageData{ nullptr };

        public:
            bool iniCom();

            bool desCom();

        public:
            IntLanguageDataAbstract::ErrorInfo searchString(const String& id, const String& language, String& s);

        };


        class IntLanguageManager {
        public:
            using String = IntLanguageDataAbstract::String;

        private:
            IntLanguageManager(IntLanguageDataAbstract* intLanguageDataAbstract)
                :m_intLanguageData(intLanguageDataAbstract) {}

        private:
            static IntLanguageManager* m_instance;

        public:
            ~IntLanguageManager() {}

            static IntLanguageManager*
                getInstance(IntLanguageDataAbstract* intLanguageDataAbstract) {
                if (!m_instance) {
                    return new IntLanguageManager(intLanguageDataAbstract);
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

    } //Packages 


} //Company







#endif // !ILS_INTLANGUAGE_H_
