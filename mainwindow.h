#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "colloborateur.h"
#include"categories.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include<QPainter>
#include<QPrinter>
#include<QPrintDialog>
#include <QDebug>


QT_BEGIN_MOC_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
   // void on_pushButton_Ajouter_clicked();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_Supprimer_clicked();

    void on_label_16_linkActivated(const QString &link);

    void on_pushButton_3_clicked();

    void on_label_17_linkActivated(const QString &link);

    void on_tableView_colloborateur_2_clicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_tabWidget_3_currentChanged(int index);

    void on_pushButton_Supprimer_2_clicked();

    void on_tabcategories_currentChanged(int index);

    void on_tabcategories_tabBarClicked(int index);

    void on_tabWidget_2_currentChanged(int index);

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_5_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked(bool checked);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    colloborateur tempcolloborateur ;
    Categories tempcategories;
    QMediaPlayer* player;

};

#endif // MAINWINDOW_H
