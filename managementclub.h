#ifndef MANAGEMENTCLUB_H
#define MANAGEMENTCLUB_H

#include <QWidget>
#include <QCloseEvent>
namespace Ui {
class ManagementClub;
}
class Controller;
class ManagementClub :public QWidget
{
    Q_OBJECT

public:
    explicit ManagementClub(Controller *c,QWidget *parent = nullptr);
    ~ManagementClub();
    void getData();
    void ac();
    void wa();
    void closeEvent( QCloseEvent * event);
private:
    Ui::ManagementClub *ui;
    Controller *c;
};

#endif // MANAGEMENTCLUB_H
