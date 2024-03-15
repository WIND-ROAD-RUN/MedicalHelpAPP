#include<iostream>

#include"ILS_IntLanguageDataAbstract.h"
#include"ILS_IntLanguageDataXML.h"

using namespace std;
using namespace HiddenButNotExposed::ILS;


int main() {
    IntLanguageDataXML a;
    a.setFilePath(R"(E:\code_place\vs_place\MedicalHelpApp\ILS_InternationalLanguageModule\database\dataFile.xml)");
    auto result = a.iniCom();
    string s;
    a.searchString("1","qw",s);
    cout << s;

    a.desCom();

    return 0;
}