#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "menu.h"
#include <QMessageBox>
#include "bienvenu.h"
#include "note_menu.h"
menuWindow::menuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menuWindow)
{
    ui->setupUi(this);
}

menuWindow::~menuWindow()
{
    delete ui;
}

void menuWindow::on_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString jours= ui->lineEdit_jours->text();
    QString repas= ui->lineEdit_repas->text();
    QString dessert = ui->lineEdit_dessert->text();
    QString daate = ui->lineEdit_date->text();
   // int note = ui->lineEdit_note->text().toInt();
  Menu M (id,jours,repas,dessert,daate);
  bool test=M.ajouter();
  if(test)
{ui->tabMenu->setModel(tmpMenu.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un menu"),
                  QObject::tr("Menu ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un menu"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void menuWindow::on_pushButton_chercherMenu_clicked()
{
    int id ;
     QSqlQueryModel *model ;
     id = ui->lineEdit_chercherMenu->text().toInt() ;
      model =tmpMenuu->chercher_menu (id);
      ui->tabMenu->show() ;
      ui->tabMenu->setModel(model);
}

void menuWindow::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
     bool test=tmpMenu.supprimer(id);
     if(test)
     {ui->tabMenu->setModel(tmpMenu.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer un menu"),
                     QObject::tr("Menu supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un menu"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);



}


void menuWindow::on_pushButton_trierParId_clicked()
{
    ui->tabMenu->setModel( tmpMenu.sortid());
}

void menuWindow::on_pushButton_clicked()
{

    bienvenu  *w= new bienvenu();
    this->close() ;
    w->show() ;
}


void menuWindow::on_pushButton_calculer_clicked()
{
    QString daate ;
        note_menu tmpmenu ;
        daate=ui->lineEdit->text() ;
        int somme ;
        somme =tmpmenu.calculer_note(daate);

      ui->label_13->setText(QString::number(somme)) ;

}

void menuWindow::on_pushButton_afficher_note_clicked()
{
    note_menu tmpmenu ;
    ui->table_note->setModel(tmpmenu.afficher_note_menu());//refresh
}
