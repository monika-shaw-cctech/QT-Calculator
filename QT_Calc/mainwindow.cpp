#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <math.h>
#include "infixToPostfix.h"
using namespace std;

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
   connect(ui->pushButton_reciprocal,SIGNAL(pressed()),this,SLOT(unary_operation()));
   connect(ui->pushButton_square,SIGNAL(pressed()),this,SLOT(unary_operation()));
   connect(ui->pushButton_square_root,SIGNAL(pressed()),this,SLOT(unary_operation()));
   connect(ui->pushButton_half,SIGNAL(pressed()),this,SLOT(unary_operation()));

   connect(ui->pushButton_plus,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_minus,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_multiply,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_divide,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_power,SIGNAL(pressed()),this,SLOT(binary_operation()));


   connect(ui->pushButton_left_brace,SIGNAL(pressed()),this,SLOT(add_brackets()));
   connect(ui->pushButton_right_brace,SIGNAL(pressed()),this,SLOT(add_brackets()));



   connect(ui->pushButton_clear,SIGNAL(pressed()),this,SLOT(clear_pressed()));
   connect(ui->pushButton_equals,SIGNAL(pressed()),this,SLOT(equal_pressed()));
   connect(ui->pushButton_back,SIGNAL(pressed()),this,SLOT(back_pressed()));

    connect(ui->pushButton_theme,SIGNAL(pressed()),this,SLOT(theme_pressed()));







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
         secondNum =( ui->label_2->text()).toDouble();
    }
        else
        {
            ui->label_2->setText(ui->label_2->text()+button->text());
            secondNum =( ui->label_2->text()).toDouble();
            qDebug()<<secondNum;

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

    else if(button->text() == "𝔁/2")
    {
       label = (ui->label_2->text().toDouble()) * (0.5);
//       qDebug()<<label;
       result = QString::number(label);
       ui->label_2->setText(result);

    }



}

void MainWindow::binary_operation()
{
    QPushButton*button =(QPushButton*)sender();
    button->setCheckable(true);
    if(button->text() == "+" || button->text() == "-" || button->text() == "x" || button->text() == "/"||button->text() == "^" )
    {
    firstNum = ui->label_2->text().toDouble();
    qDebug()<<firstNum;
    ui->label_3->setText(ui->label_2->text()+' '+button->text());
     ui->label_2->setText("0");


    }

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
    ui->label_3->setText("0");
}

void MainWindow::back_pressed()
{
    QString displayLabel = ui->label_3->text();

      //Check if label is empty
      if (displayLabel.length() == 0) {
          return;
      }

      //Delete last digit from string
      displayLabel.QString::chop(1);
      //Set number back to display
      ui->label_3->setText(displayLabel);

}

void MainWindow::equal_pressed()
{
    if(ui->pushButton_plus->isChecked())
    {
    double sum;
    sum = firstNum+secondNum;
    QString label;
    label  = QString::number(sum);
    ui->label_1->setText(label);
    ui->pushButton_plus->setChecked(false);

    }

    else if(ui->pushButton_minus->isCheckable())
    {
        double sub;
        sub = firstNum-secondNum;
        QString label;
        label  = QString::number(sub);
        ui->label_1->setText(label);
        ui->pushButton_minus->setChecked(false);

    }
    else if(ui->pushButton_multiply->isCheckable())
    {
        double mul;
        mul = firstNum*secondNum;
        QString label;
        label  = QString::number(mul);
        ui->label_1->setText(label);
        ui->pushButton_minus->setChecked(false);

    }
    else if(ui->pushButton_divide->isCheckable())
    {
        double div;
        div = firstNum/secondNum;
        QString label;
        label  = QString::number(div);
        ui->label_1->setText(label);
        ui->pushButton_minus->setChecked(false);

    }
    else
    {
        double power;
        power = pow(firstNum,secondNum);
        QString label;
        label  = QString::number(power);
        ui->label_1->setText(label);
        ui->pushButton_minus->setChecked(false);


    }
}

void MainWindow::theme_pressed()
{
  ui->pushButton_zero->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton_one->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton_two->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton_three->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton_four->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton_five->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton_six->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton_seven->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton_eight->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton_nine->setStyleSheet("* { background-color:red;border-radius:10px; }");

}
