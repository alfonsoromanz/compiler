#include "TabladeSimbolos.h"
#include "EntradaTS.h"
#include "QMap"

TablaDeSimbolos::TablaDeSimbolos()
{
    entradas.clear();
    indice.clear();
}

void TablaDeSimbolos::insertar(QString s, EntradaTS *e)
{
    this->entradas.insert(s,e);
    this->indice.push_back(s);
}

bool TablaDeSimbolos::contiene(QString s)
{
    return this->entradas.contains(s);
}

bool TablaDeSimbolos::contiene(int key)
{
    return (key < this->entradas.size());
}

int TablaDeSimbolos::getIndex(QString s)
{
    return this->indice.indexOf(s);
}

void TablaDeSimbolos::modificarLexema(QString lexViejo, QString lexNuevo)
{
    EntradaTS * e = entradas.value(lexViejo);
    indice.remove(this->getIndex(lexViejo));
    entradas.remove(lexViejo);

    e->lexema=lexNuevo;

    this->insertar(lexNuevo, e);

}

int TablaDeSimbolos::size()
{
    return this->entradas.size();
}

QList<QString> TablaDeSimbolos::keys()
{
    return this->entradas.keys();
}

EntradaTS *TablaDeSimbolos::value(const QString key)
{
    return this->entradas.value(key);
}

EntradaTS *TablaDeSimbolos::value(const int index)
{
    return this->entradas.value(this->indice.value(index));
}

QString TablaDeSimbolos::obtenerTipo(QString lexema)
{
    EntradaTS * e = this->value(lexema);
    if (e!=NULL) {
        return e->tipo;
    }
    return "indefinido";
}

void TablaDeSimbolos::eliminar(QString lexema)
{
    if (this->contiene(lexema)) {
        this->entradas.remove(lexema);
        this->indice.remove(this->getIndex(lexema));
    }
}

list<QString>TablaDeSimbolos::imprimir()
{
    entradasParaImprimir.clear();

    for (int i=0; i<indice.size(); i++) {
        EntradaTS * e = entradas.value(indice.at(i));
        QString aux = "\nNro. Entrada: " + QString::number(i+1) + " | ";
        aux.append(e->toString());
        entradasParaImprimir.push_back(aux);
    }
    return entradasParaImprimir;
};


