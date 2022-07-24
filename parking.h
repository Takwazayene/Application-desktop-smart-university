#ifndef PARKING_H
#define PARKING_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class parking
{
public:
    parking();
    parking(QString ,int ,int ,int) ;
    int get_nbre_Secteur();
    int get_idEtudiant();
    int get_nbre_place();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);

 private:

    int nbre_Secteur , nbre_place , idEtudiant ;
     QString nomPark ;


};

#endif // PARKING_H
