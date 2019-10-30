#include "mainwindow.h"
#include "ui_mainwindow.h"

static int row = 0;
static QString local = "C:/Users/joao.vitor/Desktop/Nova pasta/Joao/Qt/prototype/";
static QString nome = "itemList.txt";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Projeto 2020 - Prototipo v0.1");
    QFile file(local+nome);
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"ERRO","Erro ao abrir o arquivo");
    }else{
        QTextStream entrada(&file);
        int aux=0;
        int xrow = 0;
        QString txt;
        while(!file.atEnd()){
            ui->mainTableWidget->insertRow(xrow);
            txt = entrada.readLine();
            ui->mainTableWidget->setItem(xrow,0,new QTableWidgetItem(txt));
            aux++;
            txt = entrada.readLine();
            ui->mainTableWidget->setItem(xrow,1,new QTableWidgetItem(txt));
            aux++;
            txt = entrada.readLine();
            ui->mainTableWidget->setItem(xrow,2,new QTableWidgetItem(txt));
            aux++;
            txt = entrada.readLine();
            ui->mainTableWidget->setItem(xrow,3,new QTableWidgetItem(txt));
            aux++;
            txt = entrada.readLine();
            ui->mainTableWidget->setItem(xrow,4,new QTableWidgetItem(txt));
            aux++;
            xrow++;
        }
        file.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputButton_clicked()
{
    QFile file(local+nome);
    if(!file.open(QFile::WriteOnly|QFile::Append)){
        QMessageBox::warning(this,"ERRO","Erro ao abrir o arquivo");
    }else{
        QMessageBox msg;
        QTextStream saida(&file);
        QString item = ui->itemEdit->text();
        ui->itemEdit->clear();
        QString codigo = ui->idEdit->text();
        ui->idEdit->clear();
        QString qtd = ui->qtdEdit->text();
        ui->qtdEdit->clear();
        QString in = ui->inItem->text();
        ui->inItem->clear();
        QString out = ui->outItem->text();
        ui->outItem->clear();
        if(item != "" and codigo != "" and qtd != "" and in != "" and out != ""){
            saida<<item + '\n'<<codigo + '\n'<<qtd + '\n'<<in + '\n'<<out + '\n';
            QTableWidgetItem table;
            ui->mainTableWidget->insertRow(row);
            ui->mainTableWidget->setItem(row,0,new QTableWidgetItem(item));
            ui->mainTableWidget->setItem(row,1,new QTableWidgetItem(codigo));
            ui->mainTableWidget->setItem(row,2,new QTableWidgetItem(qtd));
            ui->mainTableWidget->setItem(row,3,new QTableWidgetItem(in));
            ui->mainTableWidget->setItem(row,4,new QTableWidgetItem(out));
            row++;
            msg.setWindowTitle("Sucesso");
            msg.setText(item + " incluido");
            msg.exec();
            file.flush();
            file.close();
        }else{
            msg.warning(this, "Aviso", "Campos necessários para inclusão do item não foram preenchidos");
        }
    }
}

void MainWindow::on_actionFechar_triggered()
{
    this->close();
}
