#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <math.h>
#include "infixToPostfix.h"
#include "unaryOperation.h"


using namespace std;

double firstNum, secondNum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *numButtons[10];

       // Cycle through locating the buttons
       for(int i = 0; i < 10; ++i){
           QString butName = "pushButton" + QString::number(i);

           // Get the buttons by name and add to array
           numButtons[i] = MainWindow::findChild<QPushButton *>(butName);

           // When the button is released call num_pressed()
           connect(numButtons[i], SIGNAL(released()), this,
                   SLOT(digit_pressed()));
       }

   connect(ui->pushButton_plus,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_minus,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_multiply,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_divide,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_power,SIGNAL(pressed()),this,SLOT(binary_operation()));

    connect(ui->pushButton_dot,SIGNAL(pressed()),this,SLOT(dot_operation()));
    connect(ui->pushButton_half,SIGNAL(pressed()),this,SLOT(unary_operation()));



   connect(ui->pushButton_left_brace,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_right_brace,SIGNAL(pressed()),this,SLOT(binary_operation()));



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
    QPushButton *button=(QPushButton*)sender(); //sender return object that call method
      if(ui->label_2->text()=="0"){
          ui->label_2->setText(button->text());
      }
      else{
          string exp=ui->label_2->text().toStdString();
          size_t length=exp.length();
          if(exp[length-1]=='+'||exp[length-1]=='*'||exp[length-1]=='-'||exp[length-1]=='/' ||exp[length-1]=='^'|| exp[length-1]=='(')
              ui->label_2->setText(ui->label_2->text()+' '+button->text());
          else
              ui->label_2->setText(ui->label_2->text()+button->text());
      }
}


void MainWindow::dot_operation()
{
    digit_pressed();
}


void MainWindow::unary_operation()
{
    qDebug()<<ui->label_2->text();
    string exp = ui->label_2->text().toStdString();
    ui->label_3->setText(ui->label_2->text());
    double result = all_unary_operation(exp);

    ui->label_1->setText(QString::number(result));


}

void MainWindow :: binary_operation()
{
    QPushButton*button =(QPushButton*)sender();
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
    QString displayLabel = ui->label_2->text();

      //Check if label is empty
      if (displayLabel.length() == 0) {
          return;
      }

      //Delete last digit from string
      displayLabel.QString::chop(1);
      //Set number back to display
      ui->label_2->setText(displayLabel);

}

void MainWindow::equal_pressed()
{


       string expression=ui->label_2->text().toStdString();
       long long result=evaluate(expression);
       ui->label_1->setText(QString::number(result,'g',15));
       //ui->statusBar->showMessage("valid expression",1000);
       ui->label_3->setText(QString::fromStdString(infixToPostfix(expression)));
}

void MainWindow::theme_pressed()
{
  ui->pushButton1->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton2->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton3->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton4->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton5->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton6->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton7->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton8->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton9->setStyleSheet("* { background-color:red;border-radius:10px; }");
  ui->pushButton0->setStyleSheet("* { background-color:red;border-radius:10px; }");

}
