#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "variables.h"
#include "utils.h"
#include "arrays.h"


#define ABS(x) ((x) < 0 ? -(x) : (x))
#define EPSILON 0.0001

void printVariable(VAR var, int newline) {
	switch(var.type) {
		case INT_T:
			printf("%d", var.value.intValue);
			break;
		case STR_T:
			printf("%s", var.value.strValue);
			break;
		case FLOAT_T:
			printf("%f", var.value.floatValue);
			break;
		case ARRAY_T:
			printArray((Array)var.value.arrValue);
			break;
	}
	if(newline)
		printf("\n");
}

void append(int sourceId, VAR elem) {
	VAR sourceVar = getVariable(sourceId);

	if (sourceVar.type != STR_T && sourceVar.type != ARRAY_T) {
		printf("Error: se intenta anexar a algo que no es una %s ni un %s. El programa no puede continuar\n",
			getNameofType(ARRAY_T), getNameofType(STR_T));
		exit(1);
	}
	assign(sourceId, sum(sourceVar, elem));
}

void toUpperString(int stringId) {
	VAR stringVar = getVariable(stringId);
	char * str;
	int i;

	if (stringVar.type != STR_T){
		printf("Error: se intenta pasar a mayuscula algo que no es un %s", getNameofType(STR_T));
		exit(1);
	}

	str = stringVar.value.strValue;

	for (i = 0; str[i] != '\0'; i++)
		str[i] = toupper(str[i]);
}

void toLowerString(int stringId) {
	VAR stringVar = getVariable(stringId);
	char * str;
	int i;

	if (stringVar.type != STR_T) {
		printf("Error: se intenta pasar a minuscula algo que no es un %s", getNameofType(STR_T));
		exit(1);
	}

	str = stringVar.value.strValue;

	for (i = 0; str[i] != '\0'; i++)
		str[i] = tolower(str[i]);
}

void inc(int id) {
	VAR num_var = getVariable(id);

	if (num_var.type != INT_T && num_var.type != FLOAT_T){
		printf("Error: se intenta incrementar algo que no es un %s", getNameofType(INT_T));
		exit(1);
	}

	assign(id, sum(num_var, anonInteger(1)));
}

void dec(int id) {
	VAR var = getVariable(id);

	if (var.type != INT_T && var.type != FLOAT_T) {
		printf("Error: se intenta decrementar algo que no es un %s", getNameofType(INT_T));
		exit(1);
	}

	assign(id, substract(var, anonInteger(1)));
}

void scan(int type, VAR_ID elem) {
	if (type == 0) {
		double read;
		scanf("%lg", &read);
		while(getchar() != '\n');
		double dif = read - (long)read;
		if(ABS(dif) < EPSILON)
			assign(elem, anonInteger((int)read));
		else 
			assign(elem, anonFloat(read));
	} else if (type == 1) {
		char * text = malloc(256);
		scanf("%255[^\n]", text);
		while(getchar() != '\n');
		assign(elem, anonString(text));
		free(text);
	}
}
