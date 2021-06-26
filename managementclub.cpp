#include "managementclub.h"
#include "ui_managementclub.h"
#include "controller.h"
#include <QPushButton>
#include <iostream>
#include "system.h"

ManagementClub::ManagementClub(Controller *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagementClub)
{
    this->c=c;
    ui->setupUi(this);
    QStringList club;
    club<<"社团ID"<<"社团名"<<"社团简介"<<"创建时间"<<"社团人数";
    ui->club->setColumnCount(5);
    ui->club->setHorizontalHeaderLabels(club);
    ui->club->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->club->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->club->verticalHeader()->setVisible(false);
    QStringList act;
    act<<"活动ID"<<"活动名"<<"活动内容"<<"活动时间"<<"活动状态";
    ui->act->setColumnCount(5);
    ui->act->setHorizontalHeaderLabels(act);
    ui->act->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->act->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->act->verticalHeader()->setVisible(false);
    QStringList checkact;
    checkact<<"活动ID"<<"活动名"<<"操作"<<"  ";
    ui->checkact->setColumnCount(4);
    ui->checkact->setHorizontalHeaderLabels(checkact);
    ui->checkact->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->checkact->setColumnWidth(0,50);
    ui->checkact->setColumnWidth(1,150);
    ui->checkact->setColumnWidth(2,50);
    ui->checkact->setColumnWidth(3,50);
    ui->checkact->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
    ui->checkact->verticalHeader()->setVisible(false);
}

void ManagementClub::ac(){
    QPushButton *button = (QPushButton *)sender();
    auto id = button->property("id").toString().toStdString();
    acceptAction(id);
    getData();
}

void ManagementClub::wa(){
    QPushButton *button = (QPushButton *)sender();
    auto id = button->property("id").toString().toStdString();
    rejectAction(id);
    getData();
}

void ManagementClub::closeEvent(QCloseEvent * event)
{
    writeData();
}


void ManagementClub::getData()
{
    ui->act->clearContents();
    ui->club->clearContents();
    ui->checkact->clearContents();
    ui->act->setRowCount(0);
    ui->club->setRowCount(0);
    ui->checkact->setRowCount(0);
    vector<Community> club=getAllClub();
    QTableWidgetItem *item[5];
    for(auto i : club)
    {
        int nCount = ui->club->rowCount();
        ui->club->insertRow(nCount);
        QString name=QString::fromStdString(i.GetName());
        QString size=QString::number(i.size);
        QString sta=QString::fromStdString(i.GetDes());
        QString time=QString::fromStdString(i.GetTime());
        QString ID=QString::number(i.GetID());
        item[0]=new QTableWidgetItem(ID);
        item[1]=new QTableWidgetItem(name);
        item[2]=new QTableWidgetItem(sta);
        item[3]=new QTableWidgetItem(time);
        item[4]=new QTableWidgetItem(size);
        ui->club->setItem(nCount,0,item[0]);
        ui->club->setItem(nCount,1,item[1]);
        ui->club->setItem(nCount,2,item[2]);
        ui->club->setItem(nCount,3,item[3]);
        ui->club->setItem(nCount,4,item[4]);
    }
    vector<Action>act =getAllAction();
    for(auto i : act)
    {
        int nCount = ui->act->rowCount();
        ui->act->insertRow(nCount);
        QString name=QString::fromStdString(i.GetName());
        QString sta;
        int s=i.status;
        switch(s)
        {
        case -1:sta="NO";break;
        case 0:sta="CHECK";break;
        case 1:sta="YES";break;
        }
        QString ID=QString::number(i.GetID());
        QString time=QString::fromStdString(i.GetTime());
        QString nr=QString::fromStdString(i.GetDes());
        item[0]=new QTableWidgetItem(ID);
        item[1]=new QTableWidgetItem(name);
        item[2]=new QTableWidgetItem(nr);
        item[3]=new QTableWidgetItem(time);
        item[4]=new QTableWidgetItem(sta);
        ui->act->setItem(nCount,0,item[0]);
        ui->act->setItem(nCount,1,item[1]);
        ui->act->setItem(nCount,2,item[2]);
        ui->act->setItem(nCount,3,item[3]);
        ui->act->setItem(nCount,4,item[4]);
    }
    vector<Action>checkact =getCheckAction();
    for(auto i : checkact)
    {
        std::cout<<"1"<<"\n";
        int nCount = ui->checkact->rowCount();
        ui->checkact->insertRow(nCount);
        QString name=QString::fromStdString(i.GetName());
        QString ID=QString::number(i.GetID());
        item[0]=new QTableWidgetItem(ID);
        item[1]=new QTableWidgetItem(name);
        ui->checkact->setItem(nCount,0,item[0]);
        ui->checkact->setItem(nCount,1,item[1]);
        QPushButton *ac = new QPushButton(this);
        QPushButton *wa = new QPushButton(this);
        ac->setText("同意");
        ac->setProperty("id", ID);
        wa->setText("拒绝");
        wa->setProperty("id", ID);
        connect(wa,&QPushButton::clicked,this,&ManagementClub::wa);
        connect(ac,&QPushButton::clicked,this,&ManagementClub::ac);
        ui->checkact->setCellWidget(nCount,2,ac);
        ui->checkact->setCellWidget(nCount,3,wa);
    }
}

ManagementClub::~ManagementClub()
{
    delete ui;
}

