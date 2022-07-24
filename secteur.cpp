#include "secteur.h"

secteur::secteur()
{
  num_S=0 ;
  nbre_Place=0 ;
  nomPark="" ;
  idEtudiant=0 ;
}

secteur::secteur(int num_S , int nbre_Place, QString nomPark, int idEtudiant )
{
  this->num_S=num_S ;
  this->nbre_Place=nbre_Place ;
  this->nomPark=nomPark ;
  this->idEtudiant=idEtudiant ;
}


int secteur::get_idEtudiant() {return idEtudiant ;}
int secteur:: get_nbre_Place() {return  nbre_Place ;}
int secteur:: get_num_S() {return  num_S ;}

bool secteur:: ajouter ()
{
    QSqlQuery query;
    QString res= QString::number(num_S);
    query.prepare("INSERT INTO parking (NUM_S, NBRE_PLACE ,NOMPARK ,IDETUDIANT) "
                        "VALUES (:num_S, :nbre_Place , :nomPark ,: idEtudiant)");
    query.bindValue(":num_S", res);
    query.bindValue(":nbre_place",nbre_Place );
    query.bindValue(":nomPark", nomPark);
    query.bindValue(":idEtudiant", idEtudiant);
    return    query.exec();
}


QSqlQueryModel *secteur::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from secteur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num_S"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr(" Nbre_Place"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr(" NomPark"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("IdEtudiant "));
     return model;
}


bool secteur::supprimer(int num)
{
    QSqlQuery query;
    QString res= QString::number(num);
    query.prepare("Delete from secteur where NUM_S = :num_S");
    query.bindValue(":num_S", res);
    return    query.exec();

 }
