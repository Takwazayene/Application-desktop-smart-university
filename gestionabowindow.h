#ifndef GESTIONABOWINDOW_H
#define GESTIONABOWINDOW_H

#include <QMainWindow>
#include "abonneresto.h"

namespace Ui {
class gestionAboWindow;
}

class gestionAboWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestionAboWindow(QWidget *parent = nullptr);
    ~gestionAboWindow();

private slots:
    void on_Retour_clicked();

    void on_pb_ajouter_clicked();

    void on_pushButton_calculernbrepresence_destroyed(QObject *arg1);

    void on_pushButton_calculernbrepresence_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_trier_id_clicked();

    void on_pb_supprimer_clicked();

    void on_modifier_etu_clicked();

private:
    Ui::gestionAboWindow *ui;
    abonneResto tmpabonne;
};

#endif // GESTIONABOWINDOW_H
