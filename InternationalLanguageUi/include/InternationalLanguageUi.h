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

private:
    Ui::InternationalLanguageUiClass ui;
};
