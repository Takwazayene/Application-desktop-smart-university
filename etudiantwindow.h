#ifndef ETUDIANTWINDOW_H
#define ETUDIANTWINDOW_H

#include <QMainWindow>

namespace Ui {
class etudiantWindow;
}

class etudiantWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit etudiantWindow(QWidget *parent = nullptr);
    ~etudiantWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_affichermenu_clicked();

    void on_pushButton_notezmenu_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::etudiantWindow *ui;
};

#endif // ETUDIANTWINDOW_H
