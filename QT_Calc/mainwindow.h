#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class  MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = nullptr);
    ~ MainWindow();

private slots:
    void digit_pressed();
    void dot_operation();
    void unary_operation();
    void binary_operation();
    void equal_pressed();
    void back_pressed();
    void theme1_pressed();
    void theme2_pressed();

private:
    Ui:: MainWindow *ui;
};

#endif // MAINWINDOW_H
