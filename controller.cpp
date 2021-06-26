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
    n=lo;
    n->show();
}

void Controller::showManagementClub()
{
    n->hide();
    ma->getData();
    n=ma;
    n->show();
}

void Controller::showJoinclub()
{
    n->hide();
    n=jo;
    n->show();
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
    n->hide();
    n=ap;
    n->show();
}

void Controller::showRegister()
{
    n->hide();
    n=re;
    n->show();
}

void Controller::showDash()
{
    n->hide();
    n=da;
    da->getData();
    n->show();
}


Controller::~Controller()
{
    delete lo;
}
