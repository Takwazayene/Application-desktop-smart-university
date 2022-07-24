#include "bienvenu.h"
#include "ui_bienvenu.h"
#include "gestionabowindow.h"
#include "menu.h"
#include "ui_menuwindow.h"
#include "menuwindow.h"
#include "etudiantwindow.h"


bienvenu::bienvenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bienvenu)
{
    ui->setupUi(this);
}

bienvenu::~bienvenu()
{
    delete ui;
}

void bienvenu::on_pushButton_5_clicked()
{
    gestionAboWindow *w =new gestionAboWindow();
    this->close() ;
    w->show();
}

void bienvenu::on_pushButton_6_clicked()
{
    menuWindow *m=new menuWindow();
    this->close() ;
    m->show();
}

void bienvenu::on_pushButton_7_clicked()
{
    etudiantWindow *e=new  etudiantWindow();
    this->close() ;
    e->show();
}
