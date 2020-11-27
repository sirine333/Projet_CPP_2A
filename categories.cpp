#include "categories.h"

Categories::Categories()


{
   id=0;
   domaine="";

}
Categories::Categories(int i,QString d)
{
    id=i;
    domaine=d;


}
bool Categories::ajouter(){
    QSqlQuery query ;

    query.prepare("INSERT INTO colloborateur(ID,domaine)"
                  "VALUES(:id,:domaine)");
    query.bindValue(":id",id);
    query.bindValue(":domaine",domaine);
    return query.exec();

}
QSqlQueryModel * Categories ::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from categories");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("domaine"));

    return model;




}
bool Categories::supprimer(int ide){

    QSqlQuery query;
    QString ids=QString::number(ide);
    query.prepare("delete from colloborateur where ID = :id");
    query.bindValue(":id",ids);
    return query.exec();
}
bool Categories::modifier(int ide){
    QSqlQuery query;
    QString ids=QString::number(ide);
    query.prepare("update colloborateur set id=:ids,domaine=:domaine");
    query.bindValue(":id",ids);
    query.bindValue(":domaine",domaine);

    query.exec();


}


