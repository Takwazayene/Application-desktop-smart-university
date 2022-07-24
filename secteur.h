#ifndef SECTEUR_H
#define SECTEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class secteur
{
public:
    secteur();
    secteur(int , int ,QString ,int) ;
    int get_idEtudiant();
    int get_nbre_Place();
     int get_num_S();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    int num_S ,nbre_Place ,idEtudiant;
    QString nomPark ;

};

#endif // SECTEUR_H
