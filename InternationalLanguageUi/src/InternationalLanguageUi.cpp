#include "InternationalLanguageUi.h"
#include "ILS_IntLanguage.h"
#include "ILS_IntLanguageDataXML.h"
#include "ILS_IntLanguageDataAbstract.h"
#include "ILS_IntlanguageUtility.h"
#include "QDir.h"
#include "QWidget.h"
#include "QTreeWidget.h"
#include "ILS_IntLanguage.cpp"
#include "ILS_IntLanguageDataXML.cpp"
#include<set>

InternationalLanguageUi::InternationalLanguageUi(QWidget *parent)
    : QWidget(parent)
{
    DEFAULT_PATH = R"(C:\Users\86158\Desktop\Repo\ILS_InternationalLanguageModule\database\dataFile.xml)";
    tool = HiddenButNotExposed::ILS::IntLanguageManager::getInstance(new
        HiddenButNotExposed::ILS::IntLanguageDataXML(DEFAULT_PATH));
    intLanMap = new HiddenButNotExposed::ILS::IntLanguageDataAbstract::IntLanMap;
    tool->iniCom();
    tool->getMap(intLanMap);
    //if (intLanMap)std::cout << "YES";
    ui.setupUi(this);

    initTree1();
    initTree2();
}

void InternationalLanguageUi::initTree1()
{
    if (!intLanMap)return;
    for (auto& Node:(*intLanMap)) {
        QTreeWidgetItem* p = new QTreeWidgetItem;
        QString s = QString("id-%1").arg(QString::fromStdString(Node.first));
        p->setText(0, s);
        ui.treeWidget->addTopLevelItem(p);
        for (auto& sonNode : Node.second) {
            QTreeWidgetItem* pp = new QTreeWidgetItem;
            QString ss = QString("country:%1").arg(QString::fromStdString(sonNode.first));
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
    if (!intLanMap)return;
    std::set<std::string> st;
    for (auto& i : (*intLanMap)) {
        for (auto& j : i.second) {
            st.insert(j.first);
        }
    }
    if (!intLanStringMap)intLanStringMap = new 
        HiddenButNotExposed::ILS::IntLanguageDataAbstract::LanStringMap;
    intLanStringMap->clear();
    for (auto& coun : st) {
        intLanStringMap->clear();
        QTreeWidgetItem* p = new QTreeWidgetItem;
        QString s = QString("country-%1").arg(QString::fromStdString(coun));
        p->setText(0, s);
        ui.treeWidget_2->addTopLevelItem(p);
        tool->getMap(coun, intLanStringMap);
        for (auto& lan : (*intLanStringMap)) {
            QTreeWidgetItem* pp = new QTreeWidgetItem;
            QString ss = QString("id-%1").arg(QString::fromStdString(lan.first));
            pp->setText(0, ss);
            p->addChild(pp);
            QTreeWidgetItem* ppp = new QTreeWidgetItem;
            QString sss = QString::fromStdString(lan.second);
            ppp->setText(0, sss);
            pp->addChild(ppp);
        }
    }
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

void InternationalLanguageUi::pushButton_8_Clicked()
{
    QString id, language, string;
    id = ui.lineEdit_2->text();
    language = ui.lineEdit_3->text();
    string = ui.lineEdit->text();
    bool is_success = true;
    if (id.isEmpty() || language.isEmpty() || string.isEmpty())is_success = false;
    if (is_success) {
        auto result = tool->storeString(id.toStdString(), language.toStdString(), string.toStdString());
        if (result != HiddenButNotExposed::ILS::IntLanguageUtility::ErrorInfo::SUCCESS)is_success = false;
    }
    if (is_success) {
        tool->desCom();
        tool->iniCom();
        tool->getMap(intLanMap);
        ui.treeWidget->clear();
        initTree1();
        ui.treeWidget_2->clear();
        initTree2();
        ui.label_4->setText("运行结果：AC");
    }
    else {
        ui.label_4->setText("运行结果：WA");
    }
}

void InternationalLanguageUi::pushButton_10_Clicked()
{
    QString id = ui.lineEdit_6->text(), language = ui.lineEdit_7->text();
    std::string s;
    bool is_success = true;
    auto result = tool->searchString(id.toStdString(), language.toStdString(), s);
    if (result != HiddenButNotExposed::ILS::IntLanguageUtility::ErrorInfo::SUCCESS)is_success = false;
    if (is_success) {
        ui.label_10->setText("result：SUCCESS");
        ui.label_11->setText(QString("id:%1").arg(id));
        ui.label_12->setText(QString("语言:%1").arg(language));
        ui.label_13->setText(QString("字符:%1").arg(QString::fromStdString(s)));
    }
    else {
        ui.label_10->setText("result：NONE");
        ui.label_11->setText("id:");
        ui.label_12->setText("语言:");
        ui.label_13->setText("字符:");
    }
}

void InternationalLanguageUi::pushButton_11_Clicked()
{
    pushButton_10_Clicked();
}

void InternationalLanguageUi::pushButton_9_Clicked()
{
    QString id = ui.lineEdit_4->text(), language = ui.lineEdit_5->text();
    bool is_success = true;
    auto result = tool->delString(id.toStdString(), language.toStdString());
    if (result != HiddenButNotExposed::ILS::IntLanguageUtility::ErrorInfo::SUCCESS)is_success = false;
    if (is_success) {
        tool->desCom();
        tool->iniCom();
        tool->getMap(intLanMap);
        ui.treeWidget->clear();
        initTree1();
        ui.treeWidget_2->clear();
        initTree2();
        ui.label_7->setText("运行结果：AC");
    }
    else {
        ui.label_7->setText("运行结果：WA");
    }
}

void InternationalLanguageUi::pushButton_12_Clicked()
{
    int idx = ui.stackedWidget->currentIndex();
    QString s = ui.lineEdit_8->text();
    QString id, language;
    QList<QTreeWidgetItem*> selectItem;

    if (idx == 0) {
        selectItem = ui.treeWidget->selectedItems();
    }
    else {
        selectItem = ui.treeWidget_2->selectedItems();
    }

    if (selectItem.isEmpty() || s.isEmpty()) {
        ui.label_15->setText("运行结果：ERROR");
        return;
    }

    if (idx == 0) {

        int layer = 0;
        QTreeWidgetItem* st = selectItem.first();
        while (st && st->parent()) {
            layer++; st = st->parent();
        }

        if (layer != 2) {
            ui.label_15->setText("运行结果：ERROR");
            return;
        }

        st = selectItem.first();
        language = st->parent()->text(0);
        language = language.mid(8);
        id = st->parent()->parent()->text(0);
        id = id.mid(3);
    }
    else {
        int layer = 0;
        QTreeWidgetItem* st = selectItem.first();
        while (st && st->parent()) {
            layer++; st = st->parent();
        }

        if (layer != 2) {
            ui.label_15->setText("运行结果：ERROR");
            return;
        }

        st = selectItem.first();
        id = st->parent()->text(0);
        id = id.mid(3);
        language = st->parent()->parent()->text(0);
        language = language.mid(8);
    }

    auto result = tool->changeString(id.toStdString(), language.toStdString(), s.toStdString());
    if (result != HiddenButNotExposed::ILS::IntLanguageUtility::ErrorInfo::SUCCESS) {
        ui.label_15->setText("运行结果：ERROR");
        return;
    }

    tool->desCom();
    tool->iniCom();
    tool->getMap(intLanMap);
    ui.treeWidget->clear();
    initTree1();
    ui.treeWidget_2->clear();
    initTree2();
    ui.label_15->setText("运行结果：SUCCESS");
}

void InternationalLanguageUi::pushButton_6_Clicked()
{
    tool->clearData();
    tool->desCom();
    tool->iniCom();
    tool->getMap(intLanMap);
    ui.treeWidget->clear();
    initTree1();
    ui.treeWidget_2->clear();
    initTree2();
}