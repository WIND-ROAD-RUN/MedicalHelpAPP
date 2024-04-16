#pragma once

#include <QtWidgets/QWidget>
#include "ui_InternationalLanguageUi.h"
#include "ILS_IntLanguage.h";

class InternationalLanguageUi : public QWidget
{
    Q_OBJECT

public:
    InternationalLanguageUi(QWidget *parent = nullptr);
    ~InternationalLanguageUi();

public:
    const HiddenButNotExposed::ILS::IntLanguageDataAbstract::String DEFAULT_PATH;
    HiddenButNotExposed::ILS::IntLanguageManager* tool;

private:
    Ui::InternationalLanguageUiClass ui;

private slots:
    void pushButton_5_Clicked();
    void pushButton_Clicked();
    void pushButton_2_Clicked();
    void pushButton_3_Clicked();
    void pushButton_4_Clicked();
    void pushButton_7_Clicked();
};
