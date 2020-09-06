#include<stdio.h>

#include "value.h"
#include "memory.h"

void initValueArray(ValueArray* array) {
	array->values = NULL;
	array->count = 0;
	array->capacity = 0;
}

void freeValueArray(ValueArray* array) {
	FREE_ARRAY(Value, array->values, array->count);
	initValueArray(array);
}

void writeValueArray(ValueArray* array, Value value) {
	if (array->count + 1 > array->capacity) {
		int oldCapacity = array->capacity;
		array->capacity = GROW_CAPACITY(oldCapacity);
		array->values = GROW_ARRAY(Value, array->values, oldCapacity, array->capacity);
	}
	array->values[array->count++] = value;
}

void printValue(Value value) {
	printf("%g", value);
}