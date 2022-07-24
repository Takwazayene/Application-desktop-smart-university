#ifndef SALLLES_H
#define SALLLES_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class salles
{
public:
    salles();
    salles(int ,QString ) ;
    int get_numSalle();
    QString get_nomBloc() ;

private:
    int numSalle  ;
    QString nomBloc ;

};

#endif // SALLLES_H
