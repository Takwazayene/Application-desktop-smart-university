#include "gestionabowindow.h"
#include "ui_gestionabowindow.h"
#include "bienvenu.h"
#include "abonneresto.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>

gestionAboWindow::gestionAboWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestionAboWindow)
{
    ui->setupUi(this);
}

gestionAboWindow::~gestionAboWindow()
{
    delete ui;
}

void gestionAboWindow::on_Retour_clicked()
{
    bienvenu  *w= new bienvenu();
    this->close() ;
    w->show() ;
}

void gestionAboWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString type_pension=ui->type_pension->currentText() ;
    QString date_abo = ui->dateEdit->text();



 abonneResto a(id,nom,prenom,type_pension,date_abo);
  bool test=a.ajouter();
  if(test)
{ui->tabetudiant->setModel(tmpabonne.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}



void gestionAboWindow::on_pushButton_calculernbrepresence_clicked()
{
    abonneResto a;
        int nbre_presence;
        nbre_presence = a.calculer_presence();

      ui->label_presence->setText(QString::number(nbre_presence)) ;
}

void gestionAboWindow::on_pushButton_2_clicked()
{
        ui->tabetudiant->setModel(tmpabonne.sortnom());
}

void gestionAboWindow::on_pushButton_trier_id_clicked()
{
      ui->tabetudiant->setModel(tmpabonne.sortid());
}


void gestionAboWindow::on_pb_supprimer_clicked()
{
    int id = ui->lineEdit->text().toInt();
     bool test=tmpabonne.supprimer(id);
     if(test)
     {ui->tabetudiant->setModel(tmpabonne.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer un abonné"),
                     QObject::tr("Abonné supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un abonné"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }





void gestionAboWindow::on_modifier_etu_clicked()
{
    QString nom,prenom;
    int id;
    id=ui->lineEdit_id_2->text().toInt();
    nom=ui->lineEdit_nom_2->text();
    prenom=ui->lineEdit_prenom_2->text();
    if (ui->lineEdit_id_2->text().isEmpty())
    {

        QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP identifiant !!!!") ;

    }
  else   if (ui->lineEdit_nom_2->text().isEmpty())
    {

        QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP nom  !!!!") ;

    }
else    if (ui->lineEdit_prenom_2->text().isEmpty())
    {

        QMessageBox::information(this," EREURE "," VEUILLEZ VERIFIER CHAMP prenom!!!!") ;
    }
else{
    //int id = ui->lineEdit->text().toInt();
     bool test=tmpabonne.modifier(id,nom,prenom);
     if(test)
     {ui->tabetudiant->setModel(tmpabonne.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Modifier un abonné"),
                     QObject::tr("Abonné modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modifier un abonné"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

