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
     DECIMAL = 261,
     NUMERO = 262,
     TEXTO = 263,
     NADA = 264,
     SI = 265,
     SINOSI = 266,
     SINO = 267,
     MIENTRAS = 268,
     HASTA = 269,
     HACER = 270,
     DESDE = 271,
     PORCADA = 272,
     RETORNA = 273,
     SEPARADOR = 274,
     ES = 275,
     POR = 276,
     DIVIDIDO = 277,
     DECREMENTAR = 278,
     INCREMENTAR = 279,
     NEGAR = 280,
     Y = 281,
     O = 282,
     DESIGUAL = 283,
     IGUAL = 284,
     MENOR = 285,
     MENOR_IGUAL = 286,
     MAYOR = 287,
     MAYOR_IGUAL = 288,
     IMPRIMIR = 289,
     LEER = 290,
     CONCATENAR = 291,
     A = 292,
     PONER = 293,
     EN = 294,
     MAYUSCULA = 295,
     MINUSCULA = 296,
     FIN = 297,
     SALIR = 298
   };
#endif
/* Tokens.  */
#define IDENTIFICADOR 258
#define STRING 259
#define ENTERO 260
#define DECIMAL 261
#define NUMERO 262
#define TEXTO 263
#define NADA 264
#define SI 265
#define SINOSI 266
#define SINO 267
#define MIENTRAS 268
#define HASTA 269
#define HACER 270
#define DESDE 271
#define PORCADA 272
#define RETORNA 273
#define SEPARADOR 274
#define ES 275
#define POR 276
#define DIVIDIDO 277
#define DECREMENTAR 278
#define INCREMENTAR 279
#define NEGAR 280
#define Y 281
#define O 282
#define DESIGUAL 283
#define IGUAL 284
#define MENOR 285
#define MENOR_IGUAL 286
#define MAYOR 287
#define MAYOR_IGUAL 288
#define IMPRIMIR 289
#define LEER 290
#define CONCATENAR 291
#define A 292
#define PONER 293
#define EN 294
#define MAYUSCULA 295
#define MINUSCULA 296
#define FIN 297
#define SALIR 298




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
#line 161 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

