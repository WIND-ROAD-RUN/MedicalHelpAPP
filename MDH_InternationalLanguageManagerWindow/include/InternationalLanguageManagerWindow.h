#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_InternationalLanguageManagerWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InternationalLanguageManagerWindowClass; };
QT_END_NAMESPACE

class InternationalLanguageManagerWindow : public QMainWindow
{
    Q_OBJECT

public:
    InternationalLanguageManagerWindow(QWidget *parent = nullptr);
    ~InternationalLanguageManagerWindow();

private:
    Ui::InternationalLanguageManagerWindowClass *ui;
};