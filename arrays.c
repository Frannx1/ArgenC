#include <stdlib.h>
#include <stdio.h>

#include "arrays.h"
#include "utils.h"

static void increaseCapacity(Array arr);

#define INITIAL_SIZE 15


Array new_array(){
	Array arr = malloc(sizeof(*arr));
	arr->values = malloc(INITIAL_SIZE * sizeof(VAR));
	arr->size = 0;
	arr->capacity = INITIAL_SIZE;
	arr->iterator = 0;
	return arr;
}

/* Deep copy del arreglo */
Array array_clone(Array other){
	if(other == NULL){
		return NULL;
	}
	Array clone = new_array();
	
	int i;
	for(i=0 ; i < other->size ; i++){
		array_push(clone, other->values[i]);
	}
	clone->iterator = other->iterator;

	return clone;
}


/*Devuelve el valor de la posición index*/
VAR array_access(Array arr, int index){
	if(index >= arr->size){
		printf("index is %d", index);
		printf("Array index out of bounds\n");
		exit(1);
	}
	return arr->values[index];
}

int hasNext(VAR arr){
	Array array = arr.value.arrValue;
	return array != NULL && (array->iterator < array->size);
}

VAR next(VAR arr){
	Array array = arr.value.arrValue;
	VAR aux = array_access(array, array->iterator);
	array->iterator++;
	return aux;
}

void reset_iterator(VAR arr){
	Array array = arr.value.arrValue;
	array->iterator = 0;
}

/* Actualiza el valor de la posicion index */
void array_modify(Array arr, int index, VAR value){
	if(index >= arr->size){
		printf("index is %d", index);
		printf("Index out of bounds\n");
		exit(1);
	}
	arr->values[index] = var_clone(value);
}

/* Agrega al final del arreglo */
void array_push(Array arr, VAR value){
	if(arr == NULL){ //TODO: Error
		return;
	}

	if(arr->size == arr->capacity){
		increaseCapacity(arr);
	}

	arr->values[arr->size] = var_clone(value);
	arr->size++;
}	

/* Devuelve un nuevo arreglo con los elementos de source que no están en other */
Array array_substract(Array source, Array other){
	Array arr = new_array();
	int i;

	for (i = 0; i < source->size; i++)
		if (!array_contains(other, source->values[i]))
			array_push(arr, source->values[i]);

	return arr;
}

/* Quita un elemento de un arreglo */
Array array_remove(Array source, VAR value){
	Array arr = new_array();
	int i;

	for (i = 0; i < source->size; i++)
		if (!is_equals(source->values[i], value))
			array_push(arr, source->values[i]);

	return arr;
}

/* Devulve 1 si el arreglo contiene a value, 0 sino */
int array_contains(Array arr, VAR value){
	int i;
	for(i = 0; i < arr->size; i++)
		if (is_equals(arr->values[i], value))
			return 1;
	return 0;
}

/* Append del arreglo other al arreglo arr */
void array_cat(Array arr, Array other){
	if(arr == NULL || other == NULL){
		return;
	}
	
	int i;
	for(i=0 ; i < other->size ; i++){
		array_push(arr, other->values[i]);
	}
}


void array_print(Array arr){
	if(arr == NULL){
		printf("ERROR");
		exit(0);
	}
	int i;
	printf("[");
	for(i = 0; i < arr->size ; i++){
		print_var(arr->values[i],0);
		if(i < arr->size -1) printf(", ");
	}	
	printf("]");
}


void array_free(Array arr){
	int i;
	for(i=0 ; i < arr->size ; i++){
		free_var_resources(&arr->values[i]);
	}
	free(arr->values);
}

static void increaseCapacity(Array arr){

	VAR * new_values = realloc(arr->values, 2*arr->capacity*sizeof(VAR));
	if(new_values == NULL){
		printf("No memory\n");
		exit(0);
	}

	arr->values = new_values;
	arr->capacity += arr->capacity;

}
