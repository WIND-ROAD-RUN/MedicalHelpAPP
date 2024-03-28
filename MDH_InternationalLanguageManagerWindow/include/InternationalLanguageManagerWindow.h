#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_InternationalLanguageManagerWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InternationalLanguageManagerWindowClass; };
QT_END_NAMESPACE

namespace HiddenButNotExposed {
    namespace MDH {
        class InternationalLanguageManagerWindow : public QMainWindow
        {
            Q_OBJECT

        public:
            InternationalLanguageManagerWindow(QWidget* parent = nullptr);

            ~InternationalLanguageManagerWindow();

        public:
            void ini_UI();
            void build_ui();

            void build_connect();

        private:
            Ui::InternationalLanguageManagerWindowClass* ui;

        public slots:
            void pbtn_openFile_clicked();

        };


    }//package

}// company


