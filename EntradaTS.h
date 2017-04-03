#ifndef __Compilador__EntradaTS__
#define __Compilador__EntradaTS__

#include <stdio.h>
#include <QString>
using namespace std;

class EntradaTS {

public:
    EntradaTS (QString lexema, QString token, int token_id);
    QString lexema;
    QString tokenType; /*ID, CTE, CADENA, ETC*/
    QString tipo; /*INT, FLOAT*/
    int value1;
    float value2;
    int token_id;
    bool usada;

    /*Para impresion por pantalla*/
    QString toString();

};

#endif /* defined(__Compilador__EntradaTS__) */
