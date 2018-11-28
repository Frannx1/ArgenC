#ifndef ARRAY_H
#define ARRAY_H

#include "variables.h"

typedef struct ArrayCDT {
	VAR * values;
	int size;
	int capacity;
	int iterator;
} ArrayCDT;


typedef ArrayCDT *Array;

Array createArray();

void pushArray(Array array, VAR value);

Array substractArray(Array source, Array other);

Array removeArray(Array source, VAR value);

int containsArray(Array array, VAR value);

VAR next(VAR array);

int hasNext(VAR array);

void resetIterator(VAR array);

Array cloneArray(Array array);

void concatArray(Array array, Array other);

VAR accessToArray(Array array, int index);

void editArray(Array array, int index, VAR value);

void printArray(Array array);

void freeArray(Array array);


#endif

