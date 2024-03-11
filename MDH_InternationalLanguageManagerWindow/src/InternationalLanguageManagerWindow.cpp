#include "InternationalLanguageManagerWindow.h"

InternationalLanguageManagerWindow::InternationalLanguageManagerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InternationalLanguageManagerWindowClass())
{
    ui->setupUi(this);
}

InternationalLanguageManagerWindow::~InternationalLanguageManagerWindow()
{
    delete ui;
}
