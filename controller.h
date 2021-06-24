#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "login.h"
#include "registered.h"
#include "dash.h"
#include "application.h"
#include "managementclub.h"
#include "joinclub.h"

#include <string>
class Controller
{
public:
    Controller();
    ~Controller();
    void showRegister();
    void showDash();
    void setUser(std::string);
    void showApplication();
    void showManagementClub();
    void showJoinclub();
    std::string getUser();
private:
    QWidget *now;
    Login *lo;
    Registered *re;
    Dash *da;
    Application *ap;
    ManagementClub *ma;
    Joinclub *jo;
    std::string user;
};

#endif // CONTROLLER_H
