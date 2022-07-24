#include "menu.h"
#include "connexion.h"

#include <QDebug>
Menu::Menu()
{
id=0;
jours="";
repas="";
dessert="";
note=0;
}
Menu::Menu(int id,QString jours,QString repas ,QString dessert,QString daate)
{
  this->id=id;
  this->jours=jours;
  this->repas=repas;
  this->dessert=dessert;
   this->daate=daate ;
 // this->note= note ;
}


bool Menu::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO menu (ID, JOURS, REPAS,DESSERT, DAATE) "
                    "VALUES (:id, :jours, :repas, :dessert, :daate)");
query.bindValue(":id", res);
query.bindValue(":jours", jours);
query.bindValue(":repas", repas);
query.bindValue(":dessert", dessert);
query.bindValue(":date", daate);
//query.bindValue(":note", note);

return    query.exec();
}

QSqlQueryModel * Menu::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from menu");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Jours "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("repas"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Dessert "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("daate "));
//model->setHeaderData(4, Qt::Horizontal, QObject::tr("Note"));
    return model;
}

bool Menu::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from menu where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel *Menu::chercher_menu(int id)
{
QSqlQueryModel *model= new QSqlQueryModel();
QString str ;
//Connexion Conn;
//Conn.ouvrirConnexion();
//Conn.openBD();
if(id== NULL){
    str="SELECT * FROM  menu";
}

     str="select * from menu where ID ="+QString::number(id);
    model->setQuery(str);
//Conn.fermerConnexion() ;
    return model;
}

QSqlQueryModel *Menu ::chercher_menu2 (QString daate)
{
    QSqlQueryModel *model= new QSqlQueryModel();
     QString str="select * from menu where daate ='"+daate+"'";
     model->setQuery(str);
     return model;
}

QSqlQueryModel *Menu::sortid()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from menu ORDER BY ID");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("jours"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("repas"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("dessert"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date"));

    return model;
}

QSqlQueryModel *Menu ::chercher_plat(QString repas)
{
    QSqlQueryModel *model= new QSqlQueryModel();
     QString str="select * from menu where repas ='"+repas+"'";
     model->setQuery(str);
     return model;

}

QSqlQueryModel * Menu::recherche_avance(const QString &str)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from menu where(ID LIKE '"+str+"%')");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("jours "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("repas"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("dessert"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("date"));

    return model;
}
