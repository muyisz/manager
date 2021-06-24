#ifndef JOINCLUB_H
#define JOINCLUB_H

#include <QWidget>

namespace Ui {
class Joinclub;
}
class Controller;
class Joinclub : public QWidget
{
    Q_OBJECT

public:
    explicit Joinclub(Controller *c,QWidget *parent = nullptr);
    ~Joinclub();

private slots:
    void on_yes_clicked();

private:
    Ui::Joinclub *ui;
    Controller *c;
};

#endif // JOINCLUB_H
