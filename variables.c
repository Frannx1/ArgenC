#include "variables.h"
#include "arrays.h"
#include "utils.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

VAR * varTable[MAX_VARS] = {0};
char* nameTable[MAX_VARS] = {0};

void mapAName(VAR_ID id, char * name) {
	nameTable[id] = name;
}

char* getNameofType(type_t type) {
	switch(type) {
		case INT_T:
		case FLOAT_T:
			return "número";
		case STR_T:
			return "texto";
		case ARRAY_T:
			return "lista";
		default:
			return "(algo desconocido)";
	}
	return "";
}

VAR getVariable(VAR_ID id) {
	if(varTable[id] == NULL) {
		fprintf(stderr, "Error fatal: usted intentó utilizar una variable nunca antes definida, de nombre '%s'.\nAsegúrese de no haberse equivocado y recompile. \n", nameTable[id]);
		exit(1);
	}
	return *varTable[id];
}

VAR anonFloat(float value) {
	VAR var;
	var.type = FLOAT_T;
	var.value.floatValue = value;
	return var;
}

VAR anonInteger(int value) {
	VAR var;
	var.type = INT_T;
	var.value.intValue = value;
	return var;
}

VAR anonString(char * value) {
	VAR var;
	var.type = STR_T;

	var.value.strValue = malloc(strlen(value) + 1);
	strcpy(var.value.strValue, value);

	return var;
}

VAR anonArray(int num, ...) {
	VAR var;
	var.type = ARRAY_T;

	var.value.arrValue = createArray();

	va_list valist;
	va_start(valist, num);
	for (int i = 0; i < num; i++)
      pushArray(var.value.arrValue, va_arg(valist, VAR));
   	va_end(valist);

	return var;
}

VAR indexOfArray(VAR array, VAR index) {
	if(array.type != ARRAY_T) {
		printf("Error fatal: se intenta acceder a un elemento de algo que no es una lista\n");
		exit(1);
	}

	if(index.type != INT_T) {
		printf("Error fatal: se intenta acceder a un elemento no entero de una lista.\n");
		exit(1);
	}

	return accessToArray(array.value.arrValue, index.value.intValue);
}

void assignmentOfArray(VAR array, VAR index, VAR new) {
	if(array.type != ARRAY_T) {
		printf("Error fatal: se intenta acceder a un elemento de algo que no es una lista\n");
		exit(1);
	}

	if(index.type != INT_T) {
		printf("Error fatal: se intenta acceder a un elemento no entero de una lista.\n");
		exit(1);
	}

	editArray(array.value.arrValue, index.value.intValue, new);
}

VAR cloneVariable(VAR var) {
	switch(var.type) {
		case INT_T:
		case FLOAT_T:
			return var;

		case STR_T:
			return anonString(var.value.strValue);

		case ARRAY_T:
		{
			VAR clone;
			clone.type = ARRAY_T;
			clone.value.arrValue = cloneArray(var.value.arrValue);
			return clone;
		}

		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", var.type);
			exit(0);
	}
}

VAR assign(VAR_ID id, VAR assigned) {
	VAR * var = malloc(4 * sizeof(*varTable[0]));

	var->type = assigned.type;

	switch(assigned.type) {
		case INT_T:
			var->value.intValue =  assigned.value.intValue;
		break;

		case STR_T:
			var->value.strValue = malloc(strlen(assigned.value.strValue) + 1);
			strcpy(var->value.strValue, assigned.value.strValue);
		break;

		case FLOAT_T:
			var->value.floatValue = assigned.value.floatValue;
		break;
		case ARRAY_T:
			var->value.arrValue = cloneArray(assigned.value.arrValue);
		break;
	}
	freeVariable(varTable[id]);
	varTable[id] = var;

	return *var;

}

void freeVariable(VAR *variable) {
	if(variable == NULL) return;

	switch(variable->type){
		case STR_T:
			free(variable->value.strValue);
			break;
		case ARRAY_T:
			freeArray(variable->value.arrValue);
			break;
	}

}

