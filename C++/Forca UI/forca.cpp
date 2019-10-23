#include <iostream>
#include <QString>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <QFile>
#include <forca.h>

forca::forca(){
    palavra = "A";
    palavraX = '*';
    vidas = 5;
    player = "unknown";
    minutos = 0;
    segundos = 0;
}

int forca::livesCount(){
    return vidas;
}

QString forca::getString(){

    //Users/administrador/Desktop/Nova pasta/projetos-Qt/forca/palavras.txt
    //home/puc/Área de Trabalho/forca
    QFile file("/home/puc/Área de Trabalho/forca/palavras.txt");
    QString linha;
    file.open(QFile::ReadOnly|QFile::Text);
    srand(time(NULL));
    for(int i = 0; i < rand() % 23; i++){
        linha = file.readLine();
        palavra = linha;
    }
    return palavra;
}

QString forca::secretWord(QString let){

    for(int i = 0; i < palavra.length()-1; i++){
        if(let == palavra.mid(i, 1)){
            palavraX.replace(i, 1, let);
        }else{
            vidas--;
        }
    }
    return palavraX;
}
