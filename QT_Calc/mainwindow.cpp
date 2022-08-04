#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <math.h>
using namespace std;

QString first_label;

double firstNum, secondNum;

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
   connect(ui->pushButton_square,SIGNAL(pressed()),this,SLOT(unary_operation()));
   connect(ui->pushButton_square_root,SIGNAL(pressed()),this,SLOT(unary_operation()));

   connect(ui->pushButton_plus,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_minus,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_multiply,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_divide,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_power,SIGNAL(pressed()),this,SLOT(binary_operation()));

   connect(ui->pushButton_left_brace,SIGNAL(pressed()),this,SLOT(add_brackets()));
   connect(ui->pushButton_right_brace,SIGNAL(pressed()),this,SLOT(add_brackets()));



   connect(ui->pushButton_clear,SIGNAL(pressed()),this,SLOT(clear_pressed()));




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digit_pressed()
{
//    qDebug()<<"presses";
    QPushButton *button=(QPushButton*)sender(); //sender return object that call method
    if(ui->label_2->text()=="0"){
        ui->label_2->setText(button->text());
    }else{
        string exp=ui->label_2->text().toStdString();
        size_t length=exp.length();
        if(exp[length-1]=='+'||exp[length-1]=='x'||exp[length-1]=='-'||exp[length-1]=='/' ||exp[length-1]=='^')
            //qDebug()<<ui->label_2->setText(ui->label_2->text()+' '+button->text());
            ui->label_2->setText(ui->label_2->text()+' '+button->text());
        else
            ui->label_2->setText(ui->label_2->text()+button->text());
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

    else if(button->text() == "𝔁²")
    {
        label = ui->label_2->text().toDouble() * (2);
        result = QString::number(label);
        ui->label_2->setText(result);

    }

    else if(button->text() == "²√")
    {
       label = sqrt(ui->label_2->text().toDouble());
//       qDebug()<<label;
       result = QString::number(label);
       ui->label_2->setText(result);

    }


}

void MainWindow::binary_operation()
{
    QPushButton*button =(QPushButton*)sender();
       ui->label_2->setText(ui->label_2->text()+' '+button->text());
}

void MainWindow::add_brackets()
{
    QPushButton*button =(QPushButton*)sender();
    // qDebug()<<(ui->label_2->text()+' '+button->text());
       ui->label_2->setText(ui->label_2->text()+' '+button->text());
}

void MainWindow::clear_pressed()
{
    ui->label_1->setText("0");
    ui->label_2->setText("0");
}



void MainWindow::equal_pressed()
{


}
