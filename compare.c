#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "variables.h"


#define EPSILON 0.00001

static int integerCompare(VAR intVar, VAR other);
static int floatCompare(VAR floatVar, VAR other);
static int stringCompare(VAR strVar, VAR other);

static int compatibleTypes(type_t t1, type_t t2);

int compare(VAR first, VAR second) {
	switch(first.type) {
		case INT_T:
			return integerCompare(first, second);

		case FLOAT_T:
			return floatCompare(first, second);

		case STR_T:
			return stringCompare(first, second);

		default:
			printf("Error. Valores incomparables: %s con %s\n", getNameofType(first.type), getNameofType(second.type));
			exit(0);
	}
}

int areEquals(VAR first, VAR second) {
	if (compatibleTypes(first.type, second.type))
		return compare(first, second) == 0;
	return 0;
}

static int compatibleTypes(type_t t1, type_t t2) {
	return t1 == t2 || (t1 == INT_T && t2 == FLOAT_T) || (t1 == FLOAT_T && t2 == INT_T);
}


static int integerCompare(VAR intVar, VAR other) {
	int i = intVar.value.intValue;

	switch(other.type) {
		case INT_T:
			return i - other.value.intValue;

		case FLOAT_T:
			return fabs(i - other.value.floatValue) < EPSILON ? 0 :
					(i - other.value.floatValue < 0) ? -1 : 1;

		default:
			printf("Error. Valores incomparables: %s con %s\n", getNameofType(intVar.type), getNameofType(other.type));
			exit(0);
	}
}


static int floatCompare(VAR floatVar, VAR other) {
	float i = floatVar.value.floatValue;
	switch(other.type){
		case INT_T:
			return -integerCompare(other, floatVar);

		case FLOAT_T:
			return fabs(i - other.value.floatValue) < EPSILON ? 0 :
					(i - other.value.floatValue < 0) ? -1 : 1;

		default:
			printf("Error. Valores incomparables: %s con %s\n", getNameofType(floatVar.type), getNameofType(other.type));
			exit(0);
	}
}


static int stringCompare(VAR strVar, VAR  other) {
		switch(other.type) {
		case STR_T:
			return strcmp(strVar.value.strValue, other.value.strValue);

		default:
			printf("Error. Valores incomparables: %s con %s\n", getNameofType(strVar.type), getNameofType(other.type));
			exit(0);
	}
}
