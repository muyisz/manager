#include "application.h"
#include "ui_application.h"
#include "controller.h"
#include "system.h"
#include <QString>
#include <iostream>
#include <string>

Application::Application(Controller *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Application)
{
    this->c=c;
    ui->setupUi(this);
}

Application::~Application()
{
    delete ui;
}

void Application::on_confirmSubmission_clicked()
{
    QString actname=ui->actname->text();
    QString club=ui->club->text();
    QString neir=ui->actcontent->toPlainText();
    QString time=ui->year->text()+"/"+ui->mouth->text()+"/"+ui->day->text();
    std::string a=actname.toStdString();
    std::string cl=club.toStdString();
    std::string n=neir.toStdString();
    std::string t=time.toStdString();
    applyAction(a,t,n,cl);
    c->showDash();
}
