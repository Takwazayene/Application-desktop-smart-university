#ifndef MENU_H
#define MENU_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Menu
{public:
    Menu();
    Menu (int,QString,QString,QString,QString);
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
   bool supprimer(int);
   QSqlQueryModel * chercher_menu(int);
   QSqlQueryModel * chercher_menu2(QString) ;
   QSqlQueryModel * chercher_plat(QString) ;
   QSqlQueryModel * sortid();
   QSqlQueryModel *recherche_avance(const QString &str);
private:
    int id;
    QString jours;
    QString repas;
    QString dessert ;
    QString daate ;


    int note ;

};
#endif // MENU_H
