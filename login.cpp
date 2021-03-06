#include "login.h"
#include "ui_login.h"
#include "controller.h"
#include <QString>
#include "system.h"

Login::Login(Controller *c,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    this->c=c;
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_register_b_clicked()
{
    this->c->showRegister();
}

void Login::closeEvent(QCloseEvent * event)
{
    writeData();
}


void Login::on_login_b_clicked()
{
    QString username=ui->username->text();
    QString password=ui->password->text();
    std::string u=username.toStdString();
    std::string p=password.toStdString();
    if(!ui->shabi->isChecked())
    {
      if(checkUser(u,p)){
          c->setUser(u);
          c->showDash();
       }
       else{
            ///
       }
    }
    else{
        if(1){
            if (username == "admin" && password == "admin") {
                c->showManagementClub();
            }
        }
        else{

        }
    }
}
