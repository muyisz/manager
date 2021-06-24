#ifndef REGISTERED_H
#define REGISTERED_H

#include <QWidget>

namespace Ui {
class Registered;
}

class Controller;
class Registered : public QWidget
{
    Q_OBJECT

public:
    explicit Registered(Controller *c,QWidget *parent = nullptr);
    ~Registered();

private slots:
    void on_registered_b_clicked();

private:
    Ui::Registered *ui;
    Controller *c;
};

#endif // REGISTERED_H
