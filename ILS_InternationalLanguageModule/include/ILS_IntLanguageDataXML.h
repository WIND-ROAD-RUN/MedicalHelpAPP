#ifndef ILS_INTLANGUAGEDATAXML_H_
#define ILS_INTLANGUAGEDATAXML_H_

#include<ILS_IntLanguageDataAbstract.h>

#include<ILS_IntLanguageUtility.h>

namespace pugi {
    class xml_document;
}

namespace HiddenButNotExposed {
    namespace ILS {

        class IntLanguageDataXML
            :public IntLanguageDataAbstract {
        public:
            IntLanguageDataXML(const String& filePath);
            IntLanguageDataXML() = default;

            ~IntLanguageDataXML();
        public:
            void setFilePath(const String& filePath);

        public:
            // ͨ通过IntLanguageDataAbstract 继承
            ErrorInfo iniCom() override;

            ErrorInfo desCom() override;

            ErrorInfo searchString(const String& id, const String& language, String& s)const override;

            ErrorInfo storeString(const String& id, const String& language, const String& s) override;

            ErrorInfo changeString(const String& id, const String& language, const String& s) override;

            ErrorInfo delString(const String& id, const String& language) override;

            ErrorInfo getMap(IntLanMap* &intLanMap)const override;

            ErrorInfo getMap(const String& language, LanStringMap* &lanStringMap)const override;

            ErrorInfo clearData() override;

        private:
            pugi::xml_document* m_operatorDoc{ nullptr };

            String m_filePath{};

        };


        inline void IntLanguageDataXML::setFilePath(const IntLanguageDataAbstract::String& filePath) {
            m_filePath = filePath;
        }

    } // package
} //company






#endif // !ILS_INTLANGUAGEDATAXML_H_

