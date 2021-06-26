#ifndef MANAGEMENTCLUB_H
#define MANAGEMENTCLUB_H

#include <QWidget>

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
private:
    Ui::ManagementClub *ui;
    Controller *c;
};

#endif // MANAGEMENTCLUB_H
