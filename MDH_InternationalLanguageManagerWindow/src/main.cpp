#include "InternationalLanguageManagerWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InternationalLanguageManagerWindow w;
    w.show();
    return a.exec();
}
