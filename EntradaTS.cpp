
#include "EntradaTS.h"

EntradaTS::EntradaTS (QString lexema, QString token, int token_id) {
    this->lexema= lexema;
    this->tokenType = token;
    this->token_id = token_id;
    this->usada=false;
}

QString EntradaTS::toString()
{
    QString out = "";

    out.append("LEXEMA: " + this->lexema + " | TIPO DE TOKEN: " + this->tokenType + " | TIPO: " + this->tipo);

    if (this->tokenType!="CADENA") {
        out.append(" | VALOR: ");
        if (this->tipo=="INT") {
            out.append(QString::number(value1));
        } else if (this->tipo=="FLOAT"){
            out.append(QString::number(value2));
        }
    }

    return out;
}
