#include <QApplication>
#include <QFile>
#include <math.h>

#include "mainwindow.h"
#include "infixToPostfix.h"
#include "QDebug"
#include "ui_mainwindow.h"
#include "unaryOperation.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *numButtons[10];
    for(int i = 0; i < 10; ++i)
    {
        QString butName = "pushButton" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this,SLOT(digit_pressed()));
    }

   connect(ui->pushButton_plus,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_minus,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_multiply,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_divide,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_power,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_left_brace,SIGNAL(pressed()),this,SLOT(binary_operation()));
   connect(ui->pushButton_right_brace,SIGNAL(pressed()),this,SLOT(binary_operation()));

   connect(ui->pushButton_round,SIGNAL(pressed()),this,SLOT(unary_operation()));
   connect(ui->pushButton_modulo,SIGNAL(pressed()),this,SLOT(unary_operation()));
   connect(ui->pushButton_square,SIGNAL(pressed()),this,SLOT(unary_operation()));
   connect(ui->pushButton_square_root,SIGNAL(pressed()),this,SLOT(unary_operation()));
   connect(ui->pushButton_reciprocal,SIGNAL(pressed()),this,SLOT(unary_operation()));
   connect(ui->pushButton_half,SIGNAL(pressed()),this,SLOT(unary_operation()));

   connect(ui->pushButton_clear,SIGNAL(pressed()),this,SLOT(clear_pressed()));
   connect(ui->pushButton_equals,SIGNAL(pressed()),this,SLOT(equal_pressed()));
   connect(ui->pushButton_back,SIGNAL(pressed()),this,SLOT(back_pressed()));

   connect(ui->pushButton_dot,SIGNAL(pressed()),this,SLOT(dot_operation()));

   connect(ui->pushButton_theme,SIGNAL(pressed()),this,SLOT(theme1_pressed()));
   connect(ui->pushButton_theme_2,SIGNAL(pressed()),this,SLOT(theme2_pressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton *button=(QPushButton*)sender();
    if(ui->label_2->text()=="0")
        ui->label_2->setText(button->text());
    else
    {
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
    QPushButton *button=(QPushButton*)sender();
    string exp = ui->label_2->text().toStdString();
    string op = button->text().toStdString();
    ui->label_3->setText(ui->label_2->text());
    double result = all_unary_operation(exp,op);
    ui->label_2->setText(QString::number(result));
    ui->label_1->setText(ui->label_2->text());
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
    if (displayLabel.length() == 0)
        return;

    displayLabel.QString::chop(1);
    ui->label_2->setText(displayLabel);
}

void MainWindow::equal_pressed()
{
    ui->label_3->setText(ui->label_2->text());
    string expression=ui->label_2->text().toStdString();
    long long result=infixToPostfixEvaluate(expression);
    ui->label_1->setText(QString::number(result,'g',15));
}

void MainWindow::theme1_pressed()
{
    QFile StylesheetFile("C:/Projects/QT-Calculator/QT_Calc/Diplaytap.qss");
    StylesheetFile.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(StylesheetFile.readAll());
    setStyleSheet(stylesheet);
}

void MainWindow::theme2_pressed()
{
    QFile StylesheetFile("C:/Projects/QT-Calculator/QT_Calc/Clocker.qss");
    StylesheetFile.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(StylesheetFile.readAll());
    setStyleSheet(stylesheet);
}
