#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <QMainWindow>

namespace Ui {
class integration;
}

class integration : public QMainWindow
{
    Q_OBJECT

public:
    explicit integration(QWidget *parent = nullptr);
    ~integration();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::integration *ui;
};

#endif // INTEGRATION_H
