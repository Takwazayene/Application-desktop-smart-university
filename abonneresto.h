#ifndef ABONNERESTO_H
#define ABONNERESTO_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class abonneResto
{public:
    abonneResto();
    abonneResto(int,QString,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
    bool ajouter();
    bool modifier(int,QString,QString);
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * sortid();
    QSqlQueryModel * sortnom();
    QSqlQueryModel * chercher_etudiant(int);
    int calculer_presence() ;

private:
    QString nom,prenom ,  type_pension , date_abo;
    int id;
};
#endif // ABONNERESTO_H
