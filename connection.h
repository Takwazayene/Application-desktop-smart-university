#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class connection
{
public:
    connection();
    bool createconnect();
    QSqlDatabase getbase();
private:
    QSqlDatabase db;
};

#endif // CONNECTION_H
