#ifndef GENERADORDECODIGO_H
#define GENERADORDECODIGO_H
#include "TabladeSimbolos.h"
#include <QStack>
#include <QList>
#include <iostream>
#include <fstream>
#include "y.tab.h"

using namespace std;


typedef struct {
    QString operacion;
    QString operando1;
    QString operando2;
    /** agregados al terceto para faciitar la generación de código **/
    QString varAux; //puntero a TS de la variable auxiliar que almacena el resultado del terceto
    QString tipoOperacion; //para distinguir entre operaciones de Enteros y Flotantes
} Terceto;


class GeneradorDeCodigo
{

private:

    TablaDeSimbolos * tablaDeSimbolos;
    QList<Terceto> listaTercetos;
    QStack <int> pila; //para tercetos incompletos


    /** Para Assembler **/

    //<lexema, nombre_assembler> para asociar un lexema de una cte a su nombre usado en assembler
    QMap <QString,QString> constantes;

    //idem anterior pero con cadenas
    QMap <QString, QString> cadenas;

    //dado un terceto, devuelve todas las instrucciones assembler asociadas
    QList<QString> obtenerInstrucciones (Terceto t, int i);

    //devuelve el string (sentencia assembler) para declarar esa variable de la TS
    QString declaracionVariable (QString lexema);

    //devuelve la variable de assembler a la que se refiere el operando de un terceto
    QString convertirOperando (QString operando);


public:

    //constructor
    GeneradorDeCodigo(TablaDeSimbolos * ts);

    //crea terceto y devuelve el numero del mismo
    int crearTerceto (QString op, QString o1, QString o2);

    //crea terceto y devuelve el numero del mismo. Permite especificar el tipo de la operacion
    int crearTerceto (QString op, QString o1, QString o2, QString tipo);

    //Se utiliza para completar un terceto (backpatching). Permite insertar un valor en alguna posición
    void completarTerceto (int nroTerceto, QString valor, int pos);

    //Desapila el último terceto incompleto y devuelve su número
    int desapilar();

    //Permite apilar el número de un terceto incompleto
    void apilar(int nro);

    //Devuelve el numero del ultimo terceto
    int ultimoTerceto();

    //Se utiliza para conocer el tipo de un operando y saber el tipo del terceto
    QString obtenerTipo(QString operando);

    //Redefine las variables de usuario y crea las auxiliares para assembler. También acomoda los tercetos
    void redefinirVariables();

    //Para cuando se hace global una variable. Hay que actualizar las referencias previas a dicha variable
    void actualizarReferencias(QString referenciaAnterior, QString referenciaNueva);

    //Para imprimir por pantalla la lista de tercetos generada
    void imprimirTercetos();

    //Genera el codigo assembler almacenandolo en la ruta especificada (formato .asm)
    void generarAssembler(const char * ruta);

};

#endif // GENERADORDECODIGO_H
