#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include <QApplication>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Catch::Session().run(argc,argv);
    return a.exec();

}


