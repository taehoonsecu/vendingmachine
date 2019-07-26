#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCoke->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(money);
}

void Widget::checkBalance(){
    if(money<100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    }if(100<=money&&money <150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    }
    if(150<=money && money<200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoke->setEnabled(false);
    }
    if(200<=money){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoke->setEnabled(true);
    }
}

void Widget::repayment(){
    a=money/500;
    b=(money%500)/100;
    c=((money%500)%100)/50;
    d=(((money%500)%100)%50/10);

    string str1="500 : "+std::to_string(a)+" 100: "+std::to_string(b)+" 50: "+std::to_string(c)+" 10: "+std::to_string(d);
    //making string is success, but msg.information of QMessageBox uses QString!

    QString str = "500 : " + QString::number(a) +" 100: "+
            QString::number(b)+" 50: "+QString::number(c)+" 10: "+QString::number(d);


    QMessageBox msg;
    msg.information(nullptr, "title",str,"OK","NO"); //qstring googling

}



void Widget::on_pb10_clicked()
{
    changeMoney(10);
    checkBalance();


}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
    checkBalance();

}

void Widget::on_pb100_clicked()
{
     changeMoney(100);
    checkBalance();


}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
    checkBalance();

}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    checkBalance();
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    checkBalance();
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
    checkBalance();
}


void Widget::on_pbReturn_clicked()
{
    repayment();
}
