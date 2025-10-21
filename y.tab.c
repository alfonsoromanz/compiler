/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     THEN = 259,
     ELSE = 260,
     ENDIF = 261,
     PRINT = 262,
     INT = 263,
     BEGIN = 264,
     END = 265,
     FLOAT = 266,
     GLOBAL = 267,
     LOOP = 268,
     UNTIL = 269,
     TOFLOAT = 270,
     ID = 271,
     CTE = 272,
     MENORIGUAL = 273,
     MAYORIGUAL = 274,
     IGUALIGUAL = 275,
     DISTINTO = 276,
     CADENA = 277
   };
#endif
/* Tokens.  */
#define IF 258
#define THEN 259
#define ELSE 260
#define ENDIF 261
#define PRINT 262
#define INT 263
#define BEGIN 264
#define END 265
#define FLOAT 266
#define GLOBAL 267
#define LOOP 268
#define UNTIL 269
#define TOFLOAT 270
#define ID 271
#define CTE 272
#define MENORIGUAL 273
#define MAYORIGUAL 274
#define IGUALIGUAL 275
#define DISTINTO 276
#define CADENA 277




/* Copy the first part of user declarations.  */
#line 1 "GRAMATICA.y"

#include <QString>
#define YYSTYPE QString
#define notificar(msg) this->notificar(msg)
#define addRegla(msg) this->addRegla(msg)
#define declararVariable(var, tipo) this->declararVariable(var, tipo)
#define hacerGlobal(var) this->hacerGlobal(var)
#define tipo this->tipo
#define codGen this->codGen


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 161 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,    30,    25,    23,    28,    24,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
      33,    31,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    13,    16,    19,    21,
      23,    26,    29,    31,    35,    39,    44,    46,    48,    52,
      54,    58,    62,    64,    68,    70,    73,    75,    78,    80,
      82,    87,    94,    98,   104,   108,   111,   114,   116,   118,
     122,   125,   128,   130,   134,   138,   142,   146,   150,   152,
     157,   161,   166,   172,   176,   180,   184,   189,   193,   197,
     199,   201,   204,   206,   208,   210,   212,   214,   216,   218,
     223,   227,   232,   234,   239,   243,   247,   250,   255,   260,
     264,   268,   273,   277,   279,   281,   284,   286,   288
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,    39,    -1,    39,    -1,    38,    41,
      -1,    41,    -1,    39,    45,    -1,    39,    58,    -1,    45,
      -1,    58,    -1,     1,    27,    -1,    40,    45,    -1,    45,
      -1,    42,    43,    27,    -1,    42,     1,    27,    -1,    42,
      43,     1,    27,    -1,    11,    -1,     8,    -1,    43,    28,
      16,    -1,    16,    -1,     1,    28,    16,    -1,    44,    28,
      16,    -1,    16,    -1,     1,    28,    16,    -1,    46,    -1,
      55,    27,    -1,    55,    -1,    57,    27,    -1,    57,    -1,
      51,    -1,     3,    47,     4,    54,    -1,     3,    47,     4,
      54,    48,    54,    -1,     3,    47,    54,    -1,     3,    47,
      54,     5,    54,    -1,    29,    50,    30,    -1,    29,    50,
      -1,    50,    30,    -1,    50,    -1,     5,    -1,    29,    50,
      30,    -1,    29,    50,    -1,    50,    30,    -1,    50,    -1,
      52,    53,    52,    -1,    52,    53,     1,    -1,     1,    53,
      52,    -1,    52,     1,    52,    -1,     1,    53,     1,    -1,
       1,    -1,    16,    31,    52,    27,    -1,    16,    31,    52,
      -1,    16,    31,     1,    27,    -1,    16,    31,    52,     1,
      27,    -1,    16,     1,    27,    -1,    52,    23,    52,    -1,
      52,    24,    52,    -1,    15,    29,    52,    30,    -1,    52,
      25,    52,    -1,    52,    26,    52,    -1,    16,    -1,    17,
      -1,    24,    17,    -1,    32,    -1,    33,    -1,    19,    -1,
      18,    -1,    21,    -1,    20,    -1,    45,    -1,     9,    40,
      10,    27,    -1,     9,    40,    10,    -1,    56,    54,    14,
      49,    -1,    13,    -1,     7,    29,    22,    30,    -1,     7,
      29,    22,    -1,     7,    22,    30,    -1,     7,    22,    -1,
       7,    29,     1,    30,    -1,    59,    61,    39,    60,    -1,
      59,    39,    60,    -1,    59,    61,    60,    -1,    59,    39,
      61,    60,    -1,    59,     1,    60,    -1,    34,    -1,    35,
      -1,    61,    62,    -1,    62,    -1,    41,    -1,    12,    44,
      27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    18,    18,    19,    23,    24,    28,    29,    30,    31,
      32,    36,    37,    41,    42,    43,    47,    48,    52,    53,
      54,    57,    58,    59,    63,    64,    65,    66,    67,    68,
      73,    78,    83,    84,    87,    90,    91,    92,    95,   103,
     107,   108,   109,   112,   124,   125,   126,   127,   128,   132,
     148,   149,   150,   151,   156,   168,   181,   188,   202,   218,
     228,   238,   250,   251,   252,   253,   254,   255,   259,   260,
     261,   265,   269,   275,   276,   277,   278,   279,   283,   284,
     285,   286,   287,   290,   300,   304,   305,   309,   310
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "THEN", "ELSE", "ENDIF", "PRINT",
  "INT", "BEGIN", "END", "FLOAT", "GLOBAL", "LOOP", "UNTIL", "TOFLOAT",
  "ID", "CTE", "MENORIGUAL", "MAYORIGUAL", "IGUALIGUAL", "DISTINTO",
  "CADENA", "'+'", "'-'", "'*'", "'/'", "';'", "','", "'('", "')'", "'='",
  "'>'", "'<'", "'{'", "'}'", "$accept", "programa", "parte_declarativa",
  "parte_ejecutable", "parte_ejecutable_bloque", "sentencia_declarativa",
  "tipo", "lista_var", "lista_var_g", "sentencia_ejecutable", "seleccion",
  "condicion_if", "else", "condicion_until", "condicion", "asignacion",
  "expresion", "comparador", "bloque_de_sentencias", "iteracion", "loop",
  "salida_mensajes", "ambito", "abre_ambito", "cierra_ambito",
  "parte_declara_ambito", "sent_declara_ambito", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    43,    45,    42,    47,    59,    44,    40,
      41,    61,    62,    60,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    39,    39,    39,
      39,    40,    40,    41,    41,    41,    42,    42,    43,    43,
      43,    44,    44,    44,    45,    45,    45,    45,    45,    45,
      46,    46,    46,    46,    47,    47,    47,    47,    48,    49,
      49,    49,    49,    50,    50,    50,    50,    50,    50,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    55,    56,    57,    57,    57,    57,    57,    58,    58,
      58,    58,    58,    59,    60,    61,    61,    62,    62
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     2,     2,     1,     1,
       2,     2,     1,     3,     3,     4,     1,     1,     3,     1,
       3,     3,     1,     3,     1,     2,     1,     2,     1,     1,
       4,     6,     3,     5,     3,     2,     2,     1,     1,     3,
       2,     2,     1,     3,     3,     3,     3,     3,     1,     4,
       3,     4,     5,     3,     3,     3,     4,     3,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     4,     1,     4,     3,     3,     2,     4,     4,     3,
       3,     4,     3,     1,     1,     2,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    17,    16,    72,     0,    83,     0,
       0,     3,     5,     0,     8,    24,    29,    26,     0,    28,
       9,     0,    10,    48,     0,    59,    60,     0,     0,     0,
      37,     0,    76,     0,     0,     0,     1,     2,     4,     6,
       7,     0,    19,     0,    25,     0,    68,     0,    27,     0,
       0,     0,    87,     0,    86,    65,    64,    67,    66,    62,
      63,     0,     0,    61,    35,     0,    32,    36,     0,     0,
       0,     0,     0,     0,    75,     0,    74,    53,     0,     0,
      14,     0,     0,    13,     0,     0,    12,     0,    84,    82,
       0,    22,     0,    79,     0,     0,    80,    85,    47,    45,
       0,    34,    30,     0,    46,    54,    55,    57,    58,    44,
      43,    77,    73,    51,     0,    49,    20,    15,    18,    70,
      11,     0,    71,    42,     0,    88,     0,    81,    78,    56,
      38,     0,    33,    52,    69,    40,    41,    23,    21,    31,
      39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    85,    52,    13,    43,    92,    46,
      15,    29,   131,   122,    30,    16,    31,    61,    47,    17,
      18,    19,    20,    21,    89,    53,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -48
static const yytype_int16 yypact[] =
{
      24,    -6,    54,    22,   -48,   -48,   -48,     8,   -48,    45,
      24,   150,   -48,    12,   -48,   -48,   -48,    26,   231,    48,
     -48,   127,   -48,   199,    56,   -48,   -48,    64,   171,   220,
      74,   126,    77,     4,    86,   181,   -48,   150,   -48,   -48,
     -48,    52,   -48,    32,   -48,   243,   -48,   103,   -48,    91,
      18,   157,   -48,    81,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   192,     0,   -48,    99,   231,   131,   -48,     0,     0,
       0,     0,     0,   198,   -48,   101,   107,   -48,   114,    98,
     -48,   132,   115,   -48,   138,   232,   -48,   161,   -48,   -48,
     128,   -48,    63,   -48,    65,     7,   -48,   -48,   -48,   177,
     228,   -48,   162,   231,   177,    94,    94,   -48,   -48,   -48,
     177,   -48,   -48,   -48,   144,   -48,   -48,   -48,   -48,   147,
     -48,   171,   -48,   125,   159,   -48,   163,   -48,   -48,   -48,
     -48,   231,   -48,   -48,   -48,   151,   -48,   -48,   -48,   -48,
     -48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -48,   -48,   -48,    -3,   -48,    62,   -48,   -48,   -48,     1,
     -48,   -48,   -48,   -48,   -26,   -48,    -5,   149,   -29,   -48,
     -48,   -48,    -8,   -48,   -47,   143,   -45
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -51
static const yytype_int16 yytable[] =
{
      66,    14,    64,    40,    93,    75,    96,    37,    97,    34,
       2,    14,    39,    41,     3,    24,    25,    26,    51,    90,
       6,    22,    14,     7,    27,     1,    76,     2,    42,    40,
      79,     3,     4,    82,    91,     5,   102,     6,    39,    35,
       7,     8,    88,    40,    32,    36,    86,   127,   128,    97,
      95,    33,    39,    44,    14,    23,    99,   100,     8,    83,
      84,   123,    12,   104,   105,   106,   107,   108,   110,    24,
      25,    26,    38,     4,   132,    48,     5,    50,    27,    80,
      81,    63,     1,    28,     2,    62,   120,    40,     3,     4,
     125,   126,     5,    50,     6,   135,    39,     7,   -50,   114,
      88,   -50,   139,   -50,    67,   -50,   -50,    74,   -50,   -50,
     -50,   -50,   -50,    77,   -50,     8,    88,    87,    22,    71,
      72,    69,    70,    71,    72,   115,    88,    68,    49,   101,
       2,   111,   -50,   -50,     3,     4,   103,   112,     5,    50,
       6,   113,   117,     7,    55,    56,    57,    58,   116,    69,
      70,    71,    72,     2,   118,   136,   124,     3,    59,    60,
       2,     8,    23,     6,     3,     4,     7,   130,     5,    50,
       6,   133,    23,     7,   134,   137,    24,    25,    26,   138,
      73,   140,    78,     0,     8,    27,    24,    25,    26,     0,
     121,     8,    88,    98,    94,    27,    24,    25,    26,   109,
      69,    70,    71,    72,     0,    27,     0,    24,    25,    26,
       0,     0,     0,    24,    25,    26,    27,    55,    56,    57,
      58,     0,    27,     2,    65,     0,     0,     3,     0,    45,
       0,    59,    60,     6,     2,     2,     7,     0,     3,     3,
      45,     0,   119,     0,     6,     6,     2,     7,     7,     0,
       3,    69,    70,    71,    72,     0,     6,     0,   129,     7
};

static const yytype_int16 yycheck[] =
{
      29,     0,    28,    11,    51,     1,    53,    10,    53,     1,
       3,    10,    11,     1,     7,    15,    16,    17,    21,     1,
      13,    27,    21,    16,    24,     1,    22,     3,    16,    37,
      35,     7,     8,     1,    16,    11,    65,    13,    37,    31,
      16,    34,    35,    51,    22,     0,    45,    94,    95,    94,
      53,    29,    51,    27,    53,     1,    61,    62,    34,    27,
      28,    87,     0,    68,    69,    70,    71,    72,    73,    15,
      16,    17,    10,     8,   103,    27,    11,    12,    24,    27,
      28,    17,     1,    29,     3,    29,    85,    95,     7,     8,
      27,    28,    11,    12,    13,   121,    95,    16,     0,     1,
      35,     3,   131,     5,    30,     7,     8,    30,    10,    11,
      12,    13,    14,    27,    16,    34,    35,    14,    27,    25,
      26,    23,    24,    25,    26,    27,    35,     1,     1,    30,
       3,    30,    34,    35,     7,     8,     5,    30,    11,    12,
      13,    27,    27,    16,    18,    19,    20,    21,    16,    23,
      24,    25,    26,     3,    16,    30,    28,     7,    32,    33,
       3,    34,     1,    13,     7,     8,    16,     5,    11,    12,
      13,    27,     1,    16,    27,    16,    15,    16,    17,    16,
      31,    30,     1,    -1,    34,    24,    15,    16,    17,    -1,
      29,    34,    35,     1,    51,    24,    15,    16,    17,     1,
      23,    24,    25,    26,    -1,    24,    -1,    15,    16,    17,
      -1,    -1,    -1,    15,    16,    17,    24,    18,    19,    20,
      21,    -1,    24,     3,     4,    -1,    -1,     7,    -1,     9,
      -1,    32,    33,    13,     3,     3,    16,    -1,     7,     7,
       9,    -1,    10,    -1,    13,    13,     3,    16,    16,    -1,
       7,    23,    24,    25,    26,    -1,    13,    -1,    30,    16
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     7,     8,    11,    13,    16,    34,    37,
      38,    39,    41,    42,    45,    46,    51,    55,    56,    57,
      58,    59,    27,     1,    15,    16,    17,    24,    29,    47,
      50,    52,    22,    29,     1,    31,     0,    39,    41,    45,
      58,     1,    16,    43,    27,     9,    45,    54,    27,     1,
      12,    39,    41,    61,    62,    18,    19,    20,    21,    32,
      33,    53,    29,    17,    50,     4,    54,    30,     1,    23,
      24,    25,    26,    53,    30,     1,    22,    27,     1,    52,
      27,    28,     1,    27,    28,    40,    45,    14,    35,    60,
       1,    16,    44,    60,    61,    39,    60,    62,     1,    52,
      52,    30,    54,     5,    52,    52,    52,    52,    52,     1,
      52,    30,    30,    27,     1,    27,    16,    27,    16,    10,
      45,    29,    49,    50,    28,    27,    28,    60,    60,    30,
       5,    48,    54,    27,    27,    50,    30,    16,    16,    54,
      30
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
//int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 10:
#line 32 "GRAMATICA.y"
    {notificar("Sentencia invalida");}
    break;

  case 13:
#line 41 "GRAMATICA.y"
    {addRegla("una declaracion de variable");}
    break;

  case 14:
#line 42 "GRAMATICA.y"
    {notificar("Se esperaba un identificador (o una lista de identificadores)");}
    break;

  case 15:
#line 43 "GRAMATICA.y"
    {notificar("Error luego de la lista de identificadores");}
    break;

  case 16:
#line 47 "GRAMATICA.y"
    {tipo="FLOAT";}
    break;

  case 17:
#line 48 "GRAMATICA.y"
    {tipo="INT";}
    break;

  case 18:
#line 52 "GRAMATICA.y"
    {declararVariable((yyvsp[(3) - (3)]), tipo);}
    break;

  case 19:
#line 53 "GRAMATICA.y"
    {declararVariable((yyvsp[(1) - (1)]), tipo);}
    break;

  case 20:
#line 54 "GRAMATICA.y"
    {notificar ("Error en la lista de identificadores");}
    break;

  case 21:
#line 57 "GRAMATICA.y"
    {hacerGlobal((yyvsp[(3) - (3)]));}
    break;

  case 22:
#line 58 "GRAMATICA.y"
    {hacerGlobal((yyvsp[(1) - (1)]));}
    break;

  case 23:
#line 59 "GRAMATICA.y"
    {notificar ("Error en la lista de identificadores");}
    break;

  case 26:
#line 65 "GRAMATICA.y"
    {notificar("Falta ';' para cerrar la iteracion");}
    break;

  case 28:
#line 67 "GRAMATICA.y"
    {notificar("Falta ';' para cerrar la sentencia PRINT");}
    break;

  case 30:
#line 73 "GRAMATICA.y"
    {	int incompleto = codGen->desapilar();
                                                                            			codGen->completarTerceto(incompleto, "["+QString::number(codGen->ultimoTerceto()+1)+"]", 3);
                                                                            			addRegla("el cierre de una sentencia de seleccion (IF-THEN)");
                                                                                        codGen->crearTerceto("Label", QString::number(codGen->ultimoTerceto()+1), "null");
                                                                        		}
    break;

  case 31:
#line 78 "GRAMATICA.y"
    {    int incompleto = codGen->desapilar();
                                                                                            	codGen->completarTerceto(incompleto, "["+QString::number(codGen->ultimoTerceto()+1)+"]", 2);
                                                                                            	addRegla("el cierre de una sentencia de seleccion (IF-THEN-ELSE)");
                                                                                                codGen->crearTerceto("Label", QString::number(codGen->ultimoTerceto()+1), "null");
                                                                                                			}
    break;

  case 32:
#line 83 "GRAMATICA.y"
    {notificar("Se encontro el cierre de una sentencia de seleccion a la que le falta la palabra reservada THEN");}
    break;

  case 33:
#line 84 "GRAMATICA.y"
    {notificar("Se encontro el cierre de una sentencia de seleccion a la que le falta la palabra reservada THEN");}
    break;

  case 34:
#line 87 "GRAMATICA.y"
    {   	int nroTerceto = codGen->crearTerceto("BF", "[" +QString::number(codGen->ultimoTerceto())+"]", "");
                                                    		codGen->apilar(nroTerceto);
                                               		}
    break;

  case 35:
#line 90 "GRAMATICA.y"
    {notificar("Se esperaba ')'");}
    break;

  case 36:
#line 91 "GRAMATICA.y"
    {notificar("Se esperaba '('");}
    break;

  case 37:
#line 92 "GRAMATICA.y"
    {notificar("Se esperaban parentesis alrededor de la condicion");}
    break;

  case 38:
#line 95 "GRAMATICA.y"
    {   	int incompleto = codGen->desapilar();
                                		codGen->completarTerceto(incompleto, "["+QString::number(codGen->ultimoTerceto()+2)+"]", 3);
                                		int nroTerceto = codGen->crearTerceto("BI", "", "null");
                                        codGen->crearTerceto("Label", QString::number(codGen->ultimoTerceto()+1), "null");
                                		codGen->apilar(nroTerceto);
                            		}
    break;

  case 39:
#line 103 "GRAMATICA.y"
    {   int nroInicio = codGen->desapilar();
                                                    int ultimoTerceto = codGen->ultimoTerceto();
                                                    codGen->crearTerceto("BF", "["+QString::number(ultimoTerceto)+"]", "["+QString::number(nroInicio)+"]");
                                                }
    break;

  case 40:
#line 107 "GRAMATICA.y"
    {notificar("Se esperaba ')'");}
    break;

  case 41:
#line 108 "GRAMATICA.y"
    {notificar("Se esperaba '('");}
    break;

  case 42:
#line 109 "GRAMATICA.y"
    {notificar("Se esperaban parentesis alrededor de la condicion");}
    break;

  case 43:
#line 112 "GRAMATICA.y"
    {	addRegla("una condicion"); 
											QString tipo1, tipo2;
											if (!tiposArrojados.empty())
												tipo1 = tiposArrojados.pop();
											if (!tiposArrojados.empty())
												tipo2 = tiposArrojados.pop();
											if (tipo1!=tipo2)
												notificar("Tipos incompatibles en la comparacion");
											else
												codGen->crearTerceto((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), codGen->obtenerTipo((yyvsp[(1) - (3)])));
									
										}
    break;

  case 44:
#line 124 "GRAMATICA.y"
    {notificar("Se esperaba una expresion en el lado derecho de la condicion");}
    break;

  case 45:
#line 125 "GRAMATICA.y"
    {notificar("Se esperaba una expresion en el lado izquierdo de la condicion");}
    break;

  case 46:
#line 126 "GRAMATICA.y"
    {notificar("Se esperaba un comparador entre las expresiones de la condicion");}
    break;

  case 47:
#line 127 "GRAMATICA.y"
    {notificar("Se esperaban expresiones alrededor del comparador");}
    break;

  case 48:
#line 128 "GRAMATICA.y"
    {notificar("Se esperaba una condicion");}
    break;

  case 49:
#line 132 "GRAMATICA.y"
    {addRegla("una sentencia de asignacion"); 
							    QString old = (yyvsp[(1) - (4)]);
							    (yyvsp[(1) - (4)]) = mangle((yyvsp[(1) - (4)]));
                                tabladeSimbolos->eliminar(old);
                                if ((yyvsp[(1) - (4)]) != "") {
                                    if (!tiposArrojados.empty()) {
                                        QString tipoExpr = tiposArrojados.pop();
                                        QString tipoId = tabladeSimbolos->obtenerTipo((yyvsp[(1) - (4)]));
                                       
                                        if (tipoExpr!=tipoId)
                                            notificar("Se esta intentando asignar una expresion de tipo " + tipoExpr + " a una variable de tipo " + tipoId);
                                        else
                                            codGen->crearTerceto("=", (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), tipoExpr);
                                    }
                                }
							    }
    break;

  case 50:
#line 148 "GRAMATICA.y"
    {addRegla("una sentencia de asignacion"); notificar("Falta ';' para cerrar la asignacion");}
    break;

  case 51:
#line 149 "GRAMATICA.y"
    {notificar("Se esperaba una expresion");}
    break;

  case 52:
#line 150 "GRAMATICA.y"
    {notificar("Error en la asignacion");}
    break;

  case 53:
#line 151 "GRAMATICA.y"
    {notificar("Se esperaba el operador de asignacion '='");}
    break;

  case 54:
#line 156 "GRAMATICA.y"
    {	(yyval) = "["+QString::number(codGen->crearTerceto("+", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), codGen->obtenerTipo((yyvsp[(1) - (3)]))))+"]";
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

  case 55:
#line 168 "GRAMATICA.y"
    {	(yyval) = "["+QString::number(codGen->crearTerceto("-", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), codGen->obtenerTipo((yyvsp[(1) - (3)]))))+"]";
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

  case 56:
#line 181 "GRAMATICA.y"
    {	tiposArrojados.pop();
									tiposArrojados.push("FLOAT");
									(yyval) = "["+QString::number(codGen->crearTerceto("TOFLOAT", (yyvsp[(3) - (4)]), "null","FLOAT"))+"]";
								}
    break;

  case 57:
#line 188 "GRAMATICA.y"
    {	(yyval) = "["+QString::number(codGen->crearTerceto("*", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), codGen->obtenerTipo((yyvsp[(1) - (3)]))))+"]";
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

  case 58:
#line 202 "GRAMATICA.y"
    {	(yyval) = "["+QString::number(codGen->crearTerceto("/", (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), codGen->obtenerTipo((yyvsp[(1) - (3)]))))+"]";
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

  case 59:
#line 218 "GRAMATICA.y"
    {	
									QString old = (yyvsp[(1) - (1)]);
									(yyvsp[(1) - (1)]) = mangle((yyvsp[(1) - (1)])); 
									(yyval)=(yyvsp[(1) - (1)]);
                                    tabladeSimbolos->eliminar(old);
                                    if ((yyvsp[(1) - (1)]) != "")
                                        tiposArrojados.push(tabladeSimbolos->obtenerTipo((yyvsp[(1) - (1)])));
									
									
								}
    break;

  case 60:
#line 228 "GRAMATICA.y"
    {	if (!rangoValido((yyvsp[(1) - (1)]), false)) {
										notificar("Constante entera fuera de rango");
										tiposArrojados.push("INT");
									} else {
										(yyval)=(yyvsp[(1) - (1)]);
										marcarUsada((yyvsp[(1) - (1)]));
										tiposArrojados.push(tabladeSimbolos->obtenerTipo((yyvsp[(1) - (1)])));
									}
								}
    break;

  case 61:
#line 238 "GRAMATICA.y"
    {	if (rangoValido((yyvsp[(2) - (2)]), true)) {
										(yyvsp[(2) - (2)]) = negativo((yyvsp[(2) - (2)]));
										(yyval)=(yyvsp[(2) - (2)]);
										tiposArrojados.push(tabladeSimbolos->obtenerTipo((yyvsp[(2) - (2)]))); 
									} else {
										notificar("Constante entera fuera de rango");
										tiposArrojados.push("INT");
									}
						   		}
    break;

  case 62:
#line 250 "GRAMATICA.y"
    {(yyval) = ">";}
    break;

  case 63:
#line 251 "GRAMATICA.y"
    {(yyval) = "<";}
    break;

  case 64:
#line 252 "GRAMATICA.y"
    {(yyval) = ">=";}
    break;

  case 65:
#line 253 "GRAMATICA.y"
    {(yyval) = "<=";}
    break;

  case 66:
#line 254 "GRAMATICA.y"
    {(yyval) = "<>";}
    break;

  case 67:
#line 255 "GRAMATICA.y"
    {(yyval) = "==";}
    break;

  case 69:
#line 260 "GRAMATICA.y"
    {addRegla("el cierre de un bloque BEGIN-END");}
    break;

  case 70:
#line 261 "GRAMATICA.y"
    {notificar("Falta ';' para cerrar el bloque BEGIN-END");}
    break;

  case 71:
#line 265 "GRAMATICA.y"
    {addRegla("una sentencia de iteracion");}
    break;

  case 72:
#line 269 "GRAMATICA.y"
    {   int inicioLoop = codGen->ultimoTerceto()+1;
                            codGen->apilar(inicioLoop);
                            codGen->crearTerceto("Label", QString::number(inicioLoop), "null");
                        }
    break;

  case 73:
#line 275 "GRAMATICA.y"
    {codGen->crearTerceto("PRINT", (yyvsp[(3) - (4)]), "null"); addRegla("una sentencia de impresion por pantalla");}
    break;

  case 74:
#line 276 "GRAMATICA.y"
    {notificar("Falta ')'");}
    break;

  case 75:
#line 277 "GRAMATICA.y"
    {notificar("Falta '('");}
    break;

  case 76:
#line 278 "GRAMATICA.y"
    {notificar ("Faltan parentesis alrededor de la cadena");}
    break;

  case 77:
#line 279 "GRAMATICA.y"
    {notificar("Se esperaba una cadena");}
    break;

  case 78:
#line 283 "GRAMATICA.y"
    {addRegla("el cierre de una declaracion de ambito");}
    break;

  case 79:
#line 284 "GRAMATICA.y"
    {addRegla("el cierre de una declaracion de ambito");}
    break;

  case 80:
#line 285 "GRAMATICA.y"
    {notificar("El ambito debe tener sentencias ejecutables");}
    break;

  case 81:
#line 286 "GRAMATICA.y"
    {notificar("Las sentencias declarativas del ambito deben estar antes que las ejecutables");}
    break;

  case 82:
#line 287 "GRAMATICA.y"
    {notificar("Error de sintaxis en el ambito");}
    break;

  case 83:
#line 290 "GRAMATICA.y"
    {       int aux =ambitos.value(sufijo);
                                    		aux++;
                                    		ambitos.remove(sufijo);
                                    		ambitos.insert(sufijo, aux);
                                		sufijo+= "_";
                                    		sufijo+= QString::number(aux);
                                		ambitos.insert(sufijo, 0);
                                	}
    break;

  case 84:
#line 300 "GRAMATICA.y"
    { sufijo = sufijoPadre(sufijo);}
    break;

  case 88:
#line 310 "GRAMATICA.y"
    {addRegla("una declaracion de variable global");}
    break;


/* Line 1267 of yacc.c.  */
#line 1982 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



