#ifndef RECHERCHE_H
#define RECHERCHE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class recherche
{
public:
    recherche();
    recherche(QString);
   QString getid(){return id;}

bool rechercher(QString);
    QSqlqueryModel * rechercher(QString);
private:
    QString id;
};

#endif // RECHERCHE_H
