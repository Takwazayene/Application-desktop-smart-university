#include "etudiant.h"
#include <QDebug>

Etudiant::Etudiant()
{
idEtudiant=0;
nom="";
prenom="";
mdp="" ;
classe="";
}
Etudiant::Etudiant (int idEtudiant,QString mdp,QString nom ,QString prenom, QString classe)
{
  this->idEtudiant=idEtudiant;
  this->nom=nom;
  this->prenom=prenom;
  this->mdp=mdp ;
    this->classe=classe ;
}

QString Etudiant::get_nom(){return  nom;}
QString Etudiant::get_prenom(){return prenom;}
int Etudiant::get_id(){return  idEtudiant;}
QString Etudiant::get_mdp() {return  mdp;};

bool Etudiant::ajouter()
{
QSqlQuery query;
QString res= QString::number(idEtudiant);
query.prepare("INSERT INTO etudiants (IDETUDIANTS, NOM, PRENOM ,MDP,CLASSE) "
                    "VALUES (:idEtudiant, :nom, :prenom, :mdp,:classe )");
query.bindValue(":idEtudiant", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":mdp", mdp);
query.bindValue(":classe",classe);

return    query.exec();
}

QSqlQueryModel * Etudiant::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from etudiants");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IdEtudiants"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mdp"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numsalle"));
    return model;
}

bool Etudiant::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from etudiants where ID = :idEtudiant");
query.bindValue(":idEtudiant", res);
return    query.exec();
}

 bool Etudiant:: connexion(int idd)
 {
    QSqlQuery query;
    QString res= QString::number(idd) ;
    query.prepare("SELECT IDETUDIANTS FROM ETUDIANTS where IDETUDIANTS= : idEtudiant") ;
    query.bindValue(":idEtudiant", res);
    return    query.exec();
 }

