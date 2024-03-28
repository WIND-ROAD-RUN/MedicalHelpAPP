#include "InternationalLanguageManagerWindow.h"
#include<QMessageBox>

namespace HiddenButNotExposed {
    namespace MDH {
        InternationalLanguageManagerWindow::InternationalLanguageManagerWindow(QWidget* parent)
            : QMainWindow(parent)
            , ui(new Ui::InternationalLanguageManagerWindowClass())
        {
            ui->setupUi(this);

            ini_UI();

        }

        InternationalLanguageManagerWindow::~InternationalLanguageManagerWindow()
        {
            delete ui;
        }

        void InternationalLanguageManagerWindow::ini_UI()
        {
            build_ui();

            build_connect();
        }

        void InternationalLanguageManagerWindow::build_ui()
        {
            this->setWindowTitle("国际化语言字符串管理器");
        }

        void InternationalLanguageManagerWindow::build_connect()
        {
            QObject::connect(ui->pbtn_openFile,&QPushButton::clicked,
                this,&InternationalLanguageManagerWindow::pbtn_openFile_clicked);
        }

        void InternationalLanguageManagerWindow::pbtn_openFile_clicked() {
       
        }
    }//package

}// company


