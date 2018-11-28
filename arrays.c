#include <stdlib.h>
#include <stdio.h>

#include "arrays.h"
#include "utils.h"

#define INITIAL_SIZE 15


static void increaseCapacity(Array array);


Array createArray() {
	Array array = malloc(sizeof(*array));
	array->values = malloc(INITIAL_SIZE * sizeof(VAR));
	array->size = 0;
	array->capacity = INITIAL_SIZE;
	array->iterator = 0;
	return array;
}

Array cloneArray(Array other) {
	if(other == NULL)
		return other;
	Array clone = createArray();
	
	for(int i=0 ; i < other->size ; i++)
		pushArray(clone, other->values[i]);

	clone->iterator = other->iterator;

	return clone;
}

VAR accessToArray(Array array, int index) {
	if(index >= array->size) {
		printf("index is %d", index);
		printf("Array index out of bounds\n");
		exit(1);
	}
	return array->values[index];
}

int hasNext(VAR array) {
	Array other = array.value.arrValue;
	return other != NULL && (other->iterator < other->size);
}

VAR next(VAR array) {
	Array other = array.value.arrValue;
	VAR aux = accessToArray(other, other->iterator);
	other->iterator++;
	return aux;
}

void resetIterator(VAR array) {
	Array other = array.value.arrValue;
	other->iterator = 0;
}

void editArray(Array array, int index, VAR value) {
	if(index >= array->size) {
		printf("index is %d", index);
		printf("Index out of bounds\n");
		exit(1);
	}
	array->values[index] = cloneVariable(value);
}

void pushArray(Array array, VAR value) {
	if(array == NULL)
		return;

	if(array->size == array->capacity) {
		increaseCapacity(array);
	}

	array->values[array->size] = cloneVariable(value);
	array->size++;
}	

Array substractArray(Array source, Array other) {
	Array arr = createArray();
	int i;

	for (i = 0; i < source->size; i++)
		if (!containsArray(other, source->values[i]))
			pushArray(arr, source->values[i]);

	return arr;
}

Array removeArray(Array source, VAR value) {
	Array arr = createArray();
	for (int i = 0; i < source->size; i++)
		if (!areEquals(source->values[i], value))
			pushArray(arr, source->values[i]);

	return arr;
}

int containsArray(Array array, VAR value) {
	for(int i = 0; i < array->size; i++)
		if (areEquals(array->values[i], value))
			return 1;
	return 0;
}

void concatArray(Array array, Array other) {
	if(array == NULL || other == NULL)
		return;
	for(int i = 0 ; i < other->size ; i++)
		pushArray(array, other->values[i]);
}


void printArray(Array array) {
	if(array == NULL)
		exit(0);
	printf("[");
	for(int i = 0; i < array->size ; i++) {
		printVariable(array->values[i],0);
		if(i < array->size -1) printf("; ");
	}	
	printf("]");
}


void freeArray(Array array) {
	for(int i = 0 ; i < array->size ; i++)
		freeVariable(&array->values[i]);
	free(array->values);
}

static void increaseCapacity(Array array){

	VAR * newValues = realloc(array->values, 2*array->capacity*sizeof(VAR));
	if(newValues == NULL) {
		printf("out of memory\n");
		exit(0);
	}

	array->values = newValues;
	array->capacity += array->capacity;

}
