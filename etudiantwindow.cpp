#include "etudiantwindow.h"
#include "ui_etudiantwindow.h"
#include <QDebug>
#include "QSqlQuery"
#include <QString>
#include <QSqlQueryModel>
#include "abonneresto.h"
#include "menu.h"
#include "gestionabowindow.h"
#include "note_menu.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "bienvenu.h"
etudiantWindow::etudiantWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::etudiantWindow)
{
    ui->setupUi(this);
}

etudiantWindow::~etudiantWindow()
{
    delete ui;
}

void etudiantWindow::on_pushButton_clicked()
{
    int id ;
     QSqlQueryModel *model ;
      abonneResto *et ;
     id = ui->lineEdit->text().toInt() ;
      model = et->chercher_etudiant (id);
      ui->tableEtudiant->show() ;
      ui->tableEtudiant->setModel(model);

}

void etudiantWindow::on_pushButton_affichermenu_clicked()
{
    QString daate;
      Menu *tmpmenuu ;
     QSqlQueryModel *model ;
     daate = ui->lineEdit_inserezmenu->text() ;
      model =tmpmenuu->chercher_menu2 (daate);
      ui->tableView_menu2->show() ;
      ui->tableView_menu2->setModel(model);
}

void etudiantWindow::on_pushButton_notezmenu_clicked()
{
    QSqlQuery qrt;
     QString daate;
     bool test;
     int note ;
     gestionAboWindow *m ;
     daate = ui->lineEdit_inserezmenu->text() ;
     note = ui->spinBox_note->text().toInt() ;
     note_menu nm(daate,note) ;
      test=nm.ajouter_note_menu();
      if(test)
    {
    QMessageBox::information(nullptr, QObject::tr("Noter menu"),
                      QObject::tr(" note  effectué , merci .\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Noter menu"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void etudiantWindow::on_pushButton_2_clicked()
{
      bienvenu *b=new bienvenu();
    this->close() ;
    b->show();
}
