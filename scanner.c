#include <stdio.h>
#include "scanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char * names[] = {NULL, "NUMERO", "TEXTO", "IMPRIMIR", "LEER", "CONCATENAR", "PONER", "EN", "MAYUSCULA", "MINUSCULA", "MIENTRAS", "HASTA", "HACER", "SI", "SINOSI", "SINO", "FIN", "ES", "MULTIPLICAR", "DIVIDIR", "INCREMENTAR", "DECREMENTAR", "NO", "Y", "O", "DESIGUAL", "IGUAL", "MENOR", "MENOR_IGUAL", "MAYOR", "MAYOR_IGUAL", "SALIR"};


int main(void) {
	int ntoken, vtoken;
	ntoken = yylex();
	while(ntoken) {
		printf("%d - %s\n", ntoken, names[ntoken]);
	}
}