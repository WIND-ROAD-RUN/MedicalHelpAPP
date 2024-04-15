#include "InternationalLanguageUi.h"

InternationalLanguageUi::InternationalLanguageUi(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

InternationalLanguageUi::~InternationalLanguageUi()
{}

void InternationalLanguageUi::pushButton_5_Clicked()
{
    ui.stackedWidget_2->setCurrentIndex(0);
}

void InternationalLanguageUi::pushButton_Clicked()
{
    ui.stackedWidget_2->setCurrentIndex(1);
}

void InternationalLanguageUi::pushButton_2_Clicked()
{
    ui.stackedWidget_2->setCurrentIndex(2);
}

void InternationalLanguageUi::pushButton_3_Clicked()
{
    ui.stackedWidget_2->setCurrentIndex(3);
}

void InternationalLanguageUi::pushButton_4_Clicked()
{
    ui.stackedWidget->setCurrentIndex(0);
}

void InternationalLanguageUi::pushButton_7_Clicked()
{
    ui.stackedWidget->setCurrentIndex(1);
}