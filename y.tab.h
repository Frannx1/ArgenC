/* A Bison parser, made by GNU Bison 2.3.  */

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
     IDENTIFICADOR = 258,
     STRING = 259,
     ENTERO = 260,
     RANDOM = 261,
     DECIMAL = 262,
     NUMERO = 263,
     TEXTO = 264,
     NADA = 265,
     SI = 266,
     SINOSI = 267,
     SINO = 268,
     MIENTRAS = 269,
     HASTA = 270,
     HACER = 271,
     DESDE = 272,
     PORCADA = 273,
     RETORNA = 274,
     SEPARADOR = 275,
     ES = 276,
     POR = 277,
     DIVIDIDO = 278,
     DECREMENTAR = 279,
     INCREMENTAR = 280,
     NEGAR = 281,
     Y = 282,
     O = 283,
     DESIGUAL = 284,
     IGUAL = 285,
     MENOR = 286,
     MENOR_IGUAL = 287,
     MAYOR = 288,
     MAYOR_IGUAL = 289,
     IMPRIMIR = 290,
     LEER = 291,
     CONCATENAR = 292,
     A = 293,
     PONER = 294,
     EN = 295,
     MAYUSCULA = 296,
     MINUSCULA = 297,
     FIN = 298,
     SALIR = 299
   };
#endif
/* Tokens.  */
#define IDENTIFICADOR 258
#define STRING 259
#define ENTERO 260
#define RANDOM 261
#define DECIMAL 262
#define NUMERO 263
#define TEXTO 264
#define NADA 265
#define SI 266
#define SINOSI 267
#define SINO 268
#define MIENTRAS 269
#define HASTA 270
#define HACER 271
#define DESDE 272
#define PORCADA 273
#define RETORNA 274
#define SEPARADOR 275
#define ES 276
#define POR 277
#define DIVIDIDO 278
#define DECREMENTAR 279
#define INCREMENTAR 280
#define NEGAR 281
#define Y 282
#define O 283
#define DESIGUAL 284
#define IGUAL 285
#define MENOR 286
#define MENOR_IGUAL 287
#define MAYOR 288
#define MAYOR_IGUAL 289
#define IMPRIMIR 290
#define LEER 291
#define CONCATENAR 292
#define A 293
#define PONER 294
#define EN 295
#define MAYUSCULA 296
#define MINUSCULA 297
#define FIN 298
#define SALIR 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "parser.y"
{
    int intval;
    char *strval;
    float floatval;

    AssignmentNode *assignment;
    ArrayAssignment *arr_assign;

    WhileNode *whilenode;
    IfNode *ifnode;
    BoolNode *boolnode;
    FunctionNode*fnnode;
    ForNode *fornode;
    ForeachNode *foreachnode;

    ExpressionNode *exprnode;

    ExpressionList *explist;

    Block *block;

    StatementList *statements;

    bool_operation boolop;
}
/* Line 1529 of yacc.c.  */
#line 163 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

