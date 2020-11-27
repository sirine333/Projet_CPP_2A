#include "colloborateur.h"


colloborateur::colloborateur()
{
   id=0;
   adresse="";
   email="";
   marque="";
   numero=0;

}
colloborateur::colloborateur(int i,QString a,QString e,QString m,int n)
{
    id=i;
    adresse=a;
    email=e;
    marque=m;
    numero=n;

}
bool colloborateur::ajouter(){
    QSqlQuery query ;

    query.prepare("INSERT INTO colloborateur(ID,adresse,email,marque,numero)"
                  "VALUES(:id,:adresse,:email,:marque,:numero)");
    query.bindValue(":id",id);
    query.bindValue(":adresse",adresse);
    query.bindValue(":email",email);
    query.bindValue(":marque",marque);
    query.bindValue(":numero",numero);
    return query.exec();

}
QSqlQueryModel * colloborateur::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from colloborateur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("marque"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("numero"));
    return model;




}
bool colloborateur::supprimer(int ide){

    QSqlQuery query;
    QString ids=QString::number(ide);
    query.prepare("delete from colloborateur where ID = :id");
    query.bindValue(":id",ids);
    return query.exec();
}
bool colloborateur::modifier(int ide){
    QSqlQuery query;
    QString ids=QString::number(ide);
    query.prepare("update colloborateur set id=:ids,adresse=:adresse,email=:email,marque=:marque,numero=:numero WHERE id:=ids");
    query.bindValue(":id",ids);
    query.bindValue(":adresse",adresse);
    query.bindValue(":email",email);
    query.bindValue(":marque",marque);
    query.bindValue(":numero",numero);
    return query.exec();


}
QSqlQueryModel * colloborateur::rechercher(QString id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from colloborateur where id LIKE '"+id+"%d' or adresse LIKE '"+id+"%' or adresse LIKE '"+id+"%' or email LIKE '"+id+"%' or marque LIKE '"+id+"%' or numero LIKE '"+id+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("marque"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("numero"));
    return model;
}
QSqlQueryModel * colloborateur::trierA()
{
    QSqlQuery * q=new QSqlQuery();
    QSqlQueryModel * model=new QSqlQueryModel();
    q->prepare("SELECT * FROM colloborateur order by id ASC");
    q->exec();
    model->setQuery(*q);
    return model;

}
QSqlQueryModel * colloborateur::trierB()
{
    QSqlQuery * q=new QSqlQuery();
    QSqlQueryModel * model=new QSqlQueryModel();
    q->prepare("SELECT * FROM colloborateur order by id DESC");
    q->exec();
    model->setQuery(*q);
    return model;

}
