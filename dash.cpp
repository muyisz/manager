#include "dash.h"
#include "ui_dash.h"
#include "controller.h"
#include "system.h"
#include "models.h"
#include <iostream>

Dash::Dash(Controller *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dash)
{
    this->c=c;
    ui->setupUi(this);
    ui->myclub->setColumnCount(3);
    QStringList clubdata;
    clubdata<<"社团名"<<"社团人数"<<"社团简介";
    ui->myclub->setHorizontalHeaderLabels(clubdata);
    ui->myclub->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->myclub->setColumnWidth(0,200);
    ui->myclub->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->myclub->verticalHeader()->setVisible(false);
    ui->myacit->setColumnCount(2);
    QStringList act;
    act<<"活动名称"<<"申请状态";
    ui->myacit->setHorizontalHeaderLabels(act);
    ui->myacit->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->myacit->setColumnWidth(0,300);
    ui->myacit->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->myacit->verticalHeader()->setVisible(false);
    ui->clubinfo->setColumnCount(2);
    QStringList info;
    info<<"社团编号"<<"社团名";
    ui->clubinfo->setHorizontalHeaderLabels(info);
    ui->clubinfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->clubinfo->setColumnWidth(0,100);
    ui->clubinfo->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->clubinfo->verticalHeader()->setVisible(false);
}

void Dash::getData()
{
    ui->myclub->clearContents();
    ui->myacit->clearContents();
    ui->clubinfo->clearContents();
    ui->myclub->setRowCount(0);
    ui->myacit->setRowCount(0);
    ui->clubinfo->setRowCount(0);
    QString name=QString::fromStdString(getUserName());
    ui->name->setText(name);
    QString username=QString::fromStdString(c->getUser());
    ui->username->setText(username);
    vector<Community> club=getJoinedClub();
    QTableWidgetItem *item[3];
    for(auto i : club)
    {
        int nCount = ui->myclub->rowCount();
        ui->myclub->insertRow(nCount);
        QString name=QString::fromStdString(i.GetName());
        QString size=QString::number(i.size);
        QString sta=QString::fromStdString(i.GetDes());
        item[0]=new QTableWidgetItem(name);
        item[1]=new QTableWidgetItem(size);
        item[2]=new QTableWidgetItem(sta);
        ui->myclub->setItem(nCount,0,item[0]);
        ui->myclub->setItem(nCount,1,item[1]);
        ui->myclub->setItem(nCount,2,item[2]);
    }
    vector<Action>act =getMyAction();
    for(auto i : act)
    {
        int nCount = ui->myacit->rowCount();
        ui->myacit->insertRow(nCount);
        QString name=QString::fromStdString(i.GetName());
        QString sta;
        int s=i.status;
        switch(s)
        {
        case -1:sta="NO";break;
        case 0:sta="CHECK";break;
        case 1:sta="YES";break;
        }
        item[0]=new QTableWidgetItem(name);
        item[1]=new QTableWidgetItem(sta);
        ui->myacit->setItem(nCount,0,item[0]);
        ui->myacit->setItem(nCount,1,item[1]);
    }
    vector<Community> ac=getAllClub();
    for(auto i : ac)
    {
        int nCount = ui->clubinfo->rowCount();
        ui->clubinfo->insertRow(nCount);
        QString name=QString::fromStdString(i.GetName());
        QString ID=QString::number(i.GetID());
        item[0]=new QTableWidgetItem(ID);
        item[1]=new QTableWidgetItem(name);
        ui->clubinfo->setItem(nCount,0,item[0]);
        ui->clubinfo->setItem(nCount,1,item[1]);
    }
}

void Dash::closeEvent(QCloseEvent * event)
{
    writeData();
    std::cout<<"--------\n";
}


Dash::~Dash()
{
    delete ui;
}

void Dash::on_pushButton_2_clicked()
{
    this->c->showApplication();
}

void Dash::on_pushButton_clicked()
{
    this->c->showJoinclub();
}
