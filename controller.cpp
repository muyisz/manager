#include "controller.h"
#include "login.h"
#include "registered.h"
#include "dash.h"
#include "application.h"
#include "managementclub.h"
#include "joinclub.h"
#include <string>

Controller::Controller()
{
    lo=new Login(this);
    re=new Registered(this);
    da=new Dash(this);
    ap=new Application(this);
    ma=new ManagementClub(this);
    jo=new Joinclub(this);
    now=lo;
    now->show();
}

void Controller::showManagementClub()
{
    now->hide();
    now=ma;
    now->show();
}

void Controller::showJoinclub()
{
    now->hide();
    now=jo;
    now->show();
}

void Controller::setUser(std::string u)
{
    this->user=u;
}

std::string Controller::getUser()
{
    return this->user;
}

void Controller::showApplication()
{
    now->hide();
    now=ap;
    now->show();
}

void Controller::showRegister()
{
    now->hide();
    now=re;
    now->show();
}

void Controller::showDash()
{
    now->hide();
    now=da;
    da->getData();
    now->show();
}


Controller::~Controller()
{
    delete lo;
}
