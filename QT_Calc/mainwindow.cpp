#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   connect(ui->pushButton_zero,SIGNAL(pressed()),this,SLOT(digit_pressed()));
   connect(ui->pushButton_one,SIGNAL(pressed()),this,SLOT(digit_pressed()));
   connect(ui->pushButton_two,SIGNAL(pressed()),this,SLOT(digit_pressed()));
   connect(ui->pushButton_three,SIGNAL(pressed()),this,SLOT(digit_pressed()));
   connect(ui->pushButton_four,SIGNAL(pressed()),this,SLOT(digit_pressed()));
   connect(ui->pushButton_five,SIGNAL(pressed()),this,SLOT(digit_pressed()));
   connect(ui->pushButton_six,SIGNAL(pressed()),this,SLOT(digit_pressed()));
   connect(ui->pushButton_seven,SIGNAL(pressed()),this,SLOT(digit_pressed()));
   connect(ui->pushButton_eight,SIGNAL(pressed()),this,SLOT(digit_pressed()));
   connect(ui->pushButton_nine,SIGNAL(pressed()),this,SLOT(digit_pressed()));


   connect(ui->pushButton_dot,SIGNAL(pressed()),this,SLOT(unary_operation()));
   connect(ui->pushButton_plus_minus,SIGNAL(pressed()),this,SLOT(unary_operation()));
   connect(ui->pushButton_modulo,SIGNAL(pressed()),this,SLOT(unary_operation()));
   connect(ui->pushButton_half,SIGNAL(pressed()),this,SLOT(unary_operation()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digit_pressed()
{
//    qDebug()<<"presses";
    QPushButton *button = (QPushButton*)sender();

    double label;
    QString result;

    //ui->label_2->setText(ui->label_2->text()+button->text());

    if(ui->label_2->text() == '0')
    {
         ui->label_2->setText(button->text());
    }

    else
    {
          label = (ui->label_2->text()+button->text()).toDouble();
          result = QString::number(label,'g',15);
          ui->label_2->setText(result);
    }

}

void MainWindow::unary_operation()
{
//      qDebug()<<"dot";
     QPushButton *button = (QPushButton*)sender();
     double label;
     QString result;

    if(button->text() == '.')
    {
        ui->label_2->setText(ui->label_2->text()+".");
    }

    else if(button->text() == "+/-")
    {
//        ui->label_2->setText("-"+ui->label_2->text());


        label = (ui->label_2->text().toDouble())* (-1);
        result = QString::number(label);
        ui->label_2->setText(result);
    }
    else if(button->text() == "%")
    {
        label = (ui->label_2->text().toDouble()) * (0.01);
        result = QString::number(label);
        ui->label_2->setText(result);

    }
    else if(button->text() == "1/𝔁")
    {
        label =  (1) / (ui->label_2->text().toDouble());
        result = QString::number(label);
        ui->label_2->setText(result);
    }

}


