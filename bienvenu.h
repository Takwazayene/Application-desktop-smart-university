#ifndef BIENVENU_H
#define BIENVENU_H

#include <QMainWindow>

namespace Ui {
class bienvenu;
}

class bienvenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit bienvenu(QWidget *parent = nullptr);
    ~bienvenu();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::bienvenu *ui;
};

#endif // BIENVENU_H
