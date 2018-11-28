#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "variables.h"
#include "arrays.h"

#define MAX_DIGITS 30

static VAR sumOfIntegers(VAR left, VAR right, int sign);
static VAR sumOfFloat(VAR left, VAR right, int sign);
static VAR sumOfString(VAR left, VAR right);
static VAR sumOfArray(VAR left, VAR right);
static VAR subOfString(VAR left, VAR right);
static VAR subOfCString(const char * left_str, const char * right_str);
static int isBeginSubStr(const char * str, const char * sub);
static VAR subOfArray(VAR left, VAR right);
static VAR productOfInteger(VAR left, VAR right);
static VAR productOfFloat(VAR left, VAR right);
static VAR productOfString(VAR left, VAR right);
static VAR divisionOfInteger(VAR left, VAR right);
static VAR divisionOfFloat(VAR left, VAR right);
static VAR divisionOfString(VAR left, VAR right);


VAR sum(VAR left, VAR right) {
	switch(left.type) {
		case INT_T:
			return sumOfIntegers(left, right, 1);
		case STR_T:
			return sumOfString(left, right);
		case FLOAT_T:
			return sumOfFloat(left, right, 1);
		case ARRAY_T:
			return sumOfArray(left, right);
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", left.type);
			exit(0);
	}
}

VAR substract(VAR left, VAR right) {
	switch(left.type) {
		case INT_T:
			return sumOfIntegers(left, right, -1);
		case STR_T:
			return subOfString(left, right);
		case FLOAT_T:
			return sumOfFloat(left, right, -1);
		case ARRAY_T:
			return subOfArray(left, right);
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", left.type);
			exit(0);
	}
}

VAR product(VAR left, VAR right) {
	switch(left.type) {
		case INT_T:
			return productOfInteger(left, right);
		case STR_T:
			return productOfString(left, right);
		case FLOAT_T:
			return productOfFloat(left, right);
		case ARRAY_T:
			printf("Error. Una %s no puede ser multiplicada\n", getNameofType(ARRAY_T));
			exit(0);
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", left.type);
			exit(0);
		}
}

VAR division(VAR left, VAR right) {
	switch(left.type) {
		case INT_T:
			return divisionOfInteger(left, right);
		case STR_T:
			return divisionOfString(left, right);
		case FLOAT_T:
			return divisionOfFloat(left, right);
		case ARRAY_T:
			printf("Error. Una %s no puede ser dividida\n", getNameofType(ARRAY_T));
			exit(0);
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", left.type);
			exit(0);
	}
}


VAR minus(VAR var) {

	switch(var.type){
		case INT_T:
		case FLOAT_T:
			var.value.intValue = -var.value.intValue;
			break;
		default:
			break;
	}

	return var;
}



static VAR sumOfIntegers(VAR left, VAR right, int sign) {
	switch(right.type) {
		case INT_T:
		{
			int iresult = left.value.intValue + sign * right.value.intValue;
			return anonInteger(iresult);
		}
		case FLOAT_T:
		{
			float fresult = left.value.intValue + sign * right.value.floatValue;
			return anonFloat(fresult);
		}
		case STR_T:
		{
			if(sign < 0)
				exit(1);

			char * str = malloc(strlen(right.value.strValue) + MAX_DIGITS);
			sprintf(str, "%d%s", left.value.intValue, right.value.strValue);
			VAR ret = anonString(str);
			free(str);
			return ret;
		}
		case ARRAY_T:
			printf("Error. No se puede sumar una %s a un %s. El programa no puede continuar.\n", getNameofType(ARRAY_T), getNameofType(INT_T));
			exit(0);
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", right.type);
			exit(0);
	}
}


static VAR sumOfFloat(VAR left, VAR right, int sign){
	switch(right.type){
		case INT_T:
		{
			float iresult = left.value.floatValue + right.value.intValue;
			iresult *= sign;
			return anonInteger(iresult);
		}
		case FLOAT_T:
		{
			float fresult = left.value.floatValue + right.value.floatValue;
			fresult *= sign;
			return anonFloat(fresult);
		}
		case STR_T:
		{
			if(sign < 0)
				exit(1);

			char * str = malloc(strlen(right.value.strValue) + MAX_DIGITS);
			sprintf(str, "%f%s", left.value.floatValue, right.value.strValue);
			VAR ret = anonString(str);
			free(str);
			return ret;
		}
		case ARRAY_T:
			printf("Error. No se puede sumar una %s a un %s. El programa no puede continuar.\n", getNameofType(ARRAY_T), getNameofType(FLOAT_T));
			exit(0);
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", right.type);
			exit(0);
	}
}


static VAR sumOfString(VAR left, VAR right) {
		switch(right.type) {
		case INT_T:
		{
			char * str = malloc(MAX_DIGITS + strlen(left.value.strValue) + 1);
			sprintf(str, "%s%d", left.value.strValue, right.value.intValue);
			VAR ret = anonString(str);
			free(str);
			return ret;
		}
		case FLOAT_T:
		{
			char * str = malloc(MAX_DIGITS + strlen(left.value.strValue) + 1);
			sprintf(str, "%s%3f", left.value.strValue, right.value.floatValue);
			VAR ret = anonString(str);
			free(str);
			return ret;
		}
		case STR_T:
		{
			char * str = malloc(strlen(left.value.strValue) + strlen(right.value.strValue) + 1);
			sprintf(str, "%s%s", left.value.strValue, right.value.strValue);
			VAR ret = anonString(str);
			free(str);
			return ret;
		}
		case ARRAY_T:
			printf("Error. No se puede sumar una %s a un %s. El programa no puede continuar.\n", getNameofType(ARRAY_T), getNameofType(STR_T));
			exit(0);
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", right.type);
			exit(0);
	}
}


static VAR sumOfArray(VAR left, VAR right) {
	switch(right.type) {
		case ARRAY_T:
		{
			VAR ary;
			ary.type = ARRAY_T;
			ary.value.arrValue = cloneArray(left.value.arrValue);
			concatArray(ary.value.arrValue, right.value.arrValue);
			return ary;
		}
		case INT_T:
		case FLOAT_T:
		case STR_T:
		{
			VAR ary;
			ary.type = ARRAY_T;
			ary.value.arrValue = cloneArray(left.value.arrValue);
			pushArray((Array)(ary.value.arrValue), right);
			return ary;
		}
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", right.type);
			exit(0);
	}
}


static VAR subOfString(VAR left, VAR right){
	switch(right.type) {
		case STR_T:
			return subOfCString(left.value.strValue, right.value.strValue);
		default:
			printf("Error: a un %s solo se le puede restar otro %s. El programa no puede continuar.\n", getNameofType(STR_T), getNameofType(STR_T));
			exit(1);
	}
}

static VAR subOfCString(const char * left_str, const char * right_str){
	char * str = malloc(strlen(left_str) + 1);
	int right_len = strlen(right_str);
	int i, j;

	for (i = j = 0; left_str[i] != '\0'; i++) {
		if (isBeginSubStr(&left_str[i], right_str))
			i += right_len - 1;
		else
			str[j++] = left_str[i];
	}

	str[j] = '\0';

	VAR ans = anonString(str);
	free(str);
	return ans;
}

static int isBeginSubStr(const char * str, const char * sub) {
	int i;

	for (i = 0; str[i] != '\0' && sub[i] != '\0'; i++)
		if (str[i] != sub[i])
			return 0;

	return sub[i] == '\0';
}

static VAR subOfArray(VAR left, VAR right) {
	VAR ans;
	ans.type = ARRAY_T;

	switch(right.type) {
		case ARRAY_T:
			ans.value.arrValue = substractArray(left.value.arrValue, right.value.arrValue);
			return ans;
		default:
			ans.value.arrValue = removeArray(left.value.arrValue, right);
			return ans;
	}
}

static VAR productOfInteger(VAR left, VAR right) {
	switch(right.type) {
		case INT_T:
		{
			int iresult = left.value.intValue * right.value.intValue;
			return anonInteger(iresult);
		}
		case FLOAT_T:
		{
			float fresult = left.value.intValue * right.value.floatValue;
			return anonFloat(fresult);
		}
		case STR_T:
		{
			if(right.value.intValue < 0) {
				printf("Error: se intenta multiplicar un texto por un numero negativo. El programa no puede continuar\n");
				exit(1);
			}

			int i;
			int len = strlen(right.value.strValue);
			char * str = malloc(len*left.value.intValue + 1);
			for(i=0 ; i < left.value.intValue ; i++){
				memcpy(str+i*len, right.value.strValue, len);
			}
			*(str+left.value.intValue*len + 1) = 0;

			VAR ret = anonString(str);
			free(str);
			return ret;
		}
		case ARRAY_T:
		{
			VAR multi = anonArray(0);
			int i;
			for(i = 0 ; i < left.value.intValue ; i++){
				concatArray(multi.value.arrValue, right.value.arrValue);
			}
			return multi;
		}
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", right.type);
			exit(0);
	}
}




static VAR productOfFloat(VAR left, VAR right) {
	switch(right.type) {
		case INT_T:
			return productOfInteger(right, left);
		case FLOAT_T:
		{
			float fresult = left.value.floatValue * right.value.floatValue;
			return anonFloat(fresult);
		}
		case STR_T:
		case ARRAY_T:
			return productOfInteger(anonInteger(left.value.floatValue), right);
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", right.type);
			exit(0);
	}
}



static VAR productOfString(VAR left, VAR right) {
	switch(right.type) {
		case INT_T:
			return productOfInteger(right, left);
		case FLOAT_T:
			return productOfFloat(right, left);
		case STR_T:
			printf("Error. No se puede multiplicar un %s con un %s. El programa no puede continuar.\n", getNameofType(STR_T), getNameofType(STR_T));
			exit(0);
		case ARRAY_T:
			printf("Error. No se puede multiplicar una %s a un %s. El programa no puede continuar.\n", getNameofType(ARRAY_T), getNameofType(STR_T));
			exit(0);
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", right.type);
			exit(0);
	}
}




static VAR divisionOfInteger(VAR left, VAR right) {
	switch(right.type) {
		case INT_T:
		{
			int iresult = left.value.intValue / right.value.intValue;
			return anonInteger(iresult);
		}
		case FLOAT_T:
		{
			float fresult = left.value.intValue / right.value.floatValue;
			return anonFloat(fresult);
		}
		case STR_T:
		{
			printf("Error: se intenta dividir un numero por un texto. El programa no puede continuar\n");
			exit(1);
		}
		case ARRAY_T:
		{
			printf("Error: se intenta dividir un numero por una lista. El programa no puede continuar\n");
			exit(1);
		}
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", right.type);
			exit(0);
	}
}


static VAR divisionOfFloat(VAR left, VAR right) {
	switch(right.type) {
		case INT_T:
		{
			float iresult = left.value.intValue / right.value.intValue;
			return anonFloat(iresult);
		}
		case FLOAT_T:
		{
			float fresult = left.value.intValue / right.value.floatValue;
			return anonFloat(fresult);
		}
		case STR_T:
		{
			printf("Error: se intenta dividir un numero por un texto. El programa no puede continuar\n");
			exit(1);
		}
		case ARRAY_T:
		{
			printf("Error: se intenta dividir un numero por una lista. El programa no puede continuar\n");
			exit(1);
		}
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", right.type);
			exit(0);
	}
}



static VAR divisionOfString(VAR left, VAR right) {
	switch(right.type) {
		case INT_T:
		{
			if(right.value.intValue <= 0){
				printf("Error: se intenta dividir un texto por un numero negativo o cero. El programa no puede continuar\n");
				exit(1);

			}

			int len = strlen(left.value.strValue);
			int chunk = strlen(left.value.strValue) / right.value.intValue;
			if(chunk < 1){
				chunk = 1;
			}
			VAR divided = anonArray(0);
			int i = 0;
			char * str = malloc(chunk + 1);
			while(i < len){
				memcpy(str, left.value.strValue + i, chunk);
				*(str+len) = 0;
				pushArray((Array)(divided.value.arrValue), anonString(str));
				i+=chunk;
			}
			free(str);
			return divided;
		}
		case FLOAT_T:
		
			return divisionOfString(left, anonInteger((int)right.value.floatValue));
		
		case STR_T:
		{
			printf("Error: se intenta dividir un texto por un texto. El programa no puede continuar\n");
			exit(1);
		}
		case ARRAY_T:
		{
			printf("Error: se intenta dividir un texto por una lista. El programa no puede continuar\n");
			exit(1);
		}
		default:
			fprintf(stderr, "Error. Tipo desconocido: %d\n", right.type);
			exit(0);
	}
}
