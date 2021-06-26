#include "joinclub.h"
#include "ui_joinclub.h"
#include "system.h"
#include "controller.h"

Joinclub::Joinclub(Controller *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Joinclub)
{
    this->c=c;
    ui->setupUi(this);
}

Joinclub::~Joinclub()
{
    delete ui;
}

void Joinclub::on_yes_clicked()
{
    QString club=ui->clubid->text();
    std::string cl=club.toStdString();
    joinClub(cl);
    this->c->showDash();
}
