#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#define IF 257
#define THEN 258
#define ELSE 259
#define ENDIF 260
#define PRINT 261
#define INT 262
#define BEGIN 263
#define END 264
#define FLOAT 265
#define GLOBAL 266
#define LOOP 267
#define UNTIL 268
#define TOFLOAT 269
#define ID 270
#define CTE 271
#define MENORIGUAL 272
#define MAYORIGUAL 273
#define IGUALIGUAL 274
#define DISTINTO 275
#define CADENA 276
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    1,    1,    2,    2,    2,    2,    2,    6,
    6,    3,    3,    3,    7,    7,    8,    8,    8,    9,
    9,    9,    4,    4,    4,    4,    4,    4,   10,   10,
   10,   10,   14,   14,   14,   14,   16,   18,   18,   18,
   18,   17,   17,   17,   17,   17,   17,   13,   13,   13,
   13,   13,   19,   19,   19,   19,   19,   19,   19,   19,
   20,   20,   20,   20,   20,   20,   15,   15,   15,   11,
   21,   12,   12,   12,   12,   12,    5,    5,    5,    5,
    5,   22,   24,   23,   23,   25,   25,
};
short yylen[] = {                                         2,
    2,    1,    2,    1,    2,    2,    1,    1,    2,    2,
    1,    3,    3,    4,    1,    1,    3,    1,    3,    3,
    1,    3,    1,    2,    1,    2,    1,    1,    4,    6,
    3,    5,    3,    2,    2,    1,    1,    3,    2,    2,
    1,    3,    3,    3,    3,    3,    1,    4,    3,    4,
    5,    3,    3,    3,    4,    3,    3,    1,    1,    2,
    1,    1,    1,    1,    1,    1,    1,    4,    3,    4,
    1,    4,    3,    3,    2,    4,    4,    3,    3,    4,
    3,    1,    1,    2,    1,    1,    3,
};
short yydefred[] = {                                      0,
    0,    0,    0,   16,   15,   71,    0,   82,    0,    0,
    0,    4,    7,    8,    0,   23,    0,    0,   28,    0,
    0,    9,    0,    0,   58,   59,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,    5,    6,    0,
   18,    0,   24,   26,    0,   67,    0,    0,    0,    0,
   86,    0,   85,   64,   63,   66,   65,   61,   62,    0,
    0,   60,    0,    0,    0,   35,    0,    0,    0,    0,
    0,    0,   74,    0,    0,   52,    0,    0,   13,    0,
    0,   12,    0,   11,    0,    0,   83,   81,    0,   21,
    0,    0,   78,    0,   79,   84,   46,    0,    0,   33,
    0,    0,    0,    0,    0,   56,   57,   43,    0,   76,
   72,   50,    0,   48,   19,   14,   17,    0,   10,    0,
    0,   70,    0,   87,    0,   80,   77,   55,   37,    0,
   32,   51,   68,    0,   40,   22,   20,   30,   38,
};
short yydgoto[] = {                                       9,
   10,   11,   51,   46,   14,   85,   15,   42,   91,   16,
   17,   18,   19,   29,   47,  130,   30,  122,   31,   60,
   20,   21,   52,   88,   53,
};
short yysindex[] = {                                    330,
  -12,  -26,  -40,    0,    0,    0,  -58,    0,    0,  330,
  -85,    0,    0,    0, -222,    0,   -8,   -7,    0,  290,
  264,    0,  189,   14,    0,    0, -228,  -43, -154,   30,
  -34,   33, -239,   -3,  174,  -85,    0,    0,    0,  -20,
    0,  -32,    0,    0,  266,    0, -191,  -36, -198,  278,
    0,  -66,    0,    0,    0,    0,    0,    0,    0,  180,
  -16,    0,   38,  290, -174,    0,  -16,  -16,  -16,  -16,
  -16,  186,    0,   50,   53,    0,   36,  -27,    0, -169,
   43,    0, -165,    0, -112,  129,    0,    0,   64,    0,
    9, -103,    0, -119,    0,    0,    0,   45,   94,    0,
 -148,  290,   45,    3,    3,    0,    0,    0,   45,    0,
    0,    0,   56,    0,    0,    0,    0,   58,    0,  -43,
   77,    0, -151,    0, -150,    0,    0,    0,    0,  290,
    0,    0,    0,   80,    0,    0,    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  140,    0,    0,    0,    0,    0,  167,  215,    0,    0,
    0,    0,   41,    0,    0,    0,    0,    0,    0,  208,
    0,   98,    0,    0,    0,  150,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  345,    0,  297,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  112,    0,    0,  233,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   55,    0,    0,
  315,    0,   69,    1,   21,    0,    0,    0,   84,    0,
    0,    0,    0,    0,    0,    0,    0,  247,    0,    0,
  127,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  147,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,   15,   76,  578,   -1,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -24,    0,  -21,    0,   62,  122,
    0,    0,  104,  -19,  -22,
};
#define YYTABLESIZE 672
short yytable[] = {                                      33,
   53,   27,   35,    8,   65,   87,   63,   70,   68,   39,
   69,   83,   71,   28,   70,   68,   74,   69,   27,   71,
   54,   87,   22,   80,   36,   59,   82,   58,   27,   96,
   93,  114,   95,   40,   39,   50,   75,    8,   79,  101,
   47,   53,   62,   53,   70,   53,   22,   41,   39,   71,
   43,   44,  125,   61,   44,   76,    8,   89,   87,   53,
   53,   54,   53,   54,  121,   54,   94,  124,   45,   96,
   66,   90,  126,   73,  127,   12,   86,  131,  100,   54,
   54,   47,   54,   42,  102,   37,   70,   68,   87,   69,
  110,   71,   39,  111,  112,   44,   78,   75,  134,   47,
  115,  116,    2,   64,  117,  138,    3,  123,   45,   45,
  129,   73,    6,   44,  132,    7,  133,  135,  136,  137,
  139,   98,   99,   53,   42,   53,   41,   45,  103,  104,
  105,  106,  107,  109,  128,   70,   68,    2,   69,    2,
   71,    3,   42,   54,    2,   54,   39,    6,    3,    1,
    7,  118,   72,   92,    6,    0,   75,    7,    4,    0,
    0,    5,   49,   47,    0,   47,   25,    0,  120,    0,
   73,    2,    0,   27,    0,    3,    0,   44,    0,   44,
    0,    6,    0,    0,    7,   41,    0,    0,    0,    1,
    2,   45,    0,   45,    3,    4,    0,   34,    5,   49,
    6,    0,    0,    7,    0,   39,   42,    0,   42,    0,
    0,    0,   23,    0,   27,    0,    0,    0,   27,    0,
   75,   67,   75,   81,   27,   24,   25,   26,  113,   23,
   27,    0,   49,    0,   73,   32,   73,   54,   55,   56,
   57,    0,   24,   25,   26,    0,   69,    0,   59,   41,
   58,   41,   24,   25,   26,    0,   53,   53,   53,   53,
    0,   53,   53,   53,   53,   53,   53,   53,   53,   39,
   53,   39,   53,   53,   53,   53,   54,   54,   54,   54,
    0,   54,   54,   54,   54,   54,   54,   54,   54,   25,
   54,   25,   54,   54,   54,   54,   31,   47,   47,   47,
    0,   47,   47,   47,   47,   47,   47,   47,   47,    0,
   47,   44,   44,   44,   29,   44,   44,   44,   44,   44,
   44,   44,   44,    0,   44,   45,   45,   45,    0,   45,
   45,   45,   45,   45,   45,   45,   45,   27,   45,   27,
   42,   42,   42,    0,   42,   42,   42,   42,   42,   42,
   42,   42,    0,   42,   75,   49,   75,   49,   75,   75,
    0,   75,   75,   75,   75,   75,    0,   75,   73,   69,
   73,   69,   73,   73,    0,   73,   73,   73,   73,   73,
    0,   73,    0,   41,   23,   41,    8,   41,   41,    0,
   41,   41,   41,   41,   41,    0,   41,   24,   25,   26,
    8,    0,   87,   39,    0,   39,    0,   39,   39,    0,
   39,   39,   39,   39,   39,    0,   39,    0,    0,   31,
    0,   31,    0,   25,    0,   25,    0,   25,   25,   77,
   25,   25,   25,   25,   25,   97,   25,   29,    0,   29,
    0,  108,   24,   25,   26,    0,    0,    0,   24,   25,
   26,    0,    8,    0,   24,   25,   26,    0,    0,    0,
   54,   55,   56,   57,   36,   36,    0,    0,   36,    0,
   36,   27,    0,   27,   36,   27,   27,   36,   27,   27,
   27,   27,   27,    0,   27,    0,    0,    0,    0,   49,
    0,   49,    0,   49,   49,    0,   49,   49,   49,   49,
   49,    0,   49,   69,    0,   69,    0,   69,   69,    0,
   69,   69,   69,   69,   69,    0,   69,    0,    0,   48,
    2,    0,    2,    0,    3,    4,    3,    0,    5,   49,
    6,    0,    6,    7,    2,    7,    0,    0,    3,    4,
    0,    0,    5,   49,    6,    0,    2,    7,    0,    0,
    3,    0,   45,   31,    0,    0,    6,   31,   31,    7,
   31,   31,   31,   31,   31,    0,   31,    0,    0,    0,
    0,   29,    0,    0,    0,   29,   29,   13,   29,   29,
   29,   29,   29,    0,   29,    1,    2,   13,   38,    0,
    3,    4,    0,    0,    5,    0,    6,    0,   13,    7,
    0,   34,   34,    0,    0,   34,    0,   34,    0,    0,
    0,   34,    0,   38,   34,    0,    0,    0,    0,    0,
    0,    0,   84,    0,    0,    0,    0,   38,    0,   13,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  119,    0,    0,    0,    0,    0,    0,    0,
    0,   38,
};
short yycheck[] = {                                      40,
    0,   45,   61,  123,   29,  125,   28,   42,   43,   11,
   45,   44,   47,   40,   42,   43,  256,   45,   45,   47,
    0,  125,   59,   44,   10,   60,   59,   62,   45,   52,
   50,   59,   52,  256,   36,   21,  276,  123,   59,   64,
    0,   41,  271,   43,   42,   45,   59,  270,   50,   47,
   59,   59,   44,   40,    0,   59,  123,  256,  125,   59,
   60,   41,   62,   43,   86,   45,   52,   59,    0,   92,
   41,  270,   92,   41,   94,    0,  268,  102,   41,   59,
   60,   41,   62,    0,  259,   10,   42,   43,  125,   45,
   41,   47,   94,   41,   59,   41,   35,    0,  120,   59,
  270,   59,  257,  258,  270,  130,  261,   44,  263,   41,
  259,    0,  267,   59,   59,  270,   59,   41,  270,  270,
   41,   60,   61,  123,   41,  125,    0,   59,   67,   68,
   69,   70,   71,   72,   41,   42,   43,  257,   45,    0,
   47,  261,   59,  123,  257,  125,    0,  267,  261,    0,
  270,  264,   31,   50,  267,   -1,   59,  270,  262,   -1,
   -1,  265,  266,  123,   -1,  125,    0,   -1,   40,   -1,
   59,  257,   -1,   45,   -1,  261,   -1,  123,   -1,  125,
   -1,  267,   -1,   -1,  270,   59,   -1,   -1,   -1,  256,
  257,  123,   -1,  125,  261,  262,   -1,  256,  265,  266,
  267,   -1,   -1,  270,   -1,   59,  123,   -1,  125,   -1,
   -1,   -1,  256,   -1,    0,   -1,   -1,   -1,   45,   -1,
  123,  256,  125,  256,   45,  269,  270,  271,  256,  256,
   45,   -1,    0,   -1,  123,  276,  125,  272,  273,  274,
  275,   -1,  269,  270,  271,   -1,    0,   -1,   60,  123,
   62,  125,  269,  270,  271,   -1,  256,  257,  258,  259,
   -1,  261,  262,  263,  264,  265,  266,  267,  268,  123,
  270,  125,  272,  273,  274,  275,  256,  257,  258,  259,
   -1,  261,  262,  263,  264,  265,  266,  267,  268,  123,
  270,  125,  272,  273,  274,  275,    0,  257,  258,  259,
   -1,  261,  262,  263,  264,  265,  266,  267,  268,   -1,
  270,  257,  258,  259,    0,  261,  262,  263,  264,  265,
  266,  267,  268,   -1,  270,  257,  258,  259,   -1,  261,
  262,  263,  264,  265,  266,  267,  268,  123,  270,  125,
  257,  258,  259,   -1,  261,  262,  263,  264,  265,  266,
  267,  268,   -1,  270,  257,  123,  259,  125,  261,  262,
   -1,  264,  265,  266,  267,  268,   -1,  270,  257,  123,
  259,  125,  261,  262,   -1,  264,  265,  266,  267,  268,
   -1,  270,   -1,  257,  256,  259,  123,  261,  262,   -1,
  264,  265,  266,  267,  268,   -1,  270,  269,  270,  271,
  123,   -1,  125,  257,   -1,  259,   -1,  261,  262,   -1,
  264,  265,  266,  267,  268,   -1,  270,   -1,   -1,  123,
   -1,  125,   -1,  257,   -1,  259,   -1,  261,  262,  256,
  264,  265,  266,  267,  268,  256,  270,  123,   -1,  125,
   -1,  256,  269,  270,  271,   -1,   -1,   -1,  269,  270,
  271,   -1,  123,   -1,  269,  270,  271,   -1,   -1,   -1,
  272,  273,  274,  275,  257,  258,   -1,   -1,  261,   -1,
  263,  257,   -1,  259,  267,  261,  262,  270,  264,  265,
  266,  267,  268,   -1,  270,   -1,   -1,   -1,   -1,  257,
   -1,  259,   -1,  261,  262,   -1,  264,  265,  266,  267,
  268,   -1,  270,  257,   -1,  259,   -1,  261,  262,   -1,
  264,  265,  266,  267,  268,   -1,  270,   -1,   -1,  256,
  257,   -1,  257,   -1,  261,  262,  261,   -1,  265,  266,
  267,   -1,  267,  270,  257,  270,   -1,   -1,  261,  262,
   -1,   -1,  265,  266,  267,   -1,  257,  270,   -1,   -1,
  261,   -1,  263,  257,   -1,   -1,  267,  261,  262,  270,
  264,  265,  266,  267,  268,   -1,  270,   -1,   -1,   -1,
   -1,  257,   -1,   -1,   -1,  261,  262,    0,  264,  265,
  266,  267,  268,   -1,  270,  256,  257,   10,   11,   -1,
  261,  262,   -1,   -1,  265,   -1,  267,   -1,   21,  270,
   -1,  257,  258,   -1,   -1,  261,   -1,  263,   -1,   -1,
   -1,  267,   -1,   36,  270,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   45,   -1,   -1,   -1,   -1,   50,   -1,   52,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   85,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   94,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 276
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"IF","THEN","ELSE","ENDIF","PRINT","INT","BEGIN","END",
"FLOAT","GLOBAL","LOOP","UNTIL","TOFLOAT","ID","CTE","MENORIGUAL","MAYORIGUAL",
"IGUALIGUAL","DISTINTO","CADENA",
};
char *yyrule[] = {
"$accept : programa",
"programa : parte_declarativa parte_ejecutable",
"programa : parte_ejecutable",
"parte_declarativa : parte_declarativa sentencia_declarativa",
"parte_declarativa : sentencia_declarativa",
"parte_ejecutable : parte_ejecutable sentencia_ejecutable",
"parte_ejecutable : parte_ejecutable ambito",
"parte_ejecutable : sentencia_ejecutable",
"parte_ejecutable : ambito",
"parte_ejecutable : error ';'",
"parte_ejecutable_bloque : parte_ejecutable_bloque sentencia_ejecutable",
"parte_ejecutable_bloque : sentencia_ejecutable",
"sentencia_declarativa : tipo lista_var ';'",
"sentencia_declarativa : tipo error ';'",
"sentencia_declarativa : tipo lista_var error ';'",
"tipo : FLOAT",
"tipo : INT",
"lista_var : lista_var ',' ID",
"lista_var : ID",
"lista_var : error ',' ID",
"lista_var_g : lista_var_g ',' ID",
"lista_var_g : ID",
"lista_var_g : error ',' ID",
"sentencia_ejecutable : seleccion",
"sentencia_ejecutable : iteracion ';'",
"sentencia_ejecutable : iteracion",
"sentencia_ejecutable : salida_mensajes ';'",
"sentencia_ejecutable : salida_mensajes",
"sentencia_ejecutable : asignacion",
"seleccion : IF condicion_if THEN bloque_de_sentencias",
"seleccion : IF condicion_if THEN bloque_de_sentencias else bloque_de_sentencias",
"seleccion : IF condicion_if bloque_de_sentencias",
"seleccion : IF condicion_if bloque_de_sentencias ELSE bloque_de_sentencias",
"condicion_if : '(' condicion ')'",
"condicion_if : '(' condicion",
"condicion_if : condicion ')'",
"condicion_if : condicion",
"else : ELSE",
"condicion_until : '(' condicion ')'",
"condicion_until : '(' condicion",
"condicion_until : condicion ')'",
"condicion_until : condicion",
"condicion : expresion comparador expresion",
"condicion : expresion comparador error",
"condicion : error comparador expresion",
"condicion : expresion error expresion",
"condicion : error comparador error",
"condicion : error",
"asignacion : ID '=' expresion ';'",
"asignacion : ID '=' expresion",
"asignacion : ID '=' error ';'",
"asignacion : ID '=' expresion error ';'",
"asignacion : ID error ';'",
"expresion : expresion '+' expresion",
"expresion : expresion '-' expresion",
"expresion : TOFLOAT '(' expresion ')'",
"expresion : expresion '*' expresion",
"expresion : expresion '/' expresion",
"expresion : ID",
"expresion : CTE",
"expresion : '-' CTE",
"comparador : '>'",
"comparador : '<'",
"comparador : MAYORIGUAL",
"comparador : MENORIGUAL",
"comparador : DISTINTO",
"comparador : IGUALIGUAL",
"bloque_de_sentencias : sentencia_ejecutable",
"bloque_de_sentencias : BEGIN parte_ejecutable_bloque END ';'",
"bloque_de_sentencias : BEGIN parte_ejecutable_bloque END",
"iteracion : loop bloque_de_sentencias UNTIL condicion_until",
"loop : LOOP",
"salida_mensajes : PRINT '(' CADENA ')'",
"salida_mensajes : PRINT '(' CADENA",
"salida_mensajes : PRINT CADENA ')'",
"salida_mensajes : PRINT CADENA",
"salida_mensajes : PRINT '(' error ')'",
"ambito : abre_ambito parte_declara_ambito parte_ejecutable cierra_ambito",
"ambito : abre_ambito parte_ejecutable cierra_ambito",
"ambito : abre_ambito parte_declara_ambito cierra_ambito",
"ambito : abre_ambito parte_ejecutable parte_declara_ambito cierra_ambito",
"ambito : abre_ambito error cierra_ambito",
"abre_ambito : '{'",
"cierra_ambito : '}'",
"parte_declara_ambito : parte_declara_ambito sent_declara_ambito",
"parte_declara_ambito : sent_declara_ambito",
"sent_declara_ambito : sentencia_declarativa",
"sent_declara_ambito : GLOBAL lista_var_g ';'",
};
#endif
#ifndef YYSTYPE
typedef QString YYSTYPE;
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 9:
#line 21 "GRAMATICA.y"
{notificar("Sentencia invalida");}
break;
case 12:
#line 30 "GRAMATICA.y"
{addRegla("una declaracion de variable");}
break;
case 13:
#line 31 "GRAMATICA.y"
{notificar("Se esperaba un identificador (o una lista de identificadores)");}
break;
case 14:
#line 32 "GRAMATICA.y"
{notificar("Error luego de la lista de identificadores");}
break;
case 15:
#line 36 "GRAMATICA.y"
{tipo="FLOAT";}
break;
case 16:
#line 37 "GRAMATICA.y"
{tipo="INT";}
break;
case 17:
#line 41 "GRAMATICA.y"
{declararVariable(yyvsp[0], tipo);}
break;
case 18:
#line 42 "GRAMATICA.y"
{declararVariable(yyvsp[0], tipo);}
break;
case 19:
#line 43 "GRAMATICA.y"
{notificar ("Error en la lista de identificadores");}
break;
case 20:
#line 46 "GRAMATICA.y"
{hacerGlobal(yyvsp[0]);}
break;
case 21:
#line 47 "GRAMATICA.y"
{hacerGlobal(yyvsp[0]);}
break;
case 22:
#line 48 "GRAMATICA.y"
{notificar ("Error en la lista de identificadores");}
break;
case 25:
#line 54 "GRAMATICA.y"
{notificar("Falta ';' para cerrar la iteracion");}
break;
case 27:
#line 56 "GRAMATICA.y"
{notificar("Falta ';' para cerrar la sentencia PRINT");}
break;
case 29:
#line 62 "GRAMATICA.y"
{	int incompleto = codGen->desapilar();
                                                                            			codGen->completarTerceto(incompleto, "["+QString::number(codGen->ultimoTerceto()+1)+"]", 3);
                                                                            			addRegla("el cierre de una sentencia de seleccion (IF-THEN)");
                                                                                        codGen->crearTerceto("Label", QString::number(codGen->ultimoTerceto()+1), "null");
                                                                        		}
break;
case 30:
#line 67 "GRAMATICA.y"
{    int incompleto = codGen->desapilar();
                                                                                            	codGen->completarTerceto(incompleto, "["+QString::number(codGen->ultimoTerceto()+1)+"]", 2);
                                                                                            	addRegla("el cierre de una sentencia de seleccion (IF-THEN-ELSE)");
                                                                                                codGen->crearTerceto("Label", QString::number(codGen->ultimoTerceto()+1), "null");
                                                                                                			}
break;
case 31:
#line 72 "GRAMATICA.y"
{notificar("Se encontro el cierre de una sentencia de seleccion a la que le falta la palabra reservada THEN");}
break;
case 32:
#line 73 "GRAMATICA.y"
{notificar("Se encontro el cierre de una sentencia de seleccion a la que le falta la palabra reservada THEN");}
break;
case 33:
#line 76 "GRAMATICA.y"
{   	int nroTerceto = codGen->crearTerceto("BF", "[" +QString::number(codGen->ultimoTerceto())+"]", "");
                                                    		codGen->apilar(nroTerceto);
                                               		}
break;
case 34:
#line 79 "GRAMATICA.y"
{notificar("Se esperaba ')'");}
break;
case 35:
#line 80 "GRAMATICA.y"
{notificar("Se esperaba '('");}
break;
case 36:
#line 81 "GRAMATICA.y"
{notificar("Se esperaban parentesis alrededor de la condicion");}
break;
case 37:
#line 84 "GRAMATICA.y"
{   	int incompleto = codGen->desapilar();
                                		codGen->completarTerceto(incompleto, "["+QString::number(codGen->ultimoTerceto()+2)+"]", 3);
                                		int nroTerceto = codGen->crearTerceto("BI", "", "null");
                                        codGen->crearTerceto("Label", QString::number(codGen->ultimoTerceto()+1), "null");
                                		codGen->apilar(nroTerceto);
                            		}
break;
case 38:
#line 92 "GRAMATICA.y"
{   int nroInicio = codGen->desapilar();
                                                    int ultimoTerceto = codGen->ultimoTerceto();
                                                    codGen->crearTerceto("BF", "["+QString::number(ultimoTerceto)+"]", "["+QString::number(nroInicio)+"]");
                                                }
break;
case 39:
#line 96 "GRAMATICA.y"
{notificar("Se esperaba ')'");}
break;
case 40:
#line 97 "GRAMATICA.y"
{notificar("Se esperaba '('");}
break;
case 41:
#line 98 "GRAMATICA.y"
{notificar("Se esperaban parentesis alrededor de la condicion");}
break;
case 42:
#line 101 "GRAMATICA.y"
{	addRegla("una condicion"); 
											QString tipo1, tipo2;
											if (!tiposArrojados.empty())
												tipo1 = tiposArrojados.pop();
											if (!tiposArrojados.empty())
												tipo2 = tiposArrojados.pop();
											if (tipo1!=tipo2)
												notificar("Tipos incompatibles en la comparacion");
											else
												codGen->crearTerceto(yyvsp[-1], yyvsp[-2], yyvsp[0], codGen->obtenerTipo(yyvsp[-2]));
									
										}
break;
case 43:
#line 113 "GRAMATICA.y"
{notificar("Se esperaba una expresion en el lado derecho de la condicion");}
break;
case 44:
#line 114 "GRAMATICA.y"
{notificar("Se esperaba una expresion en el lado izquierdo de la condicion");}
break;
case 45:
#line 115 "GRAMATICA.y"
{notificar("Se esperaba un comparador entre las expresiones de la condicion");}
break;
case 46:
#line 116 "GRAMATICA.y"
{notificar("Se esperaban expresiones alrededor del comparador");}
break;
case 47:
#line 117 "GRAMATICA.y"
{notificar("Se esperaba una condicion");}
break;
case 48:
#line 121 "GRAMATICA.y"
{addRegla("una sentencia de asignacion"); 
							    QString old = yyvsp[-3];
							    yyvsp[-3] = mangle(yyvsp[-3]);
                                tabladeSimbolos->eliminar(old);
                                if (yyvsp[-3] != "") {
                                    if (!tiposArrojados.empty()) {
                                        QString tipoExpr = tiposArrojados.pop();
                                        QString tipoId = tabladeSimbolos->obtenerTipo(yyvsp[-3]);
                                       
                                        if (tipoExpr!=tipoId)
                                            notificar("Se esta intentando asignar una expresion de tipo " + tipoExpr + " a una variable de tipo " + tipoId);
                                        else
                                            codGen->crearTerceto("=", yyvsp[-3], yyvsp[-1], tipoExpr);
                                    }
                                }
							    }
break;
case 49:
#line 137 "GRAMATICA.y"
{addRegla("una sentencia de asignacion"); notificar("Falta ';' para cerrar la asignacion");}
break;
case 50:
#line 138 "GRAMATICA.y"
{notificar("Se esperaba una expresion");}
break;
case 51:
#line 139 "GRAMATICA.y"
{notificar("Error en la asignacion");}
break;
case 52:
#line 140 "GRAMATICA.y"
{notificar("Se esperaba el operador de asignacion '='");}
break;
case 53:
#line 145 "GRAMATICA.y"
{	yyval = "["+QString::number(codGen->crearTerceto("+", yyvsp[-2], yyvsp[0], codGen->obtenerTipo(yyvsp[-2])))+"]";
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
break;
case 54:
#line 157 "GRAMATICA.y"
{	yyval = "["+QString::number(codGen->crearTerceto("-", yyvsp[-2], yyvsp[0], codGen->obtenerTipo(yyvsp[-2])))+"]";
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
break;
case 55:
#line 170 "GRAMATICA.y"
{	tiposArrojados.pop();
									tiposArrojados.push("FLOAT");
									yyval = "["+QString::number(codGen->crearTerceto("TOFLOAT", yyvsp[-1], "null","FLOAT"))+"]";
								}
break;
case 56:
#line 177 "GRAMATICA.y"
{	yyval = "["+QString::number(codGen->crearTerceto("*", yyvsp[-2], yyvsp[0], codGen->obtenerTipo(yyvsp[-2])))+"]";
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
break;
case 57:
#line 191 "GRAMATICA.y"
{	yyval = "["+QString::number(codGen->crearTerceto("/", yyvsp[-2], yyvsp[0], codGen->obtenerTipo(yyvsp[-2])))+"]";
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
break;
case 58:
#line 207 "GRAMATICA.y"
{	
									QString old = yyvsp[0];
									yyvsp[0] = mangle(yyvsp[0]); 
									yyval=yyvsp[0];
                                    tabladeSimbolos->eliminar(old);
                                    if (yyvsp[0] != "")
                                        tiposArrojados.push(tabladeSimbolos->obtenerTipo(yyvsp[0]));
									
									
								}
break;
case 59:
#line 217 "GRAMATICA.y"
{	if (!rangoValido(yyvsp[0], false)) {
										notificar("Constante entera fuera de rango");
										tiposArrojados.push("INT");
									} else {
										yyval=yyvsp[0];
										marcarUsada(yyvsp[0]);
										tiposArrojados.push(tabladeSimbolos->obtenerTipo(yyvsp[0]));
									}
								}
break;
case 60:
#line 227 "GRAMATICA.y"
{	if (rangoValido(yyvsp[0], true)) {
										yyvsp[0] = negativo(yyvsp[0]);
										yyval=yyvsp[0];
										tiposArrojados.push(tabladeSimbolos->obtenerTipo(yyvsp[0])); 
									} else {
										notificar("Constante entera fuera de rango");
										tiposArrojados.push("INT");
									}
						   		}
break;
case 61:
#line 239 "GRAMATICA.y"
{yyval = ">";}
break;
case 62:
#line 240 "GRAMATICA.y"
{yyval = "<";}
break;
case 63:
#line 241 "GRAMATICA.y"
{yyval = ">=";}
break;
case 64:
#line 242 "GRAMATICA.y"
{yyval = "<=";}
break;
case 65:
#line 243 "GRAMATICA.y"
{yyval = "<>";}
break;
case 66:
#line 244 "GRAMATICA.y"
{yyval = "==";}
break;
case 68:
#line 249 "GRAMATICA.y"
{addRegla("el cierre de un bloque BEGIN-END");}
break;
case 69:
#line 250 "GRAMATICA.y"
{notificar("Falta ';' para cerrar el bloque BEGIN-END");}
break;
case 70:
#line 254 "GRAMATICA.y"
{addRegla("una sentencia de iteracion");}
break;
case 71:
#line 258 "GRAMATICA.y"
{   int inicioLoop = codGen->ultimoTerceto()+1;
                            codGen->apilar(inicioLoop);
                            codGen->crearTerceto("Label", QString::number(inicioLoop), "null");
                        }
break;
case 72:
#line 264 "GRAMATICA.y"
{codGen->crearTerceto("PRINT", yyvsp[-1], "null"); addRegla("una sentencia de impresion por pantalla");}
break;
case 73:
#line 265 "GRAMATICA.y"
{notificar("Falta ')'");}
break;
case 74:
#line 266 "GRAMATICA.y"
{notificar("Falta '('");}
break;
case 75:
#line 267 "GRAMATICA.y"
{notificar ("Faltan parentesis alrededor de la cadena");}
break;
case 76:
#line 268 "GRAMATICA.y"
{notificar("Se esperaba una cadena");}
break;
case 77:
#line 272 "GRAMATICA.y"
{addRegla("el cierre de una declaracion de ambito");}
break;
case 78:
#line 273 "GRAMATICA.y"
{addRegla("el cierre de una declaracion de ambito");}
break;
case 79:
#line 274 "GRAMATICA.y"
{notificar("El ambito debe tener sentencias ejecutables");}
break;
case 80:
#line 275 "GRAMATICA.y"
{notificar("Las sentencias declarativas del ambito deben estar antes que las ejecutables");}
break;
case 81:
#line 276 "GRAMATICA.y"
{notificar("Error de sintaxis en el ambito");}
break;
case 82:
#line 279 "GRAMATICA.y"
{       int aux =ambitos.value(sufijo);
                                    		aux++;
                                    		ambitos.remove(sufijo);
                                    		ambitos.insert(sufijo, aux);
                                		sufijo+= "_";
                                    		sufijo+= QString::number(aux);
                                		ambitos.insert(sufijo, 0);
                                	}
break;
case 83:
#line 289 "GRAMATICA.y"
{ sufijo = sufijoPadre(sufijo);}
break;
case 87:
#line 299 "GRAMATICA.y"
{addRegla("una declaracion de variable global");}
break;
#line 930 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
