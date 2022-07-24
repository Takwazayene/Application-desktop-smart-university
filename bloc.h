#ifndef BLOC_H
#define BLOC_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class bloc
{
public:
    bloc();
    bloc(QString ,int ,int) ;
    QString get_nomBloc() ;
    int get_idEtudiant();
    int get_etage();
private:
    int etage , idEtudiant ;
    QString nomBloc ;


};

#endif // BLOC_H
