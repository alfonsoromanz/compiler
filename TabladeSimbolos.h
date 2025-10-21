#ifndef TABLADESIMBOLOS_H
#define TABLADESIMBOLOS_H
#include <QString>
#include "EntradaTS.h"
#include <QMap>
#include <QVector>
#include <list>

class TablaDeSimbolos
{
public:
    TablaDeSimbolos();
    void insertar(QString s, EntradaTS * e);
    bool contiene(QString s);
    bool contiene(int key);
    int getIndex(QString s);
    void modificarLexema(QString lexViejo, QString lexNuevo);
    int size();
    QList<QString> keys();
    EntradaTS * value(const QString key);
    EntradaTS * value(const int index);
    QString obtenerTipo(QString lexema);
    void eliminar(QString lexema);

    /*Para imprimir por pantalla */
    std::list<QString> imprimir();

private:
    QMap<QString, EntradaTS*> entradas;
    QVector<QString> indice;

    /*Para imprimir*/
    std::list<QString> entradasParaImprimir;
};

#endif // TABLADESIMBOLOS_H
