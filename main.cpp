#include "TabladeSimbolos.h"
#include "AnalizadorLexico.h"
#include "Parser.h"
#include <iostream>

static list<QString> warnings, errores, tokens, reglasReconocidas;
static TablaDeSimbolos tablaDeSimbolos;
static GeneradorDeCodigo codGen(&tablaDeSimbolos);

/** FUNCIONES AUXILIARES DE IMPRESION **/

void imprimirTokens() {
    cout << "\n\nTokens identificados: \n";
    cout <<     "****** ************** \n\n";
    if (tokens.size()>0) {
        for (list<QString>::iterator it = tokens.begin(); it!= tokens.end(); it++) {
            cout << it->toStdString();
        }
    }
    cout << "\n";
}

void imprimirErrores() {
    cout << "\n\nErrores: " << errores.size() << ". ";
    cout <<   "\n********";
    if (errores.size()>0) {
        for (list<QString>::iterator it = errores.begin(); it!= errores.end(); it++) {
            cout << it->toStdString();
        }
    }
    cout << "\n";
}

void imprimirWarnings() {
    cout << "\nWarnings: " << warnings.size() << ". ";
    cout << "\n*********";
    if (warnings.size()>0) {
        for (list<QString>::iterator it = warnings.begin(); it!= warnings.end(); it++) {
            cout << it->toStdString();
        }
    }
    cout << "\n";

}

void imprimirTabladeSimbolos() {
    cout << "\nTabla de simbolos: ";
    cout << "\n***** ** *********\n";
    list<QString> entradas = tablaDeSimbolos.imprimir();
    for (list<QString>::iterator it = entradas.begin(); it!= entradas.end(); it++) {
        cout << it->toStdString();
    }
}

void imprimirReglas() {
    cout << "\nReglas encontradas: ";
    cout << "\n****** ************\n";
    if (!reglasReconocidas.empty())
    {   for (list<QString>::iterator it = reglasReconocidas.begin(); it!=reglasReconocidas.end(); it++)
            cout << endl << it->toStdString();
    } else
        cout << "\nNo se reconocieron reglas\n\n";
}

const char * rutaSalida (const char * ruta) {
    QString aux = ruta;
    while (aux.at(aux.size()-1)!='\\') {
        aux.remove(aux.length()-1,1);
    }
    aux += "codigo_assembler.asm";
    char * ret = new char [aux.length()+1];
    strcpy(ret, aux.toLatin1().constData());
    return ret;
}


/** Programa principal **/


int main(int argc, char *argv[])
{

    AnalizadorLexico * lex = new AnalizadorLexico (argv[1], &warnings, &errores, &tablaDeSimbolos);

    Parser * parser = new Parser (&tablaDeSimbolos,lex,&codGen, &errores);

    /** Se ejecuta el yyparse **/

    int resultado = parser->yyparse();

    cout << "\n\nCodigo fuente analizado: " << argv[1] << endl;

    /** Ahora se imprimen todos los resultados **/

    /**Impresiones viejas (TP 1 y 2)**/
    //tokens = lex->getTokens();
    //imprimirTokens();
    //reglasReconocidas = parser->getReglasEncontradas();
    //imprimirReglas();

    imprimirErrores();
    imprimirWarnings();
    codGen.redefinirVariables(); //modifica tabla y variables
    imprimirTabladeSimbolos();


    if (resultado==1 || parser->hasError() || errores.size()>0) {
        cout << "\nEl programa no esta bien escrito (yyparse=1 o flag error = true).\n";
        cout << "No se genero codigo assembler.\n";
    } else {
        codGen.imprimirTercetos();
        codGen.generarAssembler(rutaSalida(argv[1]));
        cout << "\n\n\nEl programa ha sido escrito correctamente. \n";
        cout << "Codigo assembler almacenado en: " << rutaSalida(argv[1]) << endl;
    }

    cout << "\n\nDisenio de Compiladores. TP 3,4 \nAlumnos: \n  Roman y Zubeldia, Alfonso \n  Rios, Bruno.\n\n";

    return resultado;

}
