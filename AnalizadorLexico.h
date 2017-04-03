#ifndef __Compilador__AnalizadorLexico__
#define __Compilador__AnalizadorLexico__

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <list>
#include <Qlist>
#include <QMap>
#include <QString>
#include "EntradaTS.h"
#include "TabladeSimbolos.h"
#include "y.tab.h"

using namespace std;

#define F -2 //ESTADO FINAL
#define FST -3 //ESTADO FINAL SIN TOKEN
#define TOKEN_INVALIDO -3
#define FINARCHIVO 19

static const int matrizTE [20][21] ={

/*    @   l  dig  L   +-  *   =   <   >  ()  /   \b  \n  'e' 'E'  _  'i'  .   '   $  OTRO
                                         ,;      \t                             (EOF)
                                         {}                                               */
    { 1 , 2 , 3 , 5 , 6 , 6 , 7 , 8 , 9 ,10 ,11 , 0 , 0 , 2 , 5 ,FST, 2 ,19 ,18 ,FST,FST},
    {FST, 2 ,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST, 2 ,FST,FST, 2 ,FST,FST,FST,FST},
    { 2 , 2 , 2 , F , F , F , F , F , F , F , F , F , F , 2 , F , F , 2 , F , F , F , F },
    {FST,FST, 3 ,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,15 ,15 , 4 ,FST,14 ,FST,FST,FST},
    {FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST, F ,FST,FST,FST,FST},
    { F , F , F , 5 , F , F , F , F , F , F , F , F , F , F , 5 , F , F , F , F , F , F },
    { F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F },
    { F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F },
    { F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F },
    { F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F },
    { F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F },
    { F , F , F , F , F , F , F , F , F , F ,12 , F , F , F , F , F , F , F , F , F , F },
    {12 ,12 ,12 ,12 ,12 ,12 ,12 ,12 ,12 ,12 ,13 ,12 ,12 ,12 ,12 ,12 ,12 ,12 ,12 ,FST,12 },
    {12 ,12 ,12 ,12 ,12 ,12 ,12 ,12 ,12 ,12 ,FST,12 ,12 ,12 ,12 ,12 ,12 ,12 ,12 ,FST,12 },
    { F , F ,14 , F , F , F , F , F , F , F , F , F , F ,15 ,15 , F , F , F , F , F , F },
    {FST,FST,16 ,FST,17 ,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST},
    { F , F ,16 , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F , F ,FST, F },
    {FST,FST,16 ,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST},
    {18 ,18 ,18 ,18 ,18 ,18 ,18 ,18 ,18 ,18 ,18 ,18 ,FST,18 ,18 ,18 ,18 ,18 , F ,FST,18 },
    {FST,FST,14 ,FST,FST,FST,FST,FST,FST,FST,FST,FST,FST,15 ,15 ,FST,FST,FST,FST,FST,FST}

};

class AnalizadorLexico {

private:

    int lineas;
    list<char> entrada;
    list<QString> * warnings;
    list<QString> * errores;
    QMap <QString,int> palabrasReservadas;
    TablaDeSimbolos * tablaDeSimbolos;
    int (AnalizadorLexico::*matrizAS [20][21])(QString*, char);

    //solo para facilitar la impresión final de los tokens
    list<QString> tokensReconocidos;
    void imprimirToken (QString * buffer, int devolucion);


    /** Otros métodos privados **/

    void error(string str);
    void inicializarMatrizAs();
    void inicializarPR ();
    float toFloat (QString * buffer);




    //Devuelve la columna correspondiente al caracter leído
    int columna (char c);


    /** Acciones Semánticas **/

    // Reconoce un identificador. Devuelve ultimo char a la entrada y chequea longitud.
    int accionS1(QString * buffer, char c);

    // Sólo reconoce un identificador. Se utiliza al llegar a EOF.
    int accionS1F(QString * buffer, char c);

    // Reconoce palabra reservada. Devuelve ultimo char a la entrada.
    int accionS2(QString * buffer, char c);

    // Sólo reconoce palabra reservada. Se utiliza al llegar a EOF.
    int accionS2F(QString * buffer, char c);

    // Reconoce una constante
    int accionS3(QString * buffer, char c);

    // Reconoce operadores dobles (<>, <=, ==, etc).
    int accionS4(QString * buffer, char c);

    // Acción semantica al reconocer operadores simples (=, +, -, "(", ")", etc)
    int accionS5(QString * buffer, char c);

    // Reconoce operadores simples cuando se llega a EOF.
    int accionS5F(QString * buffer, char c);

    // Reconoce y verifica constantes flotantes.
    int accionS6(QString * buffer, char c);

    // Reconoce y verifica constantes flotantes cuando se llega a EOF. /*COMPLETAR/
    int accionS6F(QString * buffer, char c);

    // Reconoce y verifica una cadena. Consume ultimo char y actualiza la tabla de símbolos
    int accionS7(QString * buffer, char c);

    // Acción semántica vacía
    int accionSV(QString * buffer, char c);

    // Sólo suma las lineas leidas
    int accionSL(QString * buffer, char c);

    // Sólo almacena el char leído al buffer. Para pasos intermedios
    int accionSA(QString * buffer, char c);

    // Reconoce error en una cadena.
    int accionSEC(QString * buffer, char c);

    // Acción que anuncia error de token invalido.
    int accionSTI(QString * buffer, char c);

    // Acción que anuncia error de identificador.
    int accionSEI (QString *buffer, char c);

    // Acción que anuncia error de constante.
    int accionSECTE (QString *buffer, char c);

    // Acción que anuncia error de constante flotante.
    int accionSEF (QString *buffer, char c);

    // Acción que anuncia error de comentario.
    int accionSECOM (QString *buffer, char c);


public:

    ~AnalizadorLexico();
    AnalizadorLexico (const char * file, list<QString>* warnings, list<QString>* errores, TablaDeSimbolos * ts);
    int lineaActual();
    int yylex(void);

    /*Los tokens se piden de a uno. El siguiente metodo es solo para imprimirlos todos al final*/
    list<QString> getTokens();
};



#endif /* defined(__Compilador__AnalizadorLexico__) */
