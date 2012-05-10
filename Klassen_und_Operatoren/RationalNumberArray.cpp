#include <stdlib.h>
#include "rationalnumberarray.h"


void defaultCallbackFunction(RationalNumberArray* rna);

/*
  The constructor for RationalNumberArrays
  returns: An empty (size=0) RationalNumberArray of the given capacity.
*/
RationalNumberArray::RationalNumberArray(const int capacity, void (* const callbackFunction)(RationalNumberArray*))
    :m_size(0), m_capacity(capacity), m_callbackFunction(callbackFunction)
{
    if(m_callbackFunction == 0) {
        // set defaultErrorFunction
        m_callbackFunction = &defaultCallbackFunction;
    }

    m_values = new (nothrow) RationalNumber[capacity];

    if(m_values == 0) {
        m_callbackFunction(this);
    }
}

RationalNumberArray::~RationalNumberArray() {
    delete[] m_values;
}

/*
      Sets the capacity of the given RationalNumberArray
    */
void RationalNumberArray::resize(const int newCapacity){

    RationalNumber *temp = m_values;
    realloc(m_values, sizeof(RationalNumber) * newCapacity);
    // check whether memory was allocated
    if(m_values == 0){
        // if reallocation fails free the old space to avoid mem leak
        free(temp);
        m_callbackFunction(this);
    }

    m_capacity = newCapacity;

    if(m_size > m_capacity){
        m_size = m_capacity;
    }
}

/*
      returns: The current size (number of elements) of the given RationalNumberArray
    */
int RationalNumberArray::size(){
    return m_size;
}

/*
      returns: The current capacity of the given RationalNumberArray
    */
int RationalNumberArray::capacity(){
    return m_capacity;
}

/*
      Adds the given RationalNumber at the end of the given RationalNumberArray.
      Increases the given Arrays capacity if needed.
    */
void RationalNumberArray::add(RationalNumber const value){
    if(m_size == m_capacity){
        resize(m_capacity*2);
    }

    m_values[m_size] = value;
    m_size++;
}

/*
      Sets the element of the given RationalNumberArray at the given position to the given value
    */
void RationalNumberArray::set(RationalNumber const &value, const int position){
    while(position > m_capacity){
        resize(m_capacity*2);
    }

    if (m_size < position){
        for(int i = m_size; i < position; i++){
            m_values[i] = RationalNumber();
        }
        m_size = position + 1;
    }

    m_values[position] = value;
}

/*
  returns: the element of the given RationalNumberArray at the given position
    */
RationalNumber RationalNumberArray::get(const int position){
    if(position >= m_size) {
        //data->lastError = INVALID_INDEX;
        m_callbackFunction(this);
        return 0;
    }
    return m_values[position];
}

/*
      Removes the elements from firstPosition to lastPosition in the given RationalNumberArray and removes the gap.
    */
void RationalNumberArray::remove(const int firstPosition, const int lastPosition){
    int startIndex = firstPosition > 0 ? firstPosition : 0;
    int endIndex = lastPosition + 1;
    int oldSize = m_size;
    m_size = startIndex;
    while(endIndex < oldSize){
        add(m_values[endIndex++]);
    }
}

/*
      returns: the errorType thrown by the last function call if an error occured during call.
    */
RationalNumberArray::ErrType RationalNumberArray::error(){
    return m_lastError;
}

/*
      Sets the callback function called when an error is thrown by rna methods other than this.
      */
void RationalNumberArray::setErrorCallback(void (*callbackFunction)(RationalNumberArray*)){
    m_callbackFunction = callbackFunction;
}

void defaultCallbackFunction(RationalNumberArray * rna){
    cout << "ErrorCode: "<< rna->error();
}


