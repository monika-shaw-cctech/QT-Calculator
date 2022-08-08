#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <math.h>
#include "infixToPostfix.h"
#include "digit.h"
#include "unary.h"
#include "binary.h"
#include "equal.h"
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


   connect(ui->pushButton_dot,SIGNAL(pressed()),this,SLOT(dot_operation()));
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
     string btnTxt = button->text().toStdString();
     string labelTxt = ui->label_2->text().toStdString();
     string res = labelText(labelTxt,btnTxt);
     double num = stod(res);
     ui->label_2->setText(QString::number(num));
     secondNum =num;

    }


void MainWindow::dot_operation()
{
    QPushButton *button = (QPushButton*)sender();
    string lText = ui->label_2->text().toStdString();
    string bText = button->text().toStdString();
    string s = dotOperation(lText,bText);
    ui->label_2->setText(QString::fromStdString(s));

}


void MainWindow::unary_operation()
{
//      qDebug()<<"dot";
     QPushButton *button = (QPushButton*)sender();
     double lText = ui->label_2->text().toDouble();
     string bText = button->text().toStdString();

     double res = allUnaryOperation(lText,bText);
      ui->label_2->setText(QString::number(res));


}

void MainWindow::binary_operation()
{
    QPushButton*button =(QPushButton*)sender();
    button->setCheckable(true);


    string lText = ui->label_2->text().toStdString();
    string bText = button->text().toStdString();
    string s = binaryOperation(lText,bText);
    firstNum = stod(lText);
    ui->label_3->setText(QString::fromStdString(s));
    ui->label_2->setText("0");


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
    bool plus = ui->pushButton_plus->isChecked();
    bool minus = ui->pushButton_minus->isChecked();
    bool multiply = ui->pushButton_multiply->isChecked();
    bool divide = ui->pushButton_divide->isChecked();

    double res = equalOperation(firstNum,secondNum,plus,minus,multiply,divide);
     ui->label_1->setText(QString::number(res));
     ui->pushButton_plus->setChecked(false);
     ui->pushButton_minus->setChecked(false);

     ui->pushButton_multiply->setChecked(false);
     ui->pushButton_divide->setChecked(false);




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
