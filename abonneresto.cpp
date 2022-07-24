#include <QDebug>
#include "QSqlQuery"
#include <QString>
#include <QSqlQueryModel>
#include "abonneresto.h"
abonneResto::abonneResto()
{
//id=0;
nom="";
prenom="";
}
abonneResto::abonneResto(int id,QString nom,QString prenom, QString type_pension,QString date_abo)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->type_pension = type_pension ;
  this->date_abo = date_abo ;
}
QString abonneResto::get_nom(){return  nom;}
QString abonneResto::get_prenom(){return prenom;}
int abonneResto::get_id(){return  id;}

bool abonneResto::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO etudiant (ID, NOM, PRENOM,TYPE_PENSION,DATE_ABO) "
                    "VALUES (:id, :nom, :prenom, :type_pension, :date_abo)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":type_pension", type_pension);
query.bindValue(":date_abo", date_abo);

return    query.exec();
}

QSqlQueryModel * abonneResto::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
 QString str="SELECT *FROM  etudiant";
model->setQuery(str);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_pension "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_abo"));

    return model;
}


/*bool Etudiant ::supprimer (int idd)
{QSqlQuery qrt;
    QString str="delete from etudiant where ID= "+QString::number(idd);
    qDebug()<<str;
    bool res = qrt.exec(str);
    return res;

//return(qrt.exec(str));
}*/



bool abonneResto ::supprimer (int id)
{/*QSqlQuery qry;
    //qry.prepare("Delete from etudiant where id= "+QString::number(id));
qry.prepare("Delete from etudiant where nom='"+nom+"'");
    bool res = qry.exec();
    return res;*/

    //****
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from etudiant where ID = :id ");
    query.bindValue(":id", res);
    return    query.exec();

//return(qrt.exec(str));
}

bool abonneResto :: modifier( int id , QString nom , QString prenom)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("update etudiant set ID='"+QString::number(id)+"', nom='"+nom+"', prenom='"+prenom+"' where id="+QString::number(id));
    query.bindValue(":id", res);
    return    query.exec();


}


QSqlQueryModel *abonneResto ::sortid()
{


    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from etudiant ORDER BY ID");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));

    return model;
}


QSqlQueryModel *abonneResto ::sortnom()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from etudiant ORDER BY nom");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));

    return model;
}


QSqlQueryModel *abonneResto::chercher_etudiant(int id)
{
QSqlQueryModel *model= new QSqlQueryModel();
QString str ;
//Connexion Conn;
//Conn.ouvrirConnexion();
//Conn.openBD();

    str="select * from etudiant where ID ="+QString::number(id);
   model->setQuery(str);
//Conn.fermerConnexion() ;
   return model;
}
int abonneResto::calculer_presence()
{

    QSqlQuery qry;
    qry.prepare("select * from etudiant" );


    int i =0 ;
    if(qry.exec())
     {

        while (qry.next())
          {

             i++ ;
          }

}

    return i ;

}










