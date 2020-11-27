#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"colloborateur.h"
#include"categories.h"
#include "QPushButton"
#include <QPainter>
#include<QPrinter>
#include<QPrintDialog>
#include<QDebug>
#include <QtPrintSupport/QPrinter>
#include<QFileDialog>
#include"QMessageBox"
MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent)

    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_colloborateur->setModel(tempcolloborateur.afficher());
    ui->tableView_Categories->setModel(tempcategories.afficher());
    //sound
    player=new QMediaPlayer(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    int id=ui -> lineEdit->text().toInt();
    QString adresse=ui->lineEdit_2->text();
    QString email=ui->lineEdit_3->text();
   QString marque=ui->lineEdit_4->text();
    int numero=ui->lineEdit_5->text().toInt();
    colloborateur e(id,adresse,email,marque,numero);
    bool test=e.ajouter();
    if (test)
    {
            ui->tableView_colloborateur->setModel(tempcolloborateur.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        //button sound
            player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Downloads/click.mp3"));
            player->play();
            qDebug()<<player ->errorString();


}
else

QMessageBox::critical(nullptr, QObject::tr("ajout"),
            QObject::tr("ajout echoue.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_pushButton_3_clicked()
{

    int id=ui -> lineEdit_17->text().toInt();
    QString domaine=ui->lineEdit_21->text();

    Categories e(id,domaine);
    bool test=e.ajouter();
    if (test)
    {
            ui->tableView_Categories->setModel(tempcategories.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout"),
                    QObject::tr("ajout avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}
else

QMessageBox::critical(nullptr, QObject::tr("ajout"),
            QObject::tr("ajout echoue.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_Supprimer_clicked()
{
    int id=ui->lineEdit->text().toInt();
    bool test=tempcolloborateur.supprimer(id);
    if(test){
        ui->tableView_colloborateur->setModel(tempcolloborateur.afficher());
        QMessageBox::information(nullptr,QObject::tr("Suppression"),
                QObject::tr("suppresion avec succes.\n""click cancel to exit."),QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("suppression"),
                              QObject::tr("suppression echoue .\n""Click cancel to exit."),QMessageBox::Cancel);

    }
}
void MainWindow::on_pushButton_Supprimer_2_clicked()
{
    int id=ui->lineEdit_17->text().toInt();
    bool test=tempcategories.supprimer(id);
    if(test){
        ui->tableView_Categories->setModel(tempcategories.afficher());
        QMessageBox::information(nullptr,QObject::tr("Suppression"),


                                 QObject::tr("suppresion avec succes.\n""click cancel to exit."),QMessageBox::Cancel);
        //button sound
            player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Downloads/click.mp3"));
            player->play();
            qDebug()<<player ->errorString();
    }

    else{
        QMessageBox::critical(nullptr,QObject::tr("suppression"),
                              QObject::tr("suppression echoue .\n""Click cancel to exit."),QMessageBox::Cancel);

    }
}


void MainWindow::on_pushButton_2_clicked()
{
    int id=ui -> lineEdit->text().toInt();
    QString adresse=ui->lineEdit_2->text();
    QString email=ui->lineEdit_3->text();
   QString marque=ui->lineEdit_4->text();
   int numero = ui->lineEdit_5->text().toInt();
   colloborateur e(id,adresse,email,marque,numero);
   bool test=e.modifier(id);
   if(test)
   {
       ui->tableView_colloborateur->setModel(tempcolloborateur.afficher());//refresh
       QMessageBox::information(nullptr,QObject::tr("modifier"),
               QObject::tr("Modification avec succes.\n""click cancel to exit."),QMessageBox::Cancel);


       ui->lineEdit->clear();
       ui->lineEdit_2->clear();
       ui->lineEdit_3->clear();
       ui->lineEdit_4->clear();
       ui->lineEdit_5->clear();
      //button sound
           player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Downloads/click.mp3"));
           player->play();
           qDebug()<<player ->errorString();


   }
   else
       QMessageBox::critical(nullptr,QObject::tr("modifier"),
                             QObject::tr("Modification echoue .\n""Click cancel to exit."),QMessageBox::Cancel);

   }


void MainWindow::on_pushButton_4_clicked()
{
    int id=ui -> lineEdit_17->text().toInt();
    QString domaine=ui->lineEdit_21->text();

   Categories e(id,domaine);
   bool test=e.modifier(id);
   if(test)
   {
       ui->tableView_Categories->setModel(tempcategories.afficher());//refresh
       QMessageBox::information(nullptr,QObject::tr("modifier"),
               QObject::tr("Modification avec succes.\n""click cancel to exit."),QMessageBox::Cancel);


       ui->lineEdit_17->clear();
       ui->lineEdit_21->clear();
       //button sound
           player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Downloads/click.mp3"));
           player->play();
           qDebug()<<player ->errorString();


   }
   else
       QMessageBox::critical(nullptr,QObject::tr("modifier"),
                             QObject::tr("Modification echoue .\n""Click cancel to exit."),QMessageBox::Cancel);

   }



void MainWindow::on_pushButton_5_clicked()
{

    QString id=ui-> lineEdit_14->text();

    ui->tableView_colloborateur->setModel( tempcolloborateur.rechercher(id));
    //button sound
        player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Downloads/click.mp3"));
        player->play();
        qDebug()<<player ->errorString();


}


void MainWindow::on_radioButton_clicked()
{
    ui->tableView_colloborateur->setModel(tempcolloborateur.trierA());
    //button sound
        player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Downloads/click.mp3"));
        player->play();
        qDebug()<<player ->errorString();
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->tableView_colloborateur->setModel(tempcolloborateur.trierB());
    //button sound
        player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Downloads/click.mp3"));
        player->play();
        qDebug()<<player ->errorString();
}




void MainWindow::on_pushButton_6_clicked()
{
    QPrinter rd;
    QPrintDialog d(&rd,this);
    d.setWindowTitle("Print livre");
    d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if(d.exec() != QDialog::Accepted)
        return;
}

