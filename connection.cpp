#include "connection.h"
#include <QDebug>


connection::connection()
{

}
bool connection::createconnect()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("takwa");
    db.setPassword("takwa");

    if(db.open())
    {
        qDebug()<<"ouvert";
        return  true;
    }

    return  false;
}

QSqlDatabase connection::getbase()
{
    return db;
}
