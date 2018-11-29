%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

#define MAX_IDS 10000

int yylex();
void yyerror (char const *s);

int var_count = 0;

char *identifiers[MAX_IDS] = {0};
int list_length(ExpressionList *list);
int getId(char *strId);

%}

%union {
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

%error-verbose

%token <strval>   IDENTIFICADOR STRING;
%token <intval>   ENTERO RANDOM;
%token <floatval> DECIMAL;

%token NUMERO TEXTO NADA;
%token SI SINOSI SINO MIENTRAS HASTA HACER DESDE PORCADA RETORNA SEPARADOR;

%token ES;
%token POR DIVIDIDO DECREMENTAR INCREMENTAR;
%token NEGAR Y O;
%token DESIGUAL IGUAL MENOR MENOR_IGUAL MAYOR MAYOR_IGUAL;

%token IMPRIMIR LEER CONCATENAR A;
%token PONER EN;
%token MAYUSCULA MINUSCULA;
%token FIN;
%token SALIR

%type <assignment> asig;
%type <arr_assign> arr_asig;

%type <statements> program;
%type <exprnode> print;
%type <block> block;
%type <explist> explist;
%type <explist> array;

%type <fnnode> func_call;

%type <whilenode> while dowhile;
%type <foreachnode> foreach;
%type <fornode> for;

%type <ifnode> if;
%type <ifnode> elseif;

%type <boolop> bool_comp;
%type <boolnode> condition;
%type <exprnode> expression;
%type <exprnode> arr_indexing;

%left '+' '-';
%left '*' '/' POR DIVIDIDO;

%left MENOR_IGUAL MAYOR_IGUAL IGUAL
%left Y O NEGAR

%start entry

%%

entry: 
    program {realize($1);}
    ;

program:
    block {
        $$ = malloc(sizeof(*$$));
        $$->type = $1->type;;
        $$->body = $1->node;
        $$->next = NULL;

        free($1);
    }
    | block program {
        $$ = malloc(sizeof(*$$));

        $$->type = $1->type;
        $$->body = $1->node;
        $$->next = $2;

        free($1);
    }
    ;

block: 
    asig {
        $$ = malloc(sizeof(*$$));
        $$->type = ASSIGNMENT;
        $$->node = $1;
    }
    | arr_asig {
        $$ = malloc(sizeof(*$$));
        $$->type = ARRAY_ASSIGNMENT;
        $$->node = $1;
    }
    | print {
        $$ = malloc(sizeof(*$$));
        $$->type = PRINT_CALL;
        $$->node = $1;
    }
    | while {
        $$ = malloc(sizeof(*$$));
        $$->type = WHILE_LOOP;
        $$->node = $1;
    }
    | dowhile {
        $$ = malloc(sizeof(*$$));
        $$->type = DO_WHILE_LOOP;
        $$->node = $1;
    }
    | foreach {
        $$ = malloc(sizeof(*$$));
        $$->type = FOREACH_LOOP;
        $$->node = $1;
    }
    | for {
        $$ = malloc(sizeof(*$$));
        $$->type = FOR_LOOP;
        $$->node = $1;
    }
    | if {
        $$ = malloc(sizeof(*$$));
        $$->type = IF_THEN_ELSE;
        $$->node = $1;
    }
    | func_call {
        $$ = malloc(sizeof(*$$));
        $$->type = FUNCTION_CALL;
        $$->node = $1;
    }
    | exit {
        $$ = malloc(sizeof(*$$));
        $$->type = EXIT_CALL;
    }
    ;

exit: 
    SALIR;
    ;

asig:  
    IDENTIFICADOR ES expression {
        $$ = malloc(sizeof(*$$));
        $$->var_id = getId($1);

        $$->value = $3;
    }
	;

arr_asig: 
    arr_indexing ES expression {
		$$ = malloc(sizeof(*$$));
		$$->array = $1;
		$$->value = $3;
	}
	;

expression: 
    STRING {
        $$ = malloc(sizeof(*$$));
        $$->type = STR_LITERAL;
        $$->left = malloc(strlen($1) + 1);
        strcpy($$->left, $1);
    }
    | ENTERO {
        $$ = malloc(sizeof(*$$));
        $$->type = INT_LITERAL;
        $$->left = malloc(sizeof(int));
        memcpy($$->left, &$1, sizeof(int));
    }
    | DECIMAL {
	 		$$ = malloc(sizeof(*$$));
			$$->type = FLOAT_LITERAL;
			$$->left = malloc(sizeof(float));
			memcpy($$->left, &$1, sizeof(float));
    }
    | RANDOM {
	 		$$ = malloc(sizeof(*$$));
			$$->type = RANDOM_LITERAL;
    }
	| array {
	 	$$ = malloc(sizeof(*$$));
	 	$$->type = ARRAY_LITERAL;
	 	$$->left = $1;
	 	$$->right = malloc(sizeof(int));
	 	*((int*)$$->right) = list_length($1);
	}
    | IDENTIFICADOR {
        $$ = malloc(sizeof(*$$));
        $$->type = VARIABLE;
        $$->left = malloc(sizeof(int));
        int id = getId($1);
        memcpy($$->left, &id, sizeof(int));
    }
    | arr_indexing {
        $$ = $1;
    }
    | expression '+' expression {
        $$ = malloc(sizeof(*$$));
        $$->type = ARIT_SUM;
        $$->left = $1;
        $$->right = $3;
    }
    | expression '-' expression {
        $$ = malloc(sizeof(*$$));
        $$->type = ARIT_SUB;
        $$->left = $1;
        $$->right = $3;
	}
	| expression '*' expression {
        $$ = malloc(sizeof(*$$));
        $$->type = ARIT_PROD;
        $$->left = $1;
        $$->right = $3;
    }
    | expression POR expression {
        $$ = malloc(sizeof(*$$));
        $$->type = ARIT_PROD;
        $$->left = $1;
        $$->right = $3;
    }
	| expression '/' expression {
        $$ = malloc(sizeof(*$$));
        $$->type = ARIT_DIV;
        $$->left = $1;
        $$->right = $3;
	}
    | expression DIVIDIDO expression {
        $$ = malloc(sizeof(*$$));
        $$->type = ARIT_DIV;
        $$->left = $1;
        $$->right = $3;
    }
	| '-' expression {
        $$ = malloc(sizeof(*$$));
        $$->type = ARIT_UNARY_MINUS;
        $$->left = $2;
    }
	| '(' expression ')' {
        $$ = $2;
    }
    ;

func_call: 
    CONCATENAR expression EN IDENTIFICADOR {
        $$ = malloc(sizeof(*$$));
        $$->function = ARR_APPEND;
        $$->first = malloc(sizeof(int));
        *((int*)$$->first) = getId($4);
        $$->second = $2;
    }
    | PONER IDENTIFICADOR EN MAYUSCULA {
        $$ = malloc(sizeof(*$$));
        $$->function = TO_UPPER;
        $$->first = malloc(sizeof(int));
        *((int*)$$->first) = getId($2);
    }
    | PONER IDENTIFICADOR EN MINUSCULA {
        $$ = malloc(sizeof(*$$));
        $$->function = TO_LOWER;
        $$->first = malloc(sizeof(int));
        *((int*)$$->first) = getId($2);
    }
    | INCREMENTAR IDENTIFICADOR {
        $$ = malloc(sizeof(*$$));
        $$->function = INCREMENT;
        $$->first = malloc(sizeof(int));
        *((int*)$$->first) = getId($2);
    }
    | DECREMENTAR IDENTIFICADOR {
        $$ = malloc(sizeof(*$$));
        $$->function = DECREMENT;
        $$->first = malloc(sizeof(int));
        *((int*)$$->first) = getId($2);
    }
    | LEER NUMERO EN IDENTIFICADOR {
        $$ = malloc(sizeof(*$$));
        $$->function = SCAN_READ;
        $$->first = malloc(sizeof(int));
        *((int*)$$->first) = 0;  // 0 = NUMERO
        $$->second = malloc(sizeof(int));
        *((int*)$$->second) = getId($4);
    }
    | LEER TEXTO EN IDENTIFICADOR {
        $$ = malloc(sizeof(*$$));
        $$->function = SCAN_READ;
        $$->first = malloc(sizeof(int));
        *((int*)$$->first) = 1;  // 1 = TEXTO
        $$->second = malloc(sizeof(int));
        *((int*)$$->second) = getId($4);
    }
    ;

array: 
    '[' explist ']' {
	    $$ = $2;
	}
	| '[' ']' {
	  	$$ = NULL;
	}
    ;

arr_indexing: 
    IDENTIFICADOR '[' expression ']' {
        $$ = malloc(sizeof(*$$));
        $$->type = INDEXED_ARRAY;

        $$->left = malloc(sizeof(int));
        int id = getId($1);
        memcpy($$->left, &id, sizeof(int));

        $$->right = $3;
    }
    | arr_indexing '[' expression ']' {
        $$ = malloc(sizeof(*$$));
        $$->type = NESTED_INDEXING;
        $$->left = $1;
        $$->right = $3;
    }
    ;

explist: 
    expression {
        $$ = malloc(sizeof(*$$));
        $$->expression = $1;
        $$->next = NULL;
    }
    | expression ',' explist {
        $$ = malloc(sizeof(*$$));
        $$->expression = $1;
        $$->next = $3;
    }
    ;

print: 
    IMPRIMIR expression {
		$$ = $2;
	}
	;

while: 
    MIENTRAS SEPARADOR condition SEPARADOR HACER program FIN {
        $$ = malloc(sizeof(*$$));
        $$->condition = $3;
        $$->body = $6;
    }
    | HASTA SEPARADOR condition SEPARADOR HACER program FIN {
        $$ = malloc(sizeof(*$$));
        $$->condition = malloc(sizeof(*$$->condition));
        $$->condition->type = BOOL_NOT;
        $$->condition->left = $3;
        $$->body = $6;
    }
    | MIENTRAS condition SEPARADOR HACER program FIN {
        $$ = malloc(sizeof(*$$));
        $$->condition = $2;
        $$->body = $5;
    }
    | HASTA condition SEPARADOR HACER program FIN {
        $$ = malloc(sizeof(*$$));
        $$->condition = malloc(sizeof(*$$->condition));
        $$->condition->type = BOOL_NOT;
        $$->condition->left = $2;
        $$->body = $5;
    }
    ;

dowhile: 
    HACER program FIN MIENTRAS condition {
        $$ = malloc(sizeof(*$$));
        $$->condition = $5;
        $$->body = $2;
    }
    | HACER program FIN HASTA condition {
        $$ = malloc(sizeof(*$$));
        $$->condition = malloc(sizeof(*$$->condition));
        $$->condition->type = BOOL_NOT;
        $$->condition->left = $5;
        $$->body = $2;
    }
    | HACER program FIN HASTA SEPARADOR condition SEPARADOR {
        $$ = malloc(sizeof(*$$));
        $$->condition = malloc(sizeof(*$$->condition));
        $$->condition->type = BOOL_NOT;
        $$->condition->left = $6;
        $$->body = $2;
    }
    ;

foreach: 
    PORCADA IDENTIFICADOR EN IDENTIFICADOR HACER program FIN {
        $$ = malloc(sizeof(*$$));
        $$->current = getId($2);
        $$->list = getId($4);
        $$->body = $6;
    }
    | PORCADA IDENTIFICADOR EN IDENTIFICADOR SEPARADOR HACER program FIN {
        $$ = malloc(sizeof(*$$));
        $$->current = getId($2);
        $$->list = getId($4);
        $$->body = $7;
    }
    ;

for:
    DESDE asig HASTA SEPARADOR condition SEPARADOR HACER program FIN {
        $$ = malloc(sizeof(*$$));
        $$->asig = $2;
        $$->condition = $5;
        $$->body = $8;
    }
    | DESDE HASTA SEPARADOR condition SEPARADOR HACER program FIN {
        $$ = malloc(sizeof(*$$));
        $$->asig = NULL;
        $$->condition = $4;
        $$->body = $7;
    }
    | DESDE asig HASTA condition SEPARADOR HACER program FIN {
        $$ = malloc(sizeof(*$$));
        $$->asig = $2;
        $$->condition = $4;
        $$->body = $7;
    }
    | DESDE HASTA condition SEPARADOR HACER program FIN {
        $$ = malloc(sizeof(*$$));
        $$->asig = NULL;
        $$->condition = $3;
        $$->body = $6;
    }
    ;

if: 
    SI SEPARADOR condition SEPARADOR HACER program FIN {
        $$ = malloc(sizeof(*$$));
        $$->condition = $3;
        $$->body = $6;
        $$->elseif = NULL;

    }
    | SI SEPARADOR condition SEPARADOR HACER program FIN elseif {
        $$ = malloc(sizeof(*$$));
        $$->condition = $3;
        $$->body = $6;
        $$->elseif = $8;
    }
    | SI condition SEPARADOR HACER program FIN {
        $$ = malloc(sizeof(*$$));
        $$->condition = $2;
        $$->body = $5;
        $$->elseif = NULL;

    }
    | SI condition SEPARADOR HACER program FIN elseif {
        $$ = malloc(sizeof(*$$));
        $$->condition = $2;
        $$->body = $5;
        $$->elseif = $7;
    }
    ;

elseif: 
    SINOSI SEPARADOR condition SEPARADOR program FIN {
        $$ = malloc(sizeof(*$$));
        $$->condition = $3;
        $$->body = $5;
        $$->elseif = NULL;
    }
    | SINOSI SEPARADOR condition SEPARADOR program FIN elseif {
        $$ = malloc(sizeof(*$$));
        $$->condition = $3;
        $$->body = $5;
        $$->elseif = $7;
    }
    | SINOSI condition program FIN {
        $$ = malloc(sizeof(*$$));
        $$->condition = $2;
        $$->body = $3;
        $$->elseif = NULL;
    }
    | SINOSI condition program FIN elseif {
        $$ = malloc(sizeof(*$$));
        $$->condition = $2;
        $$->body = $3;
        $$->elseif = $5;
    }
    | SINO program FIN {
        $$ = malloc(sizeof(*$$));
        $$->body = $2;
        $$->elseif = NULL;
        $$->condition = malloc(sizeof(*$$->condition));
        $$->condition->type = TRUE_LITERAL;
    }
    ;

condition: 
    expression bool_comp expression {
        $$ = malloc(sizeof(*$$));
        $$->type = $2;

        $$->left = $1;
        $$->right = $3;
    }
    | condition O condition {
        $$ = malloc(sizeof(*$$));
        $$->type = BOOL_OR;

        $$->left = $1;
        $$->right = $3;
    }
    | condition Y condition {
        $$ = malloc(sizeof(*$$));
        $$->type = BOOL_AND;

        $$->left = $1;
        $$->right = $3;

    }
    | NEGAR condition {
        $$ = malloc(sizeof(*$$));
        $$->type = BOOL_NOT;

        $$->left = $2;
        $$->right = NULL;
    }
    ;

bool_comp: 
    MENOR_IGUAL   { $$ = COMP_LE;  }
    | MENOR       { $$ = COMP_LT;  }
    | MAYOR_IGUAL { $$ = COMP_GE;  }
    | MAYOR       { $$ = COMP_GT;  }
    | IGUAL       { $$ = COMP_EQ;  }
    | DESIGUAL    { $$ = COMP_NEQ; }
    ;

%%

int main() {
	printf("#include <stdlib.h>\n");

	printf("#include <time.h>\n");

	printf("#include \"variables.h\"\n");

	printf("#include \"arrays.h\"\n");

	printf("#include \"utils.h\"\n");

    printf("\nint main(void) { \n\n");

    printf("srand(time(NULL));\n\n");

    // Start the Parsing (yacc)
    yyparse();

    printf("}\n");

    return 0;
}

int getId(char *strId) {
	int i;

	for(i = 0 ; i < MAX_IDS && identifiers[i] != NULL ; i++) {
		if(strcmp(identifiers[i], strId) == 0) {
			return i;
		}
	}

	if(i == MAX_IDS) {
		return -1;
	}

	identifiers[i] = malloc(strlen(strId) + 1);
	strcpy(identifiers[i], strId);
	printf("mapAName(%d, \"%s\");\n", i, strId);

	return i;
}

int list_length(ExpressionList *list) {
	int len = 0;
	while(list != NULL) {
		len++;
		list = list->next;
	}
	return len;
}

int yywrap() {
    return 1;
}

void yyerror(const char *s) {
    extern int yylineno;  
    extern char *yytext;  
    fprintf(stderr, "ERROR: %s at symbol '%s' on line %d\n", s, yytext, yylineno);
}
