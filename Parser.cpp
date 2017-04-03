#include "Parser.h"

Parser::Parser(TablaDeSimbolos *ts, AnalizadorLexico *lex, GeneradorDeCodigo * codGen, list<QString> *err)
{
    this->tabladeSimbolos=ts;
    this->analizadorLexico=lex;
    this->codGen=codGen;
    this->errores=err;
    this->sufijo="_0";
    ambitos.insert("_0", 0);

    error = false;
}

list<QString> Parser::getReglasEncontradas()
{
    return reglasEncontradas;
}

QString Parser::sufijoPadre(QString var)
{
    if (!var.contains('_')) {
        return var;
    }
    bool found = false;
    QString aux = var;

    while (!found) {
        if (aux.at(aux.size()-1) == QChar('_'))
            found = true;
        aux.remove(aux.size()-1,1);
    }


    return aux;

}

void Parser::declararVariable(QString var, QString tipo)
{
    QString variable = var + sufijo;
    if (tabladeSimbolos->contiene(variable)) {
        notificar("Variable redeclarada");
    } else {
        //se modifica la entrada para ponerle el sufijo a la variable y asignarle el tipo
        EntradaTS * e = tabladeSimbolos->value(var);
        e->tipo=tipo;
        e->value1=0;
        e->value2=0;
        tabladeSimbolos->modificarLexema(var, variable);
    }
}

QString Parser::mangle(QString var)
{
    QString variable = var + sufijo;
    bool found = false;

    while (!found && variable!=var) {
        if (tabladeSimbolos->contiene(variable))
            found = true;
        else {
            variable = sufijoPadre(variable);
        }
    }

    if (!found) {
        notificar ("La variable '" + var + "' no esta definida en ese ambito");
        variable = "";
    }

    return variable; //se devuelve la variable alcanzable desde el ambito. Devuelve vacia si no esta definida
}



void Parser::hacerGlobal(QString var)
{
    //variable sin mangling
    QString variable = mangle(var); //notifica error si no es alcanzable

    //se modifica la tabla de simbolos haciendo global la variable, si es que no habia ya una global definida con el mismo nombre
    if (variable!="") {
        QString nombreGlobal = var + "_0";
        if (tabladeSimbolos->contiene(nombreGlobal)) {
            notificar ("La variable '" + var + "' no puede declararse como global, porque ya existe una variable global con el mismo nombre" );
        } else {
            EntradaTS * e = tabladeSimbolos->value(variable);
            tabladeSimbolos->modificarLexema(e->lexema,nombreGlobal);
            codGen->actualizarReferencias(variable, nombreGlobal);
        }
    }

}

void Parser::notificar(QString msg)
{
    this->errores->push_back("\nError del parser: "+ msg + ". (Linea: "+ QString::number(analizadorLexico->lineaActual())+").");
    error=true;
}

void Parser::notificar(const char * msg)
{
    this->errores->push_back("\nError del parser: "+ QString(msg) + ". (Linea: "+ QString::number(analizadorLexico->lineaActual())+").");
    error=true;
}

void Parser::addRegla(const char * msg)
{
    this->reglasEncontradas.push_back("Se encontro " + QString(msg) + ". (Linea: " + QString::number(analizadorLexico->lineaActual()) +").");
}

/*Devuelve verdadero si el rango es válido. Si no, devuelve falso*/
bool Parser::rangoValido(QString var, bool signo)
{
    EntradaTS * e = tabladeSimbolos->value(var);
    if (e->tipo == "INT") {
        if (!signo && e->value1==32768)
            return false;
    }
    return true;
}


QString Parser::negativo(QString var) {

    QString aux = "-" + var;

    if (!tabladeSimbolos->contiene(aux)) { //si no esta, se crea. (En el caso de -32768 se modifica)
        EntradaTS * e = tabladeSimbolos->value(var); //se busca la entrada del positivo para copiar valores
        if (!e->usada) {//se modifica
            if (e->tipo == "INT") {
                e->value1 = - (e->value1);
            } else if (e->tipo == "FLOAT") {
                e->value2 = - (e->value2);
            }
            e->usada=true;
            tabladeSimbolos->modificarLexema(e->lexema, aux);
        } else {//se crea la nueva entrada version negativa
            EntradaTS * nueva = new EntradaTS(aux,e->tokenType, e->token_id);
            nueva->tipo=e->tipo;
            e->usada=true; //CREO QUE DEBERIA SER NUEVA->USADA
            if (nueva->tipo == "INT") {
                nueva->value1 = - (e->value1);
            } else if (nueva->tipo == "FLOAT") {
                nueva->value2 = - (e->value2);
            }
            tabladeSimbolos->insertar(aux, nueva);
        }
    } else {
        if (tabladeSimbolos->contiene(var)) {
            EntradaTS * e = tabladeSimbolos->value(var); //se busca la entrada del positivo para ver si hay que borrarla
            if (!e->usada)
                tabladeSimbolos->eliminar(e->lexema);
        }
    }

    return aux; //siempre se devuelve el lexema. Ahora la entrada del negativo existe si no existia
}

void Parser::marcarUsada(QString var)
{
    EntradaTS * e = tabladeSimbolos->value(var);
    e->usada = true;
}

int Parser::yylex()
{
    return this->analizadorLexico->yylex();
}

void Parser::yyerror(QString s)
{
    this->errores->push_back("\nError:"+ s + ". (Linea: "+ QString::number(analizadorLexico->lineaActual())+").");
}

bool Parser::hasError()
{
    return this->error;
}



#define yyparse Parser::yyparse
#define yyerror Parser::yyerror
#include "y.tab.c" // yypase()
