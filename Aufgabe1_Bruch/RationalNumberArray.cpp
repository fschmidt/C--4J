#include <stdlib.h>
#include "RationalNumberArray.h"

enum ErrType {
    INVALID_OBJECT,
    INVALID_INDEX,
    CANNOT_ALLOCATE_MEMORY
};

struct RationalNumberArray {
    RationalNumber *values;
    int size;
    int capacity;
    ErrType lastError;
    typedef void (*callbackFunction) (RationalNumberArray*);
};

RationalNumberArray* rnaCreate(int size = 10){
    RationalNumberArray* result = (RationalNumberArray*) malloc(sizeof(RationalNumberArray));
    result -> values = (RationalNumber*) malloc(size * sizeof(RationalNumber));
    result -> capacity = size;
    result -> size = 0;
    return result;
}

void rnaDelete(RationalNumberArray *data){
    free(data -> values);
    free(data);
}

void rnaResize(RationalNumberArray *data, int size = 10){
    realloc(data -> values, sizeof(RationalNumber) * size);
    data->capacity = size;
}

int rnaSize(RationalNumberArray *data){
    return data -> size;
}

int rnaCapacity(RationalNumberArray *data){
    return data -> capacity;
}

void rnaAdd(RationalNumberArray *data, RationalNumber *value){
    if(data->size >= data->capacity){
        rnaResize(data);
    }
    data->values[(data -> size)++] = &value;
}

void rnaSet(RationalNumberArray *data, RationalNumber *value, int position){
    if(data -> capacity < position){
        rnaResize(data, position);
    }

    if (data->size < position){
        for(int i = data->size; i < position; i++){
            data->values[i].nominator = 0;
            data->values[i].denominator = 1;
        }
        data->size = position+1;
    }

    data->values[position] = &value;
}

RationalNumber rnaGet(RationalNumberArray *data, int position){
    if(position >= size) {
        data->lastError = INVALID_INDEX;
        //ask the prof =)
        return null;
    }
    return data->values[position];
}

void rnaRemove(RationalNumberArray *data, int firstPosition, int lastPosition){
    if(firstPosition < 0 || lastPosition > data->size){

    }
}

ErrType* rnaError();

void rnaSetErrorCallback(void (*callbackFunction)(RationalNumberArray*));
