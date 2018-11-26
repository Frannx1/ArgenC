%{
    #include "y.tab.h"
    #include <string.h>
    #include <stdlib.h>

%}

alphabetic [A-Za-z_$]
digit [0-9]

%%

[\t \n]
numero                           return NUMERO;
texto                            return TEXTO;

imprimi                          return IMPRIMIR;
lee                              return LEER;
concatena(me)?                   return CONCATENAR;

poner                            return PONER;
en                               return EN;
mayuscula?                       return MAYUSCULA;
minuscula?                       return MINUSCULA;

mientras(\ que)?                 return MIENTRAS;
mientras(\ que)? no              return HASTA;
hasta(\ que)?                    return HASTA;
(repetir|hacer):?                return HACER;

si(\ pasa\ (que)?)?              return SI;
en\ cambio\ si(\ pasa\ (que)?)?  return SINOSI;
si\ no\ si                       return SINOSI;
si\ no                           return SINO;

fin                              return FIN;

es                               return ES;

por                              return MULTIPLICAR;
dividido                         return DIVIDIR;
incrementar                      return INCREMENTAR;
decrementar                      return DECREMENTAR;

no(\ debe ser)?                  return NO;
y(\ tambien)?                    return Y;
o(\ tambien)?                    return O;

no\ es(\ igual(\ a|que)?)?       return DESIGUAL;
es(\ igual(\ a|que)?)?           return IGUAL;
es equivalente\ (a)?             return IGUAL;

es\ menor\ (a|que)?              return MENOR;
es\ menor\ o\ igual(\ a|que)?    return MENOR_IGUAL;
es\ mayor\ (a|que)?              return MAYOR;
es\ mayor\ o\ igual(\ a|que)?    return MAYOR_IGUAL;


salir                            return SALIR;


.               {return yytext[0];}

%%
