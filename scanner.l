%{
	#include "tree.h"
    #include "y.tab.h"
    #include <string.h>
    #include <stdlib.h>

	static void comment(void);
	static void commentToDot(void);
	void yyerror (char *s);
%}

alpha [A-Za-z_$]
digit [0-9]

%option nounput yylineno


%%
"/*"                            { comment(); }
"//".*                          { /* consume //-comment */ }
(comentario|nota):              { commentToDot(); }

numero                          return NUMERO;
texto                           return TEXTO;

imprimi(r|me)?                  return IMPRIMIR;
lee(r|me)?                      return LEER;
concatena(r|me)?                return CONCATENAR;

pone(r|me)?                     return PONER;
en                              return EN;
mayuscula                       return MAYUSCULA;
minuscula                       return MINUSCULA;

\"|(,\ )    				    return SEPARADOR;
mientras(\ que)?                return MIENTRAS;
mientras(\ que)?\ no            return HASTA;
hasta(\ que)?                   return HASTA;
(repetir|hacer|entonces):?      return HACER;

(por|para)\ cada(\ un)?         return PORCADA;
desde                           return DESDE;

si(\ (pasa|es)(\ que)?)?        return SI;
en\ cambio\ si(\ pasa(\ que)?)? return SINOSI;
si\ no\ si                      return SINOSI;
si\ no                          return SINO;

fin                             return FIN;

es|=|vale                       return ES;

por                             return POR;
dividido                        return DIVIDIDO;
incrementar                     return INCREMENTAR;
decrementar                     return DECREMENTAR;

no(\ debe\ ser)?                return NEGAR;
y(\ tambien)?                   return Y;
o(\ tambien)?                   return O;

no\ es|sea(\ igual(\ (a|que))?)?    return DESIGUAL;
igual(\ (a|que))?                   return IGUAL;
(es|sea)\ equivalente\ (a)?         return IGUAL;

((es|sea)\ )?menor(\ (a|que))?             return MENOR;
((es|sea)\ )?menor\ o\ igual(\ (a|que))?   return MENOR_IGUAL;
((es|sea)\ )?mayor(\ (a|que))?             return MAYOR;
((es|sea)\ )?mayor\ o\ igual(\ (a|que))?   return MAYOR_IGUAL;

devuelve|retorna|da             return RETORNA;
nada|vacio			            {yylval.strval = "void"; return NADA;}
salir                           return SALIR;

random|aleatorio                return RANDOM;
{alpha}({alpha}|{digit})*	 	{yylval.strval   = strdup(yytext); return IDENTIFICADOR;}
{digit}+						{yylval.intval   = atoi(yytext);   return ENTERO;}
{digit}+\.{digit}+			    {yylval.floatval = atof(yytext);   return DECIMAL;}
\'[^\']*\'|\"[^\"]*\"			{
									yylval.strval = strndup(yytext +1, strlen(yytext) -2); 
									return STRING;
								}
[ \t\n]							;
.               				{return yytext[0];}

%%

static void comment(void) {
    int c;

    while ((c = input()) != 0)
        if (c == '*') {
            while ((c = input()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
    yyerror("unterminated comment");
}

static void commentToDot(void) {
    int c;

    while ((c = input()) != 0)
        if (c == '.') {
            return;
        }
    yyerror("unterminated comment");
}
