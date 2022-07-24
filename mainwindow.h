#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "etudiant.h"
#include "places.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_P_clicked();

    void on_pushButton_EspaceEtu_clicked();

    void on_pushButton_nouvEtu_clicked();

    void on_pushButton_retour1_clicked();

    void on_pushButton_retour_clicked();

    void on_pushButton_valid_clicked();

    void on_pushButton_retour3_clicked();

    void on_pushButton_addPlace_clicked();

    void on_pushButton_consulterPlace_clicked();

    void on_pushButton_suppPlace_clicked();

    void on_pushButton_valid16_clicked();

    void on_pushButton_retour16_clicked();

    void on_pushButton_valid15_clicked();

    void on_pushButton_flec11_clicked();

    void on_pushButton_clicked();

    void on_validd_clicked();

    void on_pushButton_flec9_clicked();

    void on_pushButton_connexionProf_clicked();

    void on_pushButton_nouvProf_clicked();

    void on_pushButton_flec8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_flec7_clicked();

    void on_pushButton_valid10_clicked();

    void on_pushButton_flec6_clicked();

    void on_pushButton_valid9_clicked();

    void on_pushButton_flec5_clicked();

    void on_pushButton_valid3_clicked();

    void on_pushButton_flec4_clicked();

    void on_pushButton_flec3_clicked();

    void on_pushButton_faireReserv_clicked();

    void on_pushButton_consulterReserv_clicked();

    void on_pushButton_suppReserv_clicked();

    void on_pushButton_flec1_clicked();

    void on_pushButton_connectEtu_clicked();

    void on_pushButton_espProf_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_flec10_clicked();

    void on_pushButton_mail_clicked();

    void on_pushButton_reserv_clicked();

    void on_pushButton_comment_clicked();

private:
    Ui::MainWindow *ui;
    places tmpplace;
};

#endif // MAINWINDOW_H
