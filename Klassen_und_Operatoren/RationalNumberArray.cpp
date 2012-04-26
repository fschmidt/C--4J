#include <stdlib.h>
#include "RationalNumberArray.h"

/*
  Struct representing an Array of Rational Number.
  Use this to call all the fanvy functions for RationalNumber arrays.
  */
class RationalNumberArray {
public:
    /*
      The constructor for RationalNumberArrays
      returns: An empty (size=0) RationalNumberArray of the given capacity.
    */
    RationalNumberArray(const int capacity)
        :m_capacity(capacity), m_size(0)
    {
        m_values = (RationalNumber*) malloc(m_capacity * sizeof(RationalNumber));

        // check whether memory was allocated
        if((m_values) == 0){
            // throw some exception
        }

        return result;
    }

    /*
      destructor
    */
    ~RationalNumberArray(){
        free(m_values);
    }

    /*
      Sets the capacity of the given RationalNumberArray
    */
    void resize(const int newCapacity){

        realloc(m_values, sizeof(RationalNumber) * newCapacity);
        // check whether memory was allocated
        if(m_values == 0){
            // throw some exception
        }

        m_capacity = newCapacity;

        if(m_size > m_capacity){
            m_size = m_capacity;
        }
    }

    /*
      returns: The current size (number of elements) of the given RationalNumberArray
    */
    int size(){
        return m_size;
    }

    /*
      returns: The current capacity of the given RationalNumberArray
    */
    int capacity(){
        return m_capacity;
    }

    /*
      Adds the given RationalNumber at the end of the given RationalNumberArray.
      Increases the given Arrays capacity if needed.
    */
    void add(RationalNumber const& value){
        if(m_size == m_capacity){
            resize(m_capacity*2);
        }

        m_values[m_size].denominator = value.denominator;
        m_values[m_size].nominator = value.nominator;
        m_size++;
    }

    /*
      Sets the element of the given RationalNumberArray at the given position to the given value
    */
    void set(RationalNumber const& value, const int position){
        while(position > m_capacity){
            resize(m_capacity*2);
        }

        if (m_size < position){
            for(int i = m_size; i < position; i++){
                m_values[i].nominator = 0;
                m_values[i].denominator = 1;
            }
            m_size = position+1;
        }

        m_values[position].denominator = value.denominator;
        m_values[position].nominator = value.nominator;
    }

    /*
      returns: the element of the given RationalNumberArray at the given position
    */
    RationalNumber* get(const int position){
        if(position >= m_size) {
            //data->lastError = INVALID_INDEX;
/*            if((data->callbackFunction)!=0){
                data->callbackFunction(data);
            }*/
            return 0;
        }
        return m_values[position];
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



private:
    RationalNumber *m_values;
    int m_size;
    int m_capacity;
    ErrType m_lastError;
    void (*callbackFunction) (RationalNumberArray*);
};
