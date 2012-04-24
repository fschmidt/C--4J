#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H

#include "rationalnumber.h"

struct RationalNumberArray;

enum ErrType {
    NO_ERROR,
    INVALID_OBJECT,
    INVALID_INDEX,
    CANNOT_ALLOCATE_MEMORY
};

RationalNumberArray* rnaCreate(int size = 10);

void rnaDelete(RationalNumberArray *data);

void rnaResize(RationalNumberArray *data, int size = 10);

int rnaSize(RationalNumberArray *data);

int rnaCapacity(RationalNumberArray *data);

void rnaAdd(RationalNumberArray *data, RationalNumber *value);

void rnaSet(RationalNumberArray *data, RationalNumber *value, int position);

RationalNumber* rnaGet(RationalNumberArray *data, int position);

void rnaRemove(RationalNumberArray *data, int firstPosition, int lastPosition);

ErrType* rnaError(RationalNumberArray *data);

void rnaSetErrorCallback(RationalNumberArray *data, void (*callbackFunction)(RationalNumberArray*));

#endif // RATIONALNUMBERARRAY_H
