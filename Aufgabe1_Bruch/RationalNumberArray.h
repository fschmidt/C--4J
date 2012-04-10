#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H

#include "rationalnumber.h"

struct RationalNumberArray;

enum ErrType;

RationalNumberArray rnaCreate(int size = 10);

void rnaDelete(RationalNumberArray *data);

void rnaResize(RationalNumberArray *data, int size = 10);

int rnaSize(RationalNumberArray *data);

int rnaCapacity(RationalNumberArray *data);

void rnaAdd(RationalNumberArray *data, RationalNumber *value);

void rnaSet(RationalNumberArray *data, RationalNumber *value, int position);

RationalNumber rnaGet(RationalNumberArray *data, int position);

void rnaRemove(RationalNumberArray *data, int firstPosition, int lastPosition);

ErrType* rnaError();

void rnaSetErrorCallback(void (*callbackFunction)(RationalNumberArray*));

#endif // RATIONALNUMBERARRAY_H


