#include "note_menu.h"
#include "menu.h"
#include "connexion.h"
#include "QSqlQueryModel"
#include "QSqlQuery"


note_menu::note_menu()
{

}

note_menu::note_menu(QString daate , int note)
{
    this->daate=daate ;
    this->note=note ;
}

bool note_menu::ajouter_note_menu()
{
QSqlQuery query;
QString res= QString::number(note);
query.prepare("INSERT INTO note_menu (DATE, NOTE ) "
                    "VALUES (:daate, :note)");
//query.bindValue(":id", res);
query.bindValue(":date", daate);
query.bindValue(":note", note);

return    query.exec();
}

QSqlQueryModel *note_menu::afficher_note_menu()
{QSqlQueryModel * model= new QSqlQueryModel();
 QString str="SELECT *FROM  note_menu";
model->setQuery(str);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("daate"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("note"));


    return model;
}

  int note_menu ::calculer_note(QString daate)

  {
      QSqlQuery qry;
      qry.prepare("select * from note_menu where daate='"+daate+"'" );
     int notetot=0 ;
      int note2 ;
      int i =0 ;
      if(qry.exec())
       {

          while (qry.next())
            {
              note2  = qry.value(1).toInt();
               notetot = notetot+ note2 ;
               i++ ;
            }

  }
      notetot = notetot/i ;
      return notetot ;
}
