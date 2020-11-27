#ifndef CATEGORIES_H
#define CATEGORIES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Categories
{
public:
    Categories();
    Categories(int,QString);
   int getID(){return id;}
   QString getdomaine(){return domaine;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    private:
        int id;

    QString domaine;


};

#endif // CATEGORIES_H
