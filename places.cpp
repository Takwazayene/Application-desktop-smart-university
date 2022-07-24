#include "places.h"

places::places()
{
  num_P=0 ;
  statut=0 ; ;
 idEtudiant=0 ;
}

places::places(int num_P ,int statut,int idEtudiant)
{
  this->num_P=num_P ;
  this->statut= statut;

  this->idEtudiant=idEtudiant ;
}


int places:: get_idEtudiant() {return idEtudiant ;}
int places::get_nbre_num_P() {return num_P ; }

int places::get_statut() {return statut; }


bool places::ajouter()
{
QSqlQuery query;
QString res= QString::number(num_P);
query.prepare("INSERT INTO PLACES (NUMP, STATUT ,IDETUDIANTS) "
                    "VALUES (:num_P, :statut, :idEtudiant )");
query.bindValue(":num_P", res);
query.bindValue(":statut",statut );

query.bindValue(":idEtudiant", idEtudiant);

return    query.exec();
}


QSqlQueryModel * places::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from places");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_P"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("statut "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_S"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("idEtudiant"));
    return model;
}

bool places::supprimer(int num)
{
QSqlQuery query;
QString res= QString::number(num);
query.prepare("Delete from PLACES where NUMP = :num_P");
query.bindValue(":num_P", res);
return    query.exec();
}


 bool places::modifier(int num)
 {
     QSqlQuery query ;
     query.prepare("UPDATE STATUS=occupe FROM PLACES  where NUM_P = :num_P") ;
     query.bindValue(":num_P", num);
     return    query.exec();
 }

 bool places:: reservation(int num ,int  idd)
 {
     QSqlQuery query ;
     query.prepare("UPDATE IDETUDIANTS=:idetud FROM PLACES where NUM_P = :num_P") ;
     query.bindValue(":num_P", num);
     query.bindValue(":idetud",idd );
     return    query.exec();

 }

bool places::supprimerR(int num)
{
    QSqlQuery query ;
    query.prepare("UPDATE STATUS=libre FROM PLACES  where NUM_P = :num_P") ;
    query.bindValue(":num_P", num);
    return    query.exec();
}

QSqlQueryModel * places::consulter()
{
    QSqlQueryModel * model= new  QSqlQueryModel();
    model->setQuery("SELECT * FROM PLACE WHERE STATUT='0'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_P"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("statut"));

    return  model;
}
