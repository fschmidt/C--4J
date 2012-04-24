#include <stdlib.h>
#include "RationalNumberArray.h"

struct RationalNumberArray {
    RationalNumber *values;
    int size;
    int capacity;
    ErrType lastError;
    void (*callbackFunction) (RationalNumberArray*);
};

RationalNumberArray* rnaCreate(int size){
    RationalNumberArray* result = (RationalNumberArray*) malloc(sizeof(RationalNumberArray));

    // check whether memory was allocated
    if(!result){
        result -> lastError = CANNOT_ALLOCATE_MEMORY;
    }

    result -> values = (RationalNumber*) malloc(size * sizeof(RationalNumber));

    // check whether memory was allocated
    if(!(result -> values)){
        result -> lastError = CANNOT_ALLOCATE_MEMORY;
    }

    result -> capacity = size;
    result -> size = 0;

    result->callbackFunction = 0;
    return result;
}

void rnaDelete(RationalNumberArray *data){
    free(data -> values);
    free(data);
}

void rnaResize(RationalNumberArray *data, int size){
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
    if(data->size == data->capacity){
        rnaResize(data, data->capacity*2);
    }
    data->values[data -> size].denominator = value->denominator;
    data->values[data -> size].nominator = value->nominator;
    data->size++;
}

void rnaSet(RationalNumberArray *data, RationalNumber *value, int position){
    while(position > data->capacity){
        rnaResize(data, data->capacity*2);
    }

    if (data->size < position){
        for(int i = data->size; i < position; i++){
            data->values[i].nominator = 0;
            data->values[i].denominator = 1;
        }
        data->size = position+1;
    }

    data->values[position].denominator = value->denominator;
    data->values[position].nominator = value->nominator;
}

RationalNumber* rnaGet(RationalNumberArray *data, int position){
    if(position >= data -> size) {
        data->lastError = INVALID_INDEX;
        if((data->callbackFunction)!=0){
            data->callbackFunction(data);
        }
        return 0;
    }
    return &(data->values[position]);
}

void rnaRemove(RationalNumberArray *data, int firstPosition, int lastPosition){
    if(firstPosition < 0 || lastPosition >= data->size){
        data->lastError = INVALID_INDEX;
        if(data->callbackFunction){
            data->callbackFunction(data);
        }
    } else if(lastPosition < data->size-1){
        int diff = lastPosition - firstPosition;
        for(int i = lastPosition; i < data->size; i++){
            data->values[i-diff].denominator = data->values[i].denominator;
            data->values[i-diff].nominator = data->values[i].nominator;
        }
         data->size = data->size - lastPosition;
    } else {
        data->size = firstPosition;
    }
}

ErrType* rnaError(RationalNumberArray *data){
    return &(data->lastError);
}

void rnaSetErrorCallback(RationalNumberArray *data, void (*callbackFunction)(RationalNumberArray*)){
    data->callbackFunction = callbackFunction;
}

