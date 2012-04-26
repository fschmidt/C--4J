#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H

#include "rationalnumber.h"

struct RationalNumberArray;

enum ErrType {
    INVALID_OBJECT,
    INVALID_INDEX,
    CANNOT_ALLOCATE_MEMORY
};

RationalNumberArray* rnaCreate(const int size = 10);

void rnaDelete(RationalNumberArray* const data );

void rnaResize(RationalNumberArray* data, int size = 10);

int rnaSize(RationalNumberArray const * const data);

int rnaCapacity(RationalNumberArray const * const data);

void rnaAdd(RationalNumberArray * const data, RationalNumber const * const value);

void rnaSet(RationalNumberArray * const data, RationalNumber const *const value, const int position);

RationalNumber* rnaGet(RationalNumberArray *const data, const int position);

void rnaRemove(RationalNumberArray *data, const int firstPosition, const int lastPosition);

ErrType const *rnaError(RationalNumberArray const * const data);

void rnaSetErrorCallback(RationalNumberArray * const data, void (*callbackFunction)(RationalNumberArray*));

#endif // RATIONALNUMBERARRAY_H
