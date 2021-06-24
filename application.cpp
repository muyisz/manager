#include "application.h"
#include "ui_application.h"
#include "controller.h"
#include <QString>
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
    QString neir=ui->actcontent->toPlainText();
    std::string a=actname.toStdString();
    std::string n=neir.toStdString();
    //提交函数
    c->showDash();
}
