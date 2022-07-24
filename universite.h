#ifndef UNIVERSITE_H
#define UNIVERSITE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class universite
{
public:
    universite();
    universite(int ,int , int ) ;
    int get_nbre_classe();
    int get_nbre_bloc();
    int get_idUniversite();


private:
    int nbre_classe , idUniversite , nbre_bloc  ;
    QString nomBloc ;

};
#endif // UNIVERSITE_H
