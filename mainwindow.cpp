#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi( this );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_P_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_EspaceEtu_clicked()
{

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_nouvEtu_clicked()
{

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_retour1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_valid_clicked()
{
    QString nom = ui->lineEdit_nomEtu->text();
    QString prenom= ui->lineEdit_prenomEtu->text();
    QString mdp = ui->lineEdit_mdpEtu->text();
    QString classe = ui->lineEdit_classeEtu->text();
    int id = ui->lineEdit_IDEtu->text().toInt();

   Etudiant e(id,mdp,nom,prenom,classe);
   bool test =e.ajouter();
       if(test)
           {
               QMessageBox::information(nullptr,QObject::tr("Ajouter un Etudiant"),
                                     QObject::tr("Etudiant Ajouter avec Succes.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel );
                ui->stackedWidget->setCurrentIndex(4);

           }
           else
           {
               QMessageBox::critical(nullptr,QObject::tr("Ajouter un Etudiant"),
                                     QObject::tr("Etudiant non ajouter.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel );
           }
   }



void MainWindow::on_pushButton_retour3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_addPlace_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_pushButton_consulterPlace_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_pushButton_suppPlace_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_valid16_clicked()
{
    ui->tableView_AfficherPlace->setModel(tmpplace.afficher());

}

void MainWindow::on_pushButton_retour16_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_valid15_clicked()
{
     int num = ui->lineEdit_7->text().toInt();
     bool test = tmpplace.supprimer(num);
     if(test)
         {
             QMessageBox::information(nullptr,QObject::tr("Supprimer une Place"),
                                   QObject::tr("Place Supprimer avec Succes.\n"
                                               "Click Cancel to exit."),QMessageBox::Cancel );


         }
         else
         {
             QMessageBox::critical(nullptr,QObject::tr("Supprimer une Place"),
                                   QObject::tr("Place non supprimer.\n"
                                               "Click Cancel to exit."),QMessageBox::Cancel );
         }

}

void MainWindow::on_pushButton_flec11_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_clicked()
{
    int num = ui->lineEdit_3->text().toInt();
    int statut = ui->lineEdit_4->text().toInt();
    int id = ui->lineEdit_6->text().toInt();

    places p(num,statut,id);
    bool test = p.ajouter();
    if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("Ajouter une Place"),
                                  QObject::tr("Place Ajouter avec Succes.\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel );
             ui->stackedWidget->setCurrentIndex(17);

        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Ajouter une Place"),
                                  QObject::tr("Place non ajouter.\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel );
        }


}

void MainWindow::on_validd_clicked()
{
    int id = ui->lineEdit_5->text().toInt();

   Etudiant e;
   bool test =e.connexion(id);
       if(test)
           {
               QMessageBox::information(nullptr,QObject::tr("connexion Professeur"),
                                     QObject::tr("connexion effectué avec Succes.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel );
                ui->stackedWidget->setCurrentIndex(17);

           }
           else
           {
               QMessageBox::critical(nullptr,QObject::tr("connexion Professeur"),
                                     QObject::tr("echec de la connexion.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel );
           }

}

void MainWindow::on_pushButton_flec9_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_connexionProf_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_nouvProf_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_flec8_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    int num = ui->lineEdit_numSupp_Reserv->text().toInt();

    bool test1=tmpplace.supprimerR(num);
    if(test1)
    {
        QMessageBox::information(nullptr,QObject::tr("Supprimer reservation"),
                              QObject::tr("reservation supprimer avec Succes.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel );


    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Supprimer reservation"),
                              QObject::tr("suppresion echoué .\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel );
    }
}

void MainWindow::on_pushButton_flec7_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_valid10_clicked()
{
 ui->tableView_AfficherRes->setModel(tmpplace.afficher());
}

void MainWindow::on_pushButton_flec6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_valid9_clicked()
{
    int num= ui->lineEdit_2->text().toInt();
    int idd= ui->lineEdit_EtuReserv->text().toInt();

    places p ;
    bool test=p.reservation(num , idd);
        if(test)
            {
            bool test1=p.modifier(num);
            if(test1)
            {
                QMessageBox::information(nullptr,QObject::tr("reservation"),
                                      QObject::tr("REVERSER avec Succes.\n"
                                                  "Click Cancel to exit."),QMessageBox::Cancel );

                 ui->stackedWidget->setCurrentIndex(4);
            }

            }
            else
            {
                QMessageBox::critical(nullptr,QObject::tr("reservation"),
                                      QObject::tr("reservation echoué .\n"
                                                  "Click Cancel to exit."),QMessageBox::Cancel );
            }
     ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_flec5_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_valid3_clicked()
{

    int id = ui->lineEdit_IDEtu->text().toInt();

   Etudiant e;
   bool test =e.connexion(id);
       if(test)
           {
               QMessageBox::information(nullptr,QObject::tr("connexion etudiant"),
                                     QObject::tr("connexion effectué avec Succes.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel );
                ui->stackedWidget->setCurrentIndex(4);

           }
           else
           {
               QMessageBox::critical(nullptr,QObject::tr("connexion Etudiant"),
                                     QObject::tr("echec de la connexion.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel );
           }

}

void MainWindow::on_pushButton_flec4_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_flec3_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_faireReserv_clicked()
{
     ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_consulterReserv_clicked()
{
     ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_suppReserv_clicked()
{
     ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_flec1_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_connectEtu_clicked()
{
     ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_espProf_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_pushButton_flec10_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_mail_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_reserv_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_comment_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
