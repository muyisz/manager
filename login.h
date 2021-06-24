#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
namespace Ui {
class Login;
}
class Controller;
class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(Controller *c,QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_register_b_clicked();

    void on_login_b_clicked();

private:
    Ui::Login *ui;
    Controller *c;
};

#endif // LOGIN_H
