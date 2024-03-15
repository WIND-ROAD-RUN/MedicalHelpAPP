#include "InternationalLanguageManagerWindow.h"

namespace HiddenButNotExposed {
    namespace MDH {
        InternationalLanguageManagerWindow::InternationalLanguageManagerWindow(QWidget* parent)
            : QMainWindow(parent)
            , ui(new Ui::InternationalLanguageManagerWindowClass())
        {
            ui->setupUi(this);

            build_ui();

            build_connect();

        }

        InternationalLanguageManagerWindow::~InternationalLanguageManagerWindow()
        {
            delete ui;
        }

        void InternationalLanguageManagerWindow::build_ui()
        {
            this->setWindowTitle("国际化语言字符串管理器");
        }

        void InternationalLanguageManagerWindow::build_connect()
        {

        }
    }//package

}// company


