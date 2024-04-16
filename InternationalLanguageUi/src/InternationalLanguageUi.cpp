#include "InternationalLanguageUi.h"
#include "ILS_IntLanguage.h"
#include "ILS_IntLanguageDataXML.h"
#include "ILS_IntLanguageDataAbstract.h"
#include "ILS_IntlanguageUtility.h"
#include "QDir.h"
#include "QWidget.h"
#include "QTreeWidget.h"

InternationalLanguageUi::InternationalLanguageUi(QWidget *parent)
    : QWidget(parent)
{
    DEFAULT_PATH = R"(C:\Users\86158\Desktop\Repo\ILS_InternationalLanguageModule\database\dataFile.xml)";
    tool = HiddenButNotExposed::ILS::IntLanguageManager::getInstance(new
        HiddenButNotExposed::ILS::IntLanguageDataXML(DEFAULT_PATH));
    //tool->getMap(intLanMap);
    ui.setupUi(this);

    //initTree1();
    //initTree2();
}

void InternationalLanguageUi::initTree1()
{
    for (auto& Node:(*intLanMap)) {
        QTreeWidgetItem* p = new QTreeWidgetItem;
        QString s = QString("id-%1").arg(QString::fromStdString(Node.first));
        p->setText(0, s);
        ui.treeWidget->addTopLevelItem(p);
        for (auto& sonNode : Node.second) {
            QTreeWidgetItem* pp = new QTreeWidgetItem;
            QString ss = QString("country:").arg(QString::fromStdString(sonNode.first));
            pp->setText(0, ss);
            p->addChild(pp);

            QTreeWidgetItem* ppp = new QTreeWidgetItem;
            QString sss = QString::fromStdString(sonNode.second);
            ppp->setText(0, sss);
            pp->addChild(ppp);
        }
    }
}

void InternationalLanguageUi::initTree2()
{

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