#ifndef VARIABLES_H
#define VARIABLES_H

#include <stdint.h>

#define INT_T 1
#define STR_T 2
#define FLOAT_T 3
#define ARRAY_T 4
#define MAX_VARS 10000

typedef uint8_t type_t;

typedef int VAR_ID;


typedef union{
	int intValue;
	float floatValue;
	char* strValue;
	void* arrValue;
} varValue;

typedef struct{
  	varValue value;
	type_t type;
} VAR;


void mapAName(VAR_ID id, char * name);

VAR assign(VAR_ID id, VAR assigned);

VAR anonVariable(uint64_t value, type_t type);

void freeVariable(VAR* v);

VAR anonFloat(float value);

VAR anonInteger(int value);

VAR anonRandom(void);

VAR anonString(char* value);

VAR anonArray(int n, ...);

void addInArray(VAR_ID id, VAR new_elem);

VAR indexOfArray(VAR array, VAR index);

void assignmentOfArray(VAR array, VAR index, VAR newVar);

VAR_ID createVariable(type_t type, void * value);

VAR getVariable(VAR_ID id);

VAR cloneVariable(VAR var);

int compare(VAR first, VAR second);

int areEquals(VAR first, VAR second);

VAR sum(VAR left, VAR right);

VAR substract(VAR left, VAR right);

VAR product(VAR left, VAR right);

VAR division(VAR left, VAR right);

VAR minus(VAR var);

char* getNameofType(type_t type);


#endif
