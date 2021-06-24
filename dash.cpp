#include "dash.h"
#include "ui_dash.h"
#include "controller.h"

Dash::Dash(Controller *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dash)
{
    this->c=c;
    ui->setupUi(this);
    ui->myclub->setColumnCount(3);
    QStringList clubdata;
    clubdata<<"社团名"<<"社团人数"<<"社团状态";
    ui->myclub->setHorizontalHeaderLabels(clubdata);
    ui->myclub->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->myclub->setColumnWidth(0,200);
    ui->myclub->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->myacit->setColumnCount(2);
    QStringList act;
    act<<"活动名称"<<"申请状态";
    ui->myacit->setHorizontalHeaderLabels(act);
    ui->myacit->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->myacit->setColumnWidth(0,300);
    ui->myacit->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->clubinfo->setColumnCount(2);
    QStringList info;
    info<<"社团编号"<<"社团名";
    ui->clubinfo->setHorizontalHeaderLabels(info);
    ui->clubinfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->clubinfo->setColumnWidth(0,100);
    ui->clubinfo->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
}

void Dash::getData()
{
    ui->username->setText("c->getUser()""");
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
