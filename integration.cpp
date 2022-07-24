#include "integration.h"
#include "ui_integration.h"
#include "mainwindow.h"
#include "bienvenu.h"

integration::integration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::integration)
{
    ui->setupUi(this);
}

integration::~integration()
{
    delete ui;
}

void integration::on_pushButton_clicked()
{

    MainWindow  *w= new MainWindow();
    this->close() ;
    w->show() ;
}

void integration::on_pushButton_2_clicked()
{
    bienvenu  *w= new bienvenu();
    this->close() ;
    w->show() ;
}
