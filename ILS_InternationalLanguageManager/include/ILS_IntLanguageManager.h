#ifndef ILS_INTLANGUAGEMANAGER_H_
#define ILS_INTLANGUAGEMANAGER_H_

#include"ILS_IntLanguageDataAbstract.h"

class IntLanguageManagerManager {
private:
    IntLanguageManagerManager() {}
private:
    static IntLanguageManagerManager* m_instance;
public:
    ~IntLanguageManagerManager() {}

    static IntLanguageManagerManager*
        getInstance() {
        if (!m_instance) {
            return new IntLanguageManagerManager();
        }
    }
private:
    
};


#endif // !ILS_INTLANGUAGEMANAGER_H_
