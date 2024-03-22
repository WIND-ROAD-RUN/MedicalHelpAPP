#pragma once

#ifndef ILS_INTLANGUAGECOMTEST_H_
#define ILS_INTLANGUAGECOMTEST_H_

#include "pch.h"


namespace HiddenButNotExposed {
    namespace ILS {

        const static IntLanguageCom::String DEFAULT_PATH = R"(.\database\dataFile.xml)";

        class IntLanguageComTest {
        private:
            IntLanguageCom* m_intLanguage{ nullptr };
        public:
            IntLanguageComTest() {
                m_intLanguage = new IntLanguageCom(DEFAULT_PATH);
            }
            ~IntLanguageComTest() { delete m_intLanguage; }
        public:
            IntLanguageCom* getTestObject() { return m_intLanguage; }

        };

    }
}


#endif // !ILS_INTLANGUAGECOMTEST_H_

