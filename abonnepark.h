#ifndef ABONNEPARK_H
#define ABONNEPARK_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class abonnePark
{
public:
    abonnePark();
    abonnePark(int , int) ;
    int get_idEtudiant();
    int get_nbre_Reservation();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);

private:
    int idEtudiant , nbre_Reservation;

};

#endif // ABONNEPARK_H
