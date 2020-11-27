#include "recherche.h"

recherche::recherche()
{   id="";

}
recherche::rechercher(QString i)
{
    id=i;


}

     QSqlQueryModel * recherche ::rechercher(QString id)
    {
    QSqlQueryModel * model=new QSqlQueryModel();
    model->SetQuery("select * from colloborateur where is id like '"+id+"%' or adresse LIKE '"+id+"%' or email like '"+id+"%' or marque like '"+id+"%' or numero like '"+id+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("marque"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("numero"));
    return model;
    }

