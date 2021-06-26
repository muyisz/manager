#ifndef DASH_H
#define DASH_H

#include <QWidget>

namespace Ui {
class Dash;
}

class Controller;
class Dash : public QWidget
{
    Q_OBJECT

public:
    explicit Dash(Controller *c,QWidget *parent = nullptr);
    ~Dash();
    void getData();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dash *ui;
    Controller *c;
};

#endif // DASH_H
