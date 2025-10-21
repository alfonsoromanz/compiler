/* A Bison parser, made by GNU Bison 2.3.  */

#include <QString>

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef QString YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

