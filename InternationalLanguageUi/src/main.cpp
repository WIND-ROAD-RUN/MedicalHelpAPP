#include "InternationalLanguageUi.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InternationalLanguageUi w;
    w.show();
    return a.exec();
}
