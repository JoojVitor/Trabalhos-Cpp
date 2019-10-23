//esse mesmo v.02
#ifndef FICHA_H
#define FICHA_H

class ficha{
public:
    int in;
    int jg;
    char ch;
    void setFicha(char cor, int i, int j);
    //void retVencedor(int t1, int t2, int t3, int t4, int t5, int t6);
    void retVencedor(int *t);
};

#endif // FICHA_H
