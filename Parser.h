#ifndef PARSER_H
#define PARSER_H
#include "TabladeSimbolos.h"
#include "AnalizadorLexico.h"
#include "GeneradorDeCodigo.h"


class Parser
{
private:

    TablaDeSimbolos * tabladeSimbolos;
    AnalizadorLexico * analizadorLexico;
    list<QString> * errores;
    GeneradorDeCodigo * codGen;
    bool error;
    QStack<QString> tiposArrojados; //contiene los tipos arrojados por las ultimas expresiones. Para comprobacion de tipos

    /** Sólo para imprimir al final **/
    list<QString> reglasEncontradas;


    /** Manejo de sufijos y ambitos **/

    //contiene el sufijo actual
    QString sufijo;

    //<sufijo, cantidad de ambitos en el sufijo>
    QMap <QString, int> ambitos;

    //devuelve el sufijo padre de uno dado por parametro
    QString sufijoPadre(QString var);


    /** Mangling y declaracion de variables **/

    //Contiene el ultimo TIPO usado en una declaración de variable.
    QString tipo;

    //(puntero tabla, tipo). Modifica la tabla. Si ya estaba definida lo notifica
    void declararVariable (QString var,QString tipo);

    //Retorna a que variable se refiere (lexema completo). Vacío si no estaba definida (y lo notifica)
    QString mangle (QString var);

    //Busca la variable y la hace global (nombre_0). Si ya estaba definida tira error.
    void hacerGlobal(QString var);


    /** Otras funciones **/

    void notificar (QString msg);
    void notificar (const char * msg);
    void addRegla (const char * msg);
    bool rangoValido(QString var, bool signo);
    QString negativo(QString var);
    void marcarUsada(QString var);
    void yyerror(QString s);
    int yylex();


public:
    Parser(TablaDeSimbolos * ts, AnalizadorLexico * lex, GeneradorDeCodigo * codGen, list<QString> * err);
    list <QString> getReglasEncontradas();
    bool hasError();
    int yyparse();

};


#endif // PARSER_H


