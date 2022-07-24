#include "mainwindow.h"
#include <QApplication>
#include <connection.h>
#include <QMessageBox>
#include <QObject>
#include <QtSql>
#include <iostream>
#include <QDebug>
#include <integration.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    integration w ;

    connection c;

    if(c.createconnect())
    {
        w.show();
        QMessageBox::information(nullptr,QObject::tr("databse is open"),
                              QObject::tr("connect successful.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel );

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("databse is not open"),
                              QObject::tr("connect failled.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel );
    }


    return a.exec();
}
