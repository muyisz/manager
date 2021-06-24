#include "managementclub.h"
#include "ui_managementclub.h"
#include "controller.h"

ManagementClub::ManagementClub(Controller *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagementClub)
{
    this->c=c;
    ui->setupUi(this);
}

ManagementClub::~ManagementClub()
{
    delete ui;
}
