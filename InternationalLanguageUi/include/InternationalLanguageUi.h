#pragma once

#include <QtWidgets/QWidget>
#include "ui_InternationalLanguageUi.h"
#include "ILS_IntLanguage.h"
#include "ILS_IntLanguageDataXML.h"
#include "ILS_IntLanguageDataAbstract.h"
#include "ILS_IntlanguageUtility.h"

class InternationalLanguageUi : public QWidget
{
    Q_OBJECT

public:
    InternationalLanguageUi(QWidget *parent = nullptr);
    ~InternationalLanguageUi();

public:
    HiddenButNotExposed::ILS::IntLanguageDataAbstract::String DEFAULT_PATH;
    HiddenButNotExposed::ILS::IntLanguageManager* tool{ nullptr };
    HiddenButNotExposed::ILS::IntLanguageDataAbstract::IntLanMap* intLanMap{ nullptr };
    HiddenButNotExposed::ILS::IntLanguageDataAbstract::LanStringMap* intLanStringMap{ nullptr };

private:
    Ui::InternationalLanguageUiClass ui;
    void initTree1();
    void initTree2();

private slots:
    void pushButton_Clicked();
    void pushButton_2_Clicked();
    void pushButton_3_Clicked();
    void pushButton_4_Clicked();
    void pushButton_5_Clicked();
    void pushButton_6_Clicked();
    void pushButton_7_Clicked();
    void pushButton_8_Clicked();
    void pushButton_9_Clicked();
    void pushButton_10_Clicked();
    void pushButton_11_Clicked();
    void pushButton_12_Clicked();
};
