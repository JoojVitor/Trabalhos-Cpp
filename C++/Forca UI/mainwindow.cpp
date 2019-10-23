#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <forca.h>
using std::string;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

    forca game;

void MainWindow::on_frangarButton_clicked()
{
    QMessageBox::StandardButton reply;
    QMessageBox msg;
    reply = msg.question(this, "Sair", "Deseja mesmo arregar?", msg.Yes|msg.No);
    if(reply == msg.Yes){
        this->close();
    }
}

void MainWindow::on_inputLetra_returnPressed()
{
    QString letra = ui->inputLetra->text().toUpper();
    ui->displayLetras->setText(game.secretWord(letra));
}


void MainWindow::on_pushButton_clicked()
{
    QString word = game.getString();
    ui->labelNickname->setText(word);
    for(int i = 0; i < word.length()-1; i++){
        word.replace(i, 1, '*');
    }
    ui->displayLetras->setText(word);
}


