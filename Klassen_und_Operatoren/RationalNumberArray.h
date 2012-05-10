#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H

#include "rationalnumber.h"

class RationalNumberArray {

public:
    enum ErrType {
        INVALID_OBJECT,
        INVALID_INDEX,
        CANNOT_ALLOCATE_MEMORY
    };

    /*
      The constructor for RationalNumberArrays
      returns: An empty (size=0) RationalNumberArray of the given capacity.
    */
    RationalNumberArray(const int capacity = 10, void (* const callbackFunction)(RationalNumberArray*) = 0);

    ~RationalNumberArray();

    void resize(const int newCapacity);

    int size();

    int capacity();

    void add(RationalNumber const value);

    void set(RationalNumber const &value, const int position);

    RationalNumber get(const int position);

    void remove(const int firstPosition, const int lastPosition);

    ErrType error();

    void setErrorCallback(void (*callbackFunction)(RationalNumberArray*));

private:
    RationalNumber *m_values;
    int m_size;
    int m_capacity;
    ErrType m_lastError;

    void (*m_callbackFunction)(RationalNumberArray*);
};
#endif // RATIONALNUMBERARRAY_H
