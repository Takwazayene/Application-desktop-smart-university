#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Etudiant
{public:
    Etudiant();
    Etudiant(int,QString,QString ,QString, QString );
    QString get_nom();
    QString get_prenom();
    int get_id();
    QString get_mdp() ;
    QString  get_nomBloc();
     int get_numSalle() ;
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool ajouter();
    bool connexion(int ) ;
private:
    QString mdp ,nom,prenom , classe;
    int idEtudiant;
};


#endif // ETUDIANT_H
