#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
    int* data;
    int size;
    int capacity;
}vector_t;

vector_t* makeVector(int initCapacity){
    vector_t* vector = (vector_t*)malloc(sizeof(vector_t));
    if ( vector == NULL ){
        return NULL;
    }
    // Allocate memory for our data array.
    vector->data = (int*)malloc(sizeof(int) * initCapacity);
    vector->size = 0;
    vector->capacity = initCapacity;
    return vector;
}

void freeVector(vector_t* vector){
    if(vector == NULL){
        return;
    }
    //First delete data array, then delete vector.
    if(vector->data != NULL){
        free(vector->data);
    }
    free(vector);
}

int main() {
    // Constructed a vector on the heap with the help
    // of makeVector
    vector_t* vector = makeVector(2);
    return 0;
}
