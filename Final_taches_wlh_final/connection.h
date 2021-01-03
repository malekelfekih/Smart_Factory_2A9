#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>


class connection
{
public:
    connection();
    bool openConn();
    void closeConn(QSqlDatabase mydb);
};

#endif // CONNECTION_H
