%{
#include <QString>
#define YYSTYPE QString
#define notificar(msg) this->notificar(msg)
#define addRegla(msg) this->addRegla(msg)
#define declararVariable(var, tipo) this->declararVariable(var, tipo)
#define hacerGlobal(var) this->hacerGlobal(var)
#define tipo this->tipo
#define codGen this->codGen
%}

%token IF THEN ELSE ENDIF PRINT INT BEGIN END FLOAT GLOBAL LOOP UNTIL TOFLOAT ID CTE MENORIGUAL MAYORIGUAL IGUALIGUAL DISTINTO CADENA
%right THEN ELSE IF
%left '+' '-'
%left '*' '/'

%%
programa		:	parte_declarativa	parte_ejecutable
			|	parte_ejecutable

            ;

parte_declarativa	:	parte_declarativa	sentencia_declarativa
			|	sentencia_declarativa
			;


parte_ejecutable	:	parte_ejecutable	sentencia_ejecutable
                        |   	parte_ejecutable     	ambito
			|	sentencia_ejecutable
                        |   	ambito
            |error ';' {notificar("Sentencia invalida");}
			;


parte_ejecutable_bloque : 	parte_ejecutable_bloque sentencia_ejecutable
                        | 	sentencia_ejecutable
                        ;


sentencia_declarativa	:	tipo	lista_var ';'	{addRegla("una declaracion de variable");}
                        |   	tipo    error     ';'   {notificar("Se esperaba un identificador (o una lista de identificadores)");}
                        |   	tipo lista_var error ';' {notificar("Error luego de la lista de identificadores");}
			;


tipo			:	FLOAT	{tipo="FLOAT";}
			|	INT	{tipo="INT";}
			;


lista_var		:	lista_var	','    ID	{declararVariable($3, tipo);}
			|	ID 				{declararVariable($1, tipo);}
                        |   	error ',' ID 			{notificar ("Error en la lista de identificadores");}
			;

lista_var_g		:	lista_var_g	','    ID	{hacerGlobal($3);}
			|	ID				{hacerGlobal($1);}
                        |   	error ',' ID 	{notificar ("Error en la lista de identificadores");}
			;


sentencia_ejecutable	:	seleccion
                        |	iteracion ';'
                        |   	iteracion {notificar("Falta ';' para cerrar la iteracion");}
			|	salida_mensajes ';'
                        |   	salida_mensajes {notificar("Falta ';' para cerrar la sentencia PRINT");}
			|	asignacion

			;


seleccion		:	IF	condicion_if	THEN	bloque_de_sentencias    {	int incompleto = codGen->desapilar();
                                                                            			codGen->completarTerceto(incompleto, "["+QString::number(codGen->ultimoTerceto()+1)+"]", 3);
                                                                            			addRegla("el cierre de una sentencia de seleccion (IF-THEN)");
                                                                                        codGen->crearTerceto("Label", QString::number(codGen->ultimoTerceto()+1), "null");
                                                                        		}
			|	IF	condicion_if	THEN	bloque_de_sentencias	else	bloque_de_sentencias   {    int incompleto = codGen->desapilar();
                                                                                            	codGen->completarTerceto(incompleto, "["+QString::number(codGen->ultimoTerceto()+1)+"]", 2);
                                                                                            	addRegla("el cierre de una sentencia de seleccion (IF-THEN-ELSE)");
                                                                                                codGen->crearTerceto("Label", QString::number(codGen->ultimoTerceto()+1), "null");
                                                                                                			}
                        |   	IF  condicion_if  bloque_de_sentencias {notificar("Se encontro el cierre de una sentencia de seleccion a la que le falta la palabra reservada THEN");}
                        |   	IF  condicion_if bloque_de_sentencias ELSE bloque_de_sentencias {notificar("Se encontro el cierre de una sentencia de seleccion a la que le falta la palabra reservada THEN");}
			;

condicion_if            :  	'('	condicion  ')'  {   	int nroTerceto = codGen->crearTerceto("BF", "[" +QString::number(codGen->ultimoTerceto())+"]", "");
                                                    		codGen->apilar(nroTerceto);
                                               		}
                        |  	'(' condicion {notificar("Se esperaba ')'");}
                        |   	condicion ')' {notificar("Se esperaba '('");}
                        |   	condicion {notificar("Se esperaban parentesis alrededor de la condicion");}
                        ;

else			: 	ELSE    {   	int incompleto = codGen->desapilar();
                                		codGen->completarTerceto(incompleto, "["+QString::number(codGen->ultimoTerceto()+2)+"]", 3);
                                		int nroTerceto = codGen->crearTerceto("BI", "", "null");
                                        codGen->crearTerceto("Label", QString::number(codGen->ultimoTerceto()+1), "null");
                                		codGen->apilar(nroTerceto);
                            		}
			;

condicion_until         :  	'('	condicion  ')'  {   int nroInicio = codGen->desapilar();
                                                    int ultimoTerceto = codGen->ultimoTerceto();
                                                    codGen->crearTerceto("BF", "["+QString::number(ultimoTerceto)+"]", "["+QString::number(nroInicio)+"]");
                                                }
                        |  	'(' condicion {notificar("Se esperaba ')'");}
                        |   	condicion ')' {notificar("Se esperaba '('");}
                        |   	condicion {notificar("Se esperaban parentesis alrededor de la condicion");}
                        ;

condicion		:	expresion	comparador	expresion 	{	addRegla("una condicion"); 
											QString tipo1, tipo2;
											if (!tiposArrojados.empty())
												tipo1 = tiposArrojados.pop();
											if (!tiposArrojados.empty())
												tipo2 = tiposArrojados.pop();
											if (tipo1!=tipo2)
												notificar("Tipos incompatibles en la comparacion");
											else
												codGen->crearTerceto($2, $1, $3, codGen->obtenerTipo($1));
									
										}
                        |  	expresion   comparador  error {notificar("Se esperaba una expresion en el lado derecho de la condicion");};
                        |   	error   comparador  expresion {notificar("Se esperaba una expresion en el lado izquierdo de la condicion");};
                        |   	expresion error expresion {notificar("Se esperaba un comparador entre las expresiones de la condicion");};
                        |   	error comparador error {notificar("Se esperaban expresiones alrededor del comparador");}
                        |   	error {notificar("Se esperaba una condicion");};
			;


asignacion		:	ID 	'='  expresion ';' {addRegla("una sentencia de asignacion"); 
							    QString old = $1;
							    $1 = mangle($1);
                                tabladeSimbolos->eliminar(old);
                                if ($1 != "") {
                                    if (!tiposArrojados.empty()) {
                                        QString tipoExpr = tiposArrojados.pop();
                                        QString tipoId = tabladeSimbolos->obtenerTipo($1);
                                       
                                        if (tipoExpr!=tipoId)
                                            notificar("Se esta intentando asignar una expresion de tipo " + tipoExpr + " a una variable de tipo " + tipoId);
                                        else
                                            codGen->crearTerceto("=", $1, $3, tipoExpr);
                                    }
                                }
							    }
			|	ID	'='  expresion  {addRegla("una sentencia de asignacion"); notificar("Falta ';' para cerrar la asignacion");}
                        |   	ID 	'='  error ';' {notificar("Se esperaba una expresion");}
			|	ID 	'='  expresion error ';' {notificar("Error en la asignacion");}
                        |   	ID 	error  ';'{notificar("Se esperaba el operador de asignacion '='");}
			;



expresion		:	expresion  '+'   expresion 	{	$$ = "["+QString::number(codGen->crearTerceto("+", $1, $3, codGen->obtenerTipo($1)))+"]";
									QString tipo1, tipo2;
									if (!tiposArrojados.empty())
										tipo1 = tiposArrojados.pop();
									if (!tiposArrojados.empty())
										tipo2 = tiposArrojados.pop();
									if (tipo1!=tipo2)
										notificar("Tipos incompatibles en la suma");
									else
										tiposArrojados.push(tipo1);
							      	}

                        |	expresion  '-'   expresion 	{	$$ = "["+QString::number(codGen->crearTerceto("-", $1, $3, codGen->obtenerTipo($1)))+"]";
									QString tipo1, tipo2;
									if (!tiposArrojados.empty())
										tipo1 = tiposArrojados.pop();
									if (!tiposArrojados.empty())
										tipo2 = tiposArrojados.pop();
									if (tipo1!=tipo2)
										notificar("Tipos incompatibles en la resta");
									else
										tiposArrojados.push(tipo1);
							      	}

				
            		|   	TOFLOAT '('  expresion  ')'	{	tiposArrojados.pop();
									tiposArrojados.push("FLOAT");
									$$ = "["+QString::number(codGen->crearTerceto("TOFLOAT", $3, "null","FLOAT"))+"]";
								}
			


			|	expresion  '*'  expresion	{	$$ = "["+QString::number(codGen->crearTerceto("*", $1, $3, codGen->obtenerTipo($1)))+"]";
									QString tipo1, tipo2;
									if (!tiposArrojados.empty())
										tipo1 = tiposArrojados.pop();
									if (!tiposArrojados.empty())
										tipo2 = tiposArrojados.pop();
									if (tipo1!=tipo2) {
										notificar("Tipos incompatibles en la multiplicacion");
										tiposArrojados.push("Indefinido");
									}
									else
										tiposArrojados.push(tipo1);
						      		}

			|	expresion  '/'  expresion 	{	$$ = "["+QString::number(codGen->crearTerceto("/", $1, $3, codGen->obtenerTipo($1)))+"]";
									QString tipo1, tipo2;
									if (!tiposArrojados.empty())
										tipo1 = tiposArrojados.pop();
									if (!tiposArrojados.empty())
										tipo2 = tiposArrojados.pop();
									if (tipo1!=tipo2) {
										notificar("Tipos incompatibles en la division");
										tiposArrojados.push("Indefinido");
									}
									else
										tiposArrojados.push(tipo1);
						      		}
		


	                |   	ID				{	
									QString old = $1;
									$1 = mangle($1); 
									$$=$1;
                                    tabladeSimbolos->eliminar(old);
                                    if ($1 != "")
                                        tiposArrojados.push(tabladeSimbolos->obtenerTipo($1));
									
									
								}
                        |   	CTE 				{	if (!rangoValido($1, false)) {
										notificar("Constante entera fuera de rango");
										tiposArrojados.push("INT");
									} else {
										$$=$1;
										marcarUsada($1);
										tiposArrojados.push(tabladeSimbolos->obtenerTipo($1));
									}
								}

                        |  	'-' CTE %prec '*' 		{	if (rangoValido($2, true)) {
										$2 = negativo($2);
										$$=$2;
										tiposArrojados.push(tabladeSimbolos->obtenerTipo($2)); 
									} else {
										notificar("Constante entera fuera de rango");
										tiposArrojados.push("INT");
									}
						   		}
                        ;


comparador		:	'>'		{$$ = ">";}
			|	'<'		{$$ = "<";}
			|	MAYORIGUAL	{$$ = ">=";}
			|	MENORIGUAL	{$$ = "<=";}
			|	DISTINTO	{$$ = "<>";}
			|	IGUALIGUAL	{$$ = "==";}
			;


bloque_de_sentencias	:	sentencia_ejecutable
			|	BEGIN	parte_ejecutable_bloque	END ';' {addRegla("el cierre de un bloque BEGIN-END");}
                        |	BEGIN	parte_ejecutable_bloque	END {notificar("Falta ';' para cerrar el bloque BEGIN-END");}
			;


iteracion		:	loop	bloque_de_sentencias 	UNTIL	condicion_until {addRegla("una sentencia de iteracion");}
			;


loop            : LOOP  {   int inicioLoop = codGen->ultimoTerceto()+1;
                            codGen->apilar(inicioLoop);
                            codGen->crearTerceto("Label", QString::number(inicioLoop), "null");
                        }


salida_mensajes		:	PRINT	'('    CADENA    ')' {codGen->crearTerceto("PRINT", $3, "null"); addRegla("una sentencia de impresion por pantalla");}
                        |   	PRINT	'('    CADENA        {notificar("Falta ')'");}
                        |   	PRINT          CADENA   ')'  {notificar("Falta '('");}
                        |   	PRINT          CADENA        {notificar ("Faltan parentesis alrededor de la cadena");}
                        |   	PRINT  '(' error ')'         {notificar("Se esperaba una cadena");}
			;


ambito			:	abre_ambito   parte_declara_ambito    parte_ejecutable    cierra_ambito {addRegla("el cierre de una declaracion de ambito");}
			|	abre_ambito  parte_ejecutable    cierra_ambito {addRegla("el cierre de una declaracion de ambito");}
                        |   	abre_ambito   parte_declara_ambito cierra_ambito {notificar("El ambito debe tener sentencias ejecutables");}
                        |   	abre_ambito   parte_ejecutable parte_declara_ambito cierra_ambito {notificar("Las sentencias declarativas del ambito deben estar antes que las ejecutables");}
                        |   	abre_ambito error cierra_ambito {notificar("Error de sintaxis en el ambito");}
			;

abre_ambito		: 	'{' 	{       int aux =ambitos.value(sufijo);
                                    		aux++;
                                    		ambitos.remove(sufijo);
                                    		ambitos.insert(sufijo, aux);
                                		sufijo+= "_";
                                    		sufijo+= QString::number(aux);
                                		ambitos.insert(sufijo, 0);
                                	}
			;

cierra_ambito		: 	'}' 	{ sufijo = sufijoPadre(sufijo);}
			;


parte_declara_ambito	:	parte_declara_ambito	sent_declara_ambito
			|	sent_declara_ambito
			;


sent_declara_ambito	:	sentencia_declarativa
                        |	GLOBAL lista_var_g ';' {addRegla("una declaracion de variable global");}
                        ;
