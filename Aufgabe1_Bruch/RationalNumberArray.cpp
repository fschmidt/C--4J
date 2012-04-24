#include <stdlib.h>
#include "RationalNumberArray.h"

/*
  Struct representing an Array of Rational Number.
  Use this to call all the fanvy functions for RationalNumber arrays.
  */
struct RationalNumberArray {
    RationalNumber *values;
    int size;
    int capacity;
    ErrType lastError;
    void (*callbackFunction) (RationalNumberArray*);
};

/*
  The constructor for RationalNumberArrays
  returns: An empty (size=0) RationalNumberArray of the given capacity.
*/
RationalNumberArray* rnaCreate(const int size){
    RationalNumberArray* result = (RationalNumberArray*) malloc(sizeof(RationalNumberArray));

    result -> values = (RationalNumber*) malloc(size * sizeof(RationalNumber));

    // check whether memory was allocated
    if((result -> values) == 0){
        result -> lastError = CANNOT_ALLOCATE_MEMORY;
    }

    result -> capacity = size;
    result -> size = 0;

    result->callbackFunction = 0;
    return result;
}

/*
  Deletes a RationalNumberArray freeing the memory it used
*/
void rnaDelete(RationalNumberArray *data){
    free(data -> values);
    free(data);
}

/*
  Sets the capacity of the given RationalNumberArray
*/
void rnaResize(RationalNumberArray *data, const int size){
    realloc(data -> values, sizeof(RationalNumber) * size);
    // check whether memory was allocated
    if((data->values) == 0){
        data -> lastError = CANNOT_ALLOCATE_MEMORY;
        if((data->callbackFunction)!=0){
            data->callbackFunction(data);
        }
    }
    data->capacity = size;
    if(data->size > data->capacity){
        data->size = data->capacity;
    }
}

/*
  returns: The current size (number of elements) of the given RationalNumberArray
*/
int rnaSize(RationalNumberArray const * const data){
    return data -> size;
}

/*
  returns: The current capacity of the given RationalNumberArray
*/
int rnaCapacity(const RationalNumberArray * const data){
    return data -> capacity;
}

/*
  Adds the given RationalNumber at the end of the given RationalNumberArray.
  Increases the given Arrays capacity if needed.
*/
void rnaAdd(RationalNumberArray * const data, RationalNumber const * const value){
    if(data->size == data->capacity){
        rnaResize(data, data->capacity*2);
    }
    data->values[data -> size].denominator = value->denominator;
    data->values[data -> size].nominator = value->nominator;
    data->size++;
}

/*
  Sets the element of the given RationalNumberArray at the given position to the given value
*/
void rnaSet(RationalNumberArray *const data, const RationalNumber *const value, const int position){
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

/*
  returns: the element of the given RationalNumberArray at the given position
*/
RationalNumber* rnaGet(RationalNumberArray * const data, const int position){
    if(position >= data -> size) {
        data->lastError = INVALID_INDEX;
        if((data->callbackFunction)!=0){
            data->callbackFunction(data);
        }
        return 0;
    }
    return &(data->values[position]);
}

/*
  Removes the elements from firstPosition to lastPosition in the given RationalNumberArray and removes the gap.
*/
void rnaRemove(RationalNumberArray *data, const int firstPosition, const int lastPosition){
    int startIndex = firstPosition > 0 ? firstPosition : 0;
    int endIndex = lastPosition + 1;
    int oldSize = data->size;
    data->size = startIndex;
    while(endIndex < oldSize){
        rnaAdd(data, &(data->values[endIndex++]));
    }
}

/*
  returns: the errorType thrown by the last function call if an error occured during call.
*/
ErrType const * rnaError(const RationalNumberArray *const data){
    return &(data->lastError);
}

/*
  Sets the callback function called when an error is thrown by rna methods other than this.
  */
void rnaSetErrorCallback(RationalNumberArray * const data, void (*callbackFunction)(RationalNumberArray*)){
    data->callbackFunction = callbackFunction;
}
