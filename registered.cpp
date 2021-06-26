#include "registered.h"
#include "ui_registered.h"
#include "controller.h"
#include <QString>
#include "system.h"

Registered::Registered(Controller *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registered)
{
    this->c=c;
    ui->setupUi(this);
}

void Registered::closeEvent(QCloseEvent * event)
{
    writeData();
}


Registered::~Registered()
{
    delete ui;
}

void Registered::on_registered_b_clicked()
{
    QString name=ui->name->text();
    QString username=ui->username->text();
    QString password=ui->password->text();
    std::string n=name.toStdString();
    std::string p=password.toStdString();
    std::string u=username.toStdString();
    setUser(n,u,p);
    c->setUser(u);
    c->showDash();
}
