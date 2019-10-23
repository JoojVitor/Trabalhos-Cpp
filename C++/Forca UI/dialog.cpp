#include "dialog.h"
#include "ui_dialog.h"
#include <mainwindow.h>
#include <QDialog>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_jogar_clicked()
{
    Dialog janela;
    janela.setModal(true);
    janela.exec();
}
