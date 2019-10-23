#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_inputLetra_returnPressed();

    void on_frangarButton_clicked();

    void on_pushButton_clicked();

    void on_livesLCD_overflow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
