#ifndef RATIONALNUMBERARRAY_H
#define RATIONALNUMBERARRAY_H

#include "rationalnumber.h"

namespace rnum {

class RationalNumberArray {

public:
    enum ErrType {
        INVALID_OBJECT,
        INVALID_INDEX,
        NEGATIVE_CAPAZITY,
        CANNOT_ALLOCATE_MEMORY
    };

    /*
      The constructor for RationalNumberArrays
      returns: An empty (size=0) RationalNumberArray of the given capacity.
    */
    RationalNumberArray(const int capacity = 10, void (* const callbackFunction)(const RationalNumberArray&) = 0);

    RationalNumberArray(RationalNumberArray const &another);

    ~RationalNumberArray();

    void resize(const int newCapacity);

    int size();

    int capacity();

    void add(RationalNumber const value);

    void set(RationalNumber const &value, const int position);

    RationalNumber& operator[](int i);

    const RationalNumber& operator[](int i) const;

    void remove(const int firstPosition, const int lastPosition);

    ErrType error() const;

    ErrType error();

    void setErrorCallback(void (*callbackFunction)(const RationalNumberArray&));

private:
    RationalNumber *m_values;
    int m_size;
    int m_capacity;
    ErrType m_lastError;

    void (*m_callbackFunction)( const RationalNumberArray&);

    bool operator==(const RationalNumberArray& another);

    bool operator!=(const RationalNumberArray& another);

    bool operator>=(const RationalNumberArray& another);

    bool operator<=(const RationalNumberArray& another);

    bool operator>(const RationalNumberArray& another);

    bool operator<(const RationalNumberArray& another);
};

}
#endif // RATIONALNUMBERARRAY_H
