#include "InternationalLanguageManagerWindow.h"
#include <QtWidgets/QApplication>

using namespace HiddenButNotExposed::MDH;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InternationalLanguageManagerWindow w;
    w.show();
    return a.exec();
}
