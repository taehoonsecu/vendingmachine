#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}


class Widget : public QWidget   //from Qwidget inherit
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void changeMoney(int n);

    int money{0};           //each obcject haves money
    void checkBalance();
    int a,b,c,d=0;
    void repayment();
    char itoa( int value, char *string, int radix );

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbCoke_clicked();




    void on_pbReturn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
