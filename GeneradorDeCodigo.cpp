 #include "GeneradorDeCodigo.h"


GeneradorDeCodigo::GeneradorDeCodigo(TablaDeSimbolos * ts)
{
    this->tablaDeSimbolos=ts;
}

int GeneradorDeCodigo::crearTerceto(QString op, QString o1, QString o2, QString tipo)
{
    int nro = listaTercetos.size();

    Terceto t;
    t.operacion=op;
    t.operando1=o1;
    t.operando2=o2;
    //agregados
    t.tipoOperacion=tipo;
    t.varAux="";

    listaTercetos.push_back(t);

    return nro;

}

int GeneradorDeCodigo::crearTerceto(QString op, QString o1, QString o2)
{
    int nro = listaTercetos.size();

    Terceto t;
    t.operacion=op;
    t.operando1=o1;
    t.operando2=o2;
    //agregados
    t.tipoOperacion="";
    t.varAux="";

    listaTercetos.push_back(t);

    return nro;

}


void GeneradorDeCodigo::completarTerceto(int nroTerceto, QString valor, int pos)
{
    Terceto t = listaTercetos.at(nroTerceto);
    if (pos==1)
        t.operacion=valor;
    else if (pos==2)
       t.operando1=valor;
    else if (pos==3)
        t.operando2=valor;

    listaTercetos.replace(nroTerceto, t);
}

int GeneradorDeCodigo::desapilar()
{
    return this->pila.pop();
}

void GeneradorDeCodigo::apilar(int nro)
{
    this->pila.push(nro);
}

int GeneradorDeCodigo::ultimoTerceto()
{
    return (this->listaTercetos.size()-1);
}

QString GeneradorDeCodigo::obtenerTipo(QString operando)
{
    if (operando.contains("[")) { //si es un terceto
        QString op = operando;
        op.remove(0,1);
        op.remove(op.size()-1,1);
        int terceto = op.toInt();
        Terceto t = listaTercetos.at(terceto);
        if (t.operacion == "TOFLOAT")
            return "FLOAT";
        return obtenerTipo(t.operando1);
    } else {
        return tablaDeSimbolos->obtenerTipo(operando);
    }
}

void GeneradorDeCodigo::redefinirVariables()
{
    //Se acomodan los tercetos redefiniendo variables de usuario
    for (int i=0; i<listaTercetos.size(); i++) {

        bool modificado = false;
        Terceto t = listaTercetos.at(i);

        if (t.operacion!="Label") {

            if (t.operando1.at(0)!='[') {
                EntradaTS * e = tablaDeSimbolos->value(t.operando1);
                if (e!=NULL)
                    if (e->tokenType=="ID") {
                        t.operando1.push_front("_");
                        modificado = true;
                    }
            }
            if (t.operando2.at(0)!='[') {
                EntradaTS * e = tablaDeSimbolos->value(t.operando2);
                if (e!=NULL)
                    if (e->tokenType=="ID") {
                        t.operando2.push_front("_");
                        modificado = true;
                    }
             }

            if (modificado) {
                listaTercetos.replace(i, t);
            }
        }


    }

    //Se redefine la tabla de simbolos agregando prefijos a las variables de usuario
    QList<QString> entradas = tablaDeSimbolos->keys();
    for (int i=0; i<entradas.size(); i++) {
        EntradaTS * e = tablaDeSimbolos->value(entradas.at(i));
        if (e->tokenType=="ID") {
            QString lexemaViejo = e->lexema;
            QString lexemaNuevo = lexemaViejo;
            lexemaNuevo.push_front("_");
            tablaDeSimbolos->modificarLexema(lexemaViejo, lexemaNuevo);
        }
    }

    //se agregan a la tabla de simbolos las variables auxiliares y se acomodan los tercetos
    for (int i=0; i<listaTercetos.size(); i++) {
        bool modificado = false;
        Terceto t = listaTercetos.at(i);

        if (t.operacion=="+" || t.operacion=="-" || t.operacion=="*" || t.operacion=="/" || t.operacion=="TOFLOAT") {
            t.varAux = "@aux" + QString::number(i);
            EntradaTS * e = new EntradaTS(t.varAux, "ID", ID);
            e->tipo = t.tipoOperacion;
            e->value1=0;
            e->value2=0;
            tablaDeSimbolos->insertar(e->lexema, e);
            modificado=true;
        }

        if (modificado) {
            listaTercetos.replace(i, t);
        }
    }

}

void GeneradorDeCodigo::actualizarReferencias(QString referenciaAnterior, QString referenciaNueva)
{
    for (int i=0; i<listaTercetos.size();i++) {
        bool modificado = false;
        Terceto t = listaTercetos.at(i);

        if (t.operando1==referenciaAnterior) {
            t.operando1=referenciaNueva;
            modificado=true;
        }

        if (t.operando2==referenciaAnterior) {
            t.operando2=referenciaNueva;
            modificado=true;
        }

        if (modificado) {
            listaTercetos.replace(i, t);
        }
    }
}


void GeneradorDeCodigo::imprimirTercetos()
{
    int size=listaTercetos.size();

    std::cout << endl << "\n\nTercetos:  ";
    std::cout << endl << "*********" << endl;
    for (int i=0; i<size; i++) {
        Terceto t = listaTercetos.at(i);
        std::cout << endl << "Nro: " << i << " | " << t.operacion.toStdString() << " , " << t.operando1.toStdString() << " , " << t.operando2.toStdString();
    }

}



QString GeneradorDeCodigo::declaracionVariable(QString lexema)
{
    EntradaTS * e = tablaDeSimbolos->value(lexema);

    if (e->token_id==ID) {
        if (e->tipo=="INT")
            return (e->lexema+ " dw " + QString::number(e->value1));
        else
            return (e->lexema+ " dd " + QString::number(e->value2));
    }

    if (e->token_id==CTE) {
        QString nombreCte = "cte" + QString::number(constantes.size());
        constantes.insert(e->lexema, nombreCte); //el convertir operando hace uso de esta tabla cuando llega lexema de cte
        if (e->tipo=="INT")
            return (nombreCte+ " dw " + QString::number(e->value1));
        else if (e->tipo=="FLOAT") {
            QString valor = QString::number(e->value2);
            //Se le agrega parte decimal si no la tiene
            if (!valor.contains('.') && !valor.contains('e') && !valor.contains('E')) {
                valor.push_back(".0");
            }
            //Caso especial de cuando tiene exponente pero no punto
            if (!valor.contains('.') && (valor.contains('e')||valor.contains('E'))) {
                if (valor.contains('e')) {
                    valor.insert(valor.indexOf('e'),'.');
                } else {
                    valor.insert(valor.indexOf('E'),'.');
                }

            }
            return (nombreCte+ " dd " + valor);
        }
    }

    if (e->token_id==CADENA) {
        QString cad = e->lexema;
        QString nombreCad = "cadena" + QString::number(cadenas.size());
        cadenas.insert(cad,nombreCad);
        cad.remove(0,1);
        cad.remove(cad.size()-1,1);
        return (nombreCad + " db " + "\""+cad+"\""+ ", 0");
    }

    return "";
}

QString GeneradorDeCodigo::convertirOperando(QString operando)
{
    if (operando.at(0)=='[') { //si el operando es un terceto
        QString num = operando;
        num.remove(0,1);
        num.remove(num.size()-1,1); //se le sacan los corchetes
        return ("@aux"+num); //se devuelve @auxNumTerceto (la variable donde se almacena el resultado)
    }

    if (operando.at(0)=='\'') {//si el operando es una cadena
        return cadenas.value(operando);
    }

    if (constantes.contains(operando)) { //si el operando es una constante
        return constantes.value(operando); //se devuelve el nombre de la cte en assembler
    }

    return operando; //si era una variable
}

QList<QString> GeneradorDeCodigo::obtenerInstrucciones(Terceto t, int i)
{
    QList<QString> instrucciones;
    QString instruccion;

    if (t.operacion=="PRINT") {
        QString operando = convertirOperando(t.operando1);
        instruccion = "invoke MessageBox, NULL, addr " + operando + ", addr " + operando + ", MB_OK";
        instrucciones.push_back(instruccion);
        return instrucciones;
    }

    if (t.operacion == "TOFLOAT") {
        instruccion = "FILD " + convertirOperando(t.operando1);
        instrucciones.push_back(instruccion);
        instruccion = "FST @aux"+ QString::number(i);
        instrucciones.push_back(instruccion);
        return instrucciones;
    }

    if (t.operacion == "Label") {
        instruccion = "Label" + t.operando1 +":";
        instrucciones.push_back(instruccion);
        return instrucciones;
    }

    if (t.operacion == "BI") {
        QString nroLabel = t.operando1;
        nroLabel.remove(0,1);
        nroLabel.remove(nroLabel.size()-1,1);
        instruccion = "JMP Label" + nroLabel;
        instrucciones.push_back(instruccion);
        return instrucciones;
    }


    if (t.operacion == "=") {
        if (t.tipoOperacion == "INT") {
            instruccion = "MOV ax," + convertirOperando(t.operando2);
            instrucciones.push_back(instruccion);
            instruccion = "MOV " + convertirOperando(t.operando1) + ", ax";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
        if (t.tipoOperacion=="FLOAT") {
            instruccion = "FLD " + convertirOperando(t.operando2);
            instrucciones.push_back(instruccion);
            instruccion = "FSTP " + convertirOperando(t.operando1);
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }



    if (t.operacion == "+") {
        if (t.tipoOperacion=="INT") {
            instruccion = "MOV ax, " + convertirOperando(t.operando1);
            instrucciones.push_back(instruccion);
            instruccion = "ADD ax, " + convertirOperando(t.operando2);
            instrucciones.push_back(instruccion);
            instruccion = "JO overflow";
            instrucciones.push_back(instruccion);
            instruccion = "MOV @aux" + QString::number(i) + ", ax";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }

        if (t.tipoOperacion=="FLOAT") {
            instruccion = "FLD " + convertirOperando(t.operando1);
            instrucciones.push_back(instruccion);
            instruccion = "FADD " + convertirOperando(t.operando2);
            instrucciones.push_back(instruccion);
            instruccion = "FST @aux" + QString::number(i);
            instrucciones.push_back(instruccion);
            //Chequea overflow
            instruccion = "FABS";
            instrucciones.push_back(instruccion);
            instruccion = "FCOM floatMax";
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JAE overflow";
            instrucciones.push_back(instruccion);
            instruccion = "FCOM floatMin";
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JBE overflow";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }

    if (t.operacion == "-") {
        if (t.tipoOperacion=="INT") {
            instruccion = "MOV ax, " + convertirOperando(t.operando1);
            instrucciones.push_back(instruccion);
            instruccion = "SUB ax, " + convertirOperando(t.operando2);
            instrucciones.push_back(instruccion);
            instruccion = "JO overflow";
            instrucciones.push_back(instruccion);
            instruccion = "MOV @aux" + QString::number(i) + ", ax";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }

        if (t.tipoOperacion=="FLOAT") {
            instruccion = "FLD " + convertirOperando(t.operando1);
            instrucciones.push_back(instruccion);
            instruccion = "FSUB " + convertirOperando(t.operando2);
            instrucciones.push_back(instruccion);
            instruccion = "FST @aux" + QString::number(i);
            instrucciones.push_back(instruccion);
            //CHEQUEA OVERFLOW
            instruccion = "FABS";
            instrucciones.push_back(instruccion);
            instruccion = "FCOM floatMax";
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JAE overflow";
            instrucciones.push_back(instruccion);
            instruccion = "FCOM floatMin";
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JBE overflow";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }

    }

    if (t.operacion == "*") {
        if (t.tipoOperacion=="INT") {
            instruccion = "MOV ax, " + convertirOperando(t.operando1);
            instrucciones.push_back(instruccion);
            instruccion = "IMUL ax, " + convertirOperando(t.operando2);
            instrucciones.push_back(instruccion);
            instruccion = "JO overflow";
            instrucciones.push_back(instruccion);
            instruccion = "MOV @aux" + QString::number(i) + ", ax";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }

        if (t.tipoOperacion=="FLOAT") {
            instruccion = "FLD " + convertirOperando(t.operando1);
            instrucciones.push_back(instruccion);
            instruccion = "FMUL " + convertirOperando(t.operando2);
            instrucciones.push_back(instruccion);
            instruccion = "FST @aux" + QString::number(i);
            instrucciones.push_back(instruccion);
            //CHEQUEA OVERFLOW
            instruccion = "FABS";
            instrucciones.push_back(instruccion);
            instruccion = "FCOM floatMax";
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JAE overflow";
            instrucciones.push_back(instruccion);
            instruccion = "FCOM floatMin";
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JBE overflow";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }

    if (t.operacion == "/") {
        if (t.tipoOperacion=="INT") {
            instruccion = "CMP " + convertirOperando(t.operando2) + ", 0";
            instrucciones.push_back(instruccion);
            instruccion = "JE divcero";
            instrucciones.push_back(instruccion);
            instruccion = "MOV dx, 0";
            instrucciones.push_back(instruccion);
            instruccion = "MOV ax, " + convertirOperando(t.operando1);
            instrucciones.push_back(instruccion);
            instruccion = "IDIV " + convertirOperando(t.operando2);
            instrucciones.push_back(instruccion);
            //CHEQUEA OVERFLOW
            instruccion = "JO overflow";
            instrucciones.push_back(instruccion);
            instruccion = "MOV @aux" + QString::number(i) + ", ax";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }

        if (t.tipoOperacion=="FLOAT") {
            //chequea division por cero
            instruccion = "FLDZ ";
            instrucciones.push_back(instruccion);
            instruccion = "FLD " + convertirOperando(t.operando2);
            instrucciones.push_back(instruccion);
            instruccion = "FCOM";
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JE divcero";
            instrucciones.push_back(instruccion);

            //Divide
            instruccion = "FLD " + convertirOperando(t.operando1);
            instrucciones.push_back(instruccion);
            instruccion = "FDIV ST, ST(1)";
            instrucciones.push_back(instruccion);
            instruccion = "FST @aux" + QString::number(i);
            instrucciones.push_back(instruccion);
            //Chequea overflow
            instruccion = "FABS";
            instrucciones.push_back(instruccion);
            instruccion = "FCOM floatMax";
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JAE overflow";
            instrucciones.push_back(instruccion);
            instruccion = "FCOM floatMin";
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JBE overflow";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }

    if (t.operacion=="==" || t.operacion=="<>" || t.operacion=="<=" || t.operacion==">=" || t.operacion=="<" || t.operacion==">" ) {
        if (t.tipoOperacion=="INT") {
            instruccion = "MOV ax, " + convertirOperando(t.operando1);
            instrucciones.push_back(instruccion);
            instruccion = "CMP ax, " + convertirOperando(t.operando2);
            instrucciones.push_back(instruccion);
            return instrucciones;
        }

        if (t.tipoOperacion=="FLOAT") {
            instruccion = "FLD " + convertirOperando(t.operando1);
            instrucciones.push_back(instruccion);
            instruccion = "FCOM " + convertirOperando(t.operando2);
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            return instrucciones;

        }

    }

    if (t.operacion=="BF") {
        Terceto anterior = listaTercetos.value(i-1);
        QString target = t.operando2;
        target.remove(0,1);
        target.remove(target.size()-1,1);
        target = "Label" + target;

        if (anterior.operacion==">") {
            if (anterior.tipoOperacion=="INT")
                instruccion = "JLE " + target;
            else if (anterior.tipoOperacion=="FLOAT")
                instruccion = "JBE " + target;
            instrucciones.push_back(instruccion);
            return instrucciones;
        }

        if (anterior.operacion=="<") {
            if (anterior.tipoOperacion=="INT")
                instruccion = "JGE " + target;
            else if (anterior.tipoOperacion=="FLOAT")
                instruccion = "JAE " + target;
            instrucciones.push_back(instruccion);
            return instrucciones;
        }

        if (anterior.operacion==">=") {
            if (anterior.tipoOperacion=="INT")
                instruccion = "JL " + target;
            else if (anterior.tipoOperacion=="FLOAT")
                instruccion = "JB " + target;
            instrucciones.push_back(instruccion);
            return instrucciones;
        }

        if (anterior.operacion=="<=") {
            if (anterior.tipoOperacion=="INT")
                instruccion = "JG " + target;
            else if (anterior.tipoOperacion=="FLOAT")
                instruccion = "JA " + target;
            instrucciones.push_back(instruccion);
            return instrucciones;
        }

        if (anterior.operacion=="==") {
            if (anterior.tipoOperacion=="INT") {
                instruccion = "JNE " + target;
                instrucciones.push_back(instruccion);
                return instrucciones;
            } else if (anterior.tipoOperacion=="FLOAT") {
                instruccion = "JB " + target;
                instrucciones.push_back(instruccion);
                instruccion = "JG " + target;
                instrucciones.push_back(instruccion);
                return instrucciones;
            }
        }
        if (anterior.operacion=="<>") {

            instruccion = "JE " + target;
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }
}

void GeneradorDeCodigo::generarAssembler(const char *ruta)
{
    ofstream salida;
    salida.open (ruta);

    /** ENCABEZADO **/
    salida << ".386";
    salida << "\n";
    salida << ".model flat, stdcall";
    salida << "\n";
    salida << "option casemap :none";
    salida << "\n";
    salida << "include \\masm32\\include\\windows.inc";
    salida << "\n";
    salida << "include \\masm32\\include\\kernel32.inc";
    salida << "\n";
    salida << "include \\masm32\\include\\user32.inc";
    salida << "\n";
    salida << "includelib \\masm32\\lib\\kernel32.lib";
    salida << "\n";
    salida << "includelib \\masm32\\lib\\user32.lib";
    salida << "\n";

    /** DECLARACION DE VARIABLES **/

    salida << ".data";
    salida << "\n";
    QList<QString> entradas = tablaDeSimbolos->keys();
    for (int i=0; i<entradas.size(); i++) {
        salida << this->declaracionVariable(entradas.at(i)).toStdString();
        salida << "\n";
    }
    salida << "floatMax dd 3.40282347e38";
    salida << "\n";
    salida << "floatMin dd 1.17549435e-38";
    salida << "\n";
    salida << "OverFlow db \"OverFlow en operacion aritmetica\", 0";
    salida << "\n";
    salida << "DivPorCero db \"No se permite dividir por cero\", 0";
    salida << "\n";


    /** CODIGO **/

    salida << ".code";
    salida << "\n";


    salida << "overflow:";
    salida << "\n";
    salida << "invoke MessageBox, NULL, addr OverFlow, addr OverFlow, MB_OK";
    salida << "\n";
    salida << "invoke ExitProcess, 0";
    salida << "\n";

    salida << "divcero:";
    salida << "\n";
    salida << "invoke MessageBox, NULL, addr DivPorCero, addr DivPorCero, MB_OK";
    salida << "\n";
    salida << "invoke ExitProcess, 0";
    salida << "\n";

    salida << "start:";
    salida << "\n";
    for (int i=0; i<listaTercetos.size(); i++) {
        QList<QString> instrucciones = obtenerInstrucciones(listaTercetos.at(i),i);
        for (int j=0; j<instrucciones.size();j++) {
            salida<< instrucciones.at(j).toStdString();
            salida << "\n";
        }
    }
    salida << "end start";

    salida.close();


}

