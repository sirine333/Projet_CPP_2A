#ifndef COLLOBORATEUR_H
#define COLLOBORATEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class colloborateur
{
public:
    colloborateur();
    colloborateur(int,QString,QString,QString,int);
   int getID(){return id;}
   QString getadresse(){return adresse;}
    QString getmail(){return email;}
    QString getmarque(){return marque;}
    int getnumero(){return numero;}
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * trierA();
    QSqlQueryModel * trierB();
    bool supprimer(int);
    bool modifier(int);

    private:
        int id;

    QString adresse,email,marque;
    int numero;
};

#endif // COLLOBORATEUR_H
