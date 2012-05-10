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
    RationalNumberArray(const int capacity = 10, void (* const callbackFunction)() = 0)
        :m_size(0), m_capacity(capacity), m_callbackFunction(callbackFunction)
    {
        m_values = new (nothrow) RationalNumber[capacity];

        if(m_values == 0) {
            callback();
        }
    }

    ~RationalNumberArray() {
        delete[] m_values;
    }

    void resize(const int newCapacity);

    int size();

    int capacity();

    void add(RationalNumber const value);

    void set(RationalNumber const &value, const int position);

    RationalNumber get(const int position);

    void remove(const int firstPosition, const int lastPosition);

    //    ErrType error(RationalNumberArray const * const data);

    //    void setErrorCallback(RationalNumberArray * const data, void (*callbackFunction)(RationalNumberArray*));

private:
    RationalNumber *m_values;
    int m_size;
    int m_capacity;
    ErrType m_lastError;
    void (*m_callbackFunction)();

    void callback();
};
#endif // RATIONALNUMBERARRAY_H
