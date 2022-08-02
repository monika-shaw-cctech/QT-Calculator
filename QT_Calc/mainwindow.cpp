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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digit_pressed()
{
//    qDebug()<<"presses";
    QPushButton *button = (QPushButton*)sender();

    if(ui->label_2->text() == '0')
    {
         ui->label_2->setText(button->text());
    }

    else
    {
        ui->label_2->setText(ui->label_2->text()+button->text());
    }

}


