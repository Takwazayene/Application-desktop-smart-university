#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "menu.h"

namespace Ui {
class menuWindow;
}

class menuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit menuWindow(QWidget *parent = nullptr);
    ~menuWindow();

private slots:
    void on_ajouter_clicked();

    void on_pushButton_chercherMenu_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_trierParJours_clicked();

    void on_pushButton_trierParId_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_calculer_clicked();

    void on_pushButton_afficher_note_clicked();

private:
    Ui::menuWindow *ui;
    Menu tmpMenu;
    Menu *tmpMenuu ;

};

#endif // MENUWINDOW_H
