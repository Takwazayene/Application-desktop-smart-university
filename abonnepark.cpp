#include "abonnepark.h"
#include <QDebug>

abonnePark::abonnePark()
{
  idEtudiant=0 ;
  nbre_Reservation=0 ;
}

abonnePark::abonnePark(int idEtudiant , int nbre_Reservation)
{
    this->idEtudiant=idEtudiant ;
    this->nbre_Reservation=nbre_Reservation ;

}

int abonnePark::get_idEtudiant() {return  idEtudiant ;}
int abonnePark::get_nbre_Reservation() {return  nbre_Reservation ;}

bool abonnePark::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(idEtudiant);
    query.prepare("INSERT INTO etudiant (IDETUDIANT, NBRE_RESERVATION) "
                        "VALUES (:idEtudiant, :nbre_Reservation)");
    query.bindValue(":idEtudiant", res);
    query.bindValue(":nbre_Reservation", nbre_Reservation);
    return    query.exec();
}

QSqlQueryModel * abonnePark::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from etudiant");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IdEtudiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nbre_Reservation "));
     return model;
}

bool abonnePark::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from abonnePark where ID = :idEtudiant");
    query.bindValue(":idEtudiant", res);
    return    query.exec();

 }

