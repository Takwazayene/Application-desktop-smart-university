#include "parking.h"
#include <QDebug>

parking::parking()
{
  nomPark="" ;
  nbre_Secteur=0 ;
  nbre_place=0 ;
  idEtudiant=0 ;
}

parking::parking(QString nomPark , int nbre_Secteur , int nbre_place , int idEtudiant)
{
    this-> nomPark=nomPark ;
    this->nbre_Secteur=nbre_Secteur ;
    this->nbre_place=nbre_place ;
    this->idEtudiant=idEtudiant ;

}

int parking::get_nbre_Secteur() {return  nbre_Secteur ;}
int parking::get_idEtudiant(){return  idEtudiant ;}
int parking::get_nbre_place(){return nbre_place ; }

bool parking::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(idEtudiant);
    query.prepare("INSERT INTO parking (NOMPARK , NBRE_SECTEUR ,NBRE_PLACE ,IDETUDIANT ,) "
                        "VALUES (:nomPark ,:nbre_Secteur,:nbre_place ,:idEtudiant)");
    query.bindValue(":nomPark", res);
    query.bindValue(":nbre_Secteur", nbre_Secteur);
    query.bindValue(":nbre_place", nbre_place);
    query.bindValue(":idEtudiant", idEtudiant);
    return    query.exec();
}

QSqlQueryModel *parking::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from parking");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nomPark"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbre_Secteur "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbre_place "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr(" idEtudiant"));
     return model;
}

bool parking::supprimer(QString nomP)
{
    QSqlQuery query;

    query.prepare("Delete from parking where NOMPARK = :nomPark");
    query.bindValue(":nomPark", nomP);
    return    query.exec();
}

