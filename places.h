#ifndef PLACES_H
#define PLACES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class places
{
public:
    places();
    places(int ,int ,int) ;

    int get_idEtudiant();
    int get_nbre_num_P();
    int get_statut() ;

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimerR(int);
    bool supprimer(int);
    bool modifier(int ) ;
    bool reservation(int ,int ) ;
    QSqlQueryModel * consulter();

private:
    int num_P  , idEtudiant , statut;


};

#endif // PLACES_H
