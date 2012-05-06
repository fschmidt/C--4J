#include "rationalnumber.h"

RationalNumber rnNormalize(RationalNumber n);

int euclid(int a, int b);

/*
  Check whether this RationalNumber is valid.
  returns: True if this RationalNumber is valid, False otherwise
  */
bool RationalNumber::isValid() const{
    return m_dem_m_denominator != 0;
}

/*
  Check whether this RationalNumber is NaN (Not a Number).
  returns: True if this RationalNumber is NaN, False otherwise
  */
bool RationalNumber::isNaN(){
    return m_nominator==0;
}

/*
  Check whether this RationalNumber is equal to another RationalNumber.
  RationalNumbers are equal when all requirements for arithmetic equalty of RationalNumbers are met.
  returns: True if the given RationalNumbers are equal, False otherwise
  */
bool RationalNumber::equal(RationalNumber another) const{
    RationalNumber a = rnNormalize(this);
    RationalNumber b = rnNormalize(another);
    return (a.m_nominator == b.m_nominator && a.m_denominator == b.m_denominator);
}

/*
  Check whether the arithmetic value this RationalNumber is less
  than the arithmetic value of another RationalNumber.
  returns: True if this < another, False otherwise
  */
bool RationalNumber::lessThan(RationalNumber another) const{
    if(this.compareTo(another) == -1){
        return true;
    }
    return false;
}

/*
  Compares two RationalNumbers
  returns:
 -1 if this < another
  0 if this = another
  1 if this > another
  */
int RationalNumber::compareTo(RationalNumber another) const{
    if (m_denominator / m_nominator > another.m_denominator / another.m_nominator){
        return 1;
    }else if (m_denominator / m_nominator < another.m_denominator / another.m_nominator){
        return -1;
    } else if (m_denominator % m_nominator > another.m_denominator % another.m_nominator){
        return 1;
    }else if (m_denominator % m_nominator < another.m_denominator % another.m_nominator){
        return -1;
    } else {
        return 0;
    }
}

/*
  Basic arithmetic operation Addition for two RationalNumbers.
  returns: the result of this + another as a Rational Number
  */
RationalNumber RationalNumber::add(RationalNumber another) const{
RationalNumber result = new RationalNumber();
    result.m_denominator = m_denominator * another.m_nominator + m_nominator * another.m_denominator;
    result.m_nominator = m_nominator * another.m_nominator;
    return rnNormalize(result);
}

/*
  Basic arithmetic operation Subtraction for two RationalNumbers.
  returns: the result of this - another as a Rational Number
  */
RationalNumber RationalNumber::sub(RationalNumber another) const{
RationalNumber result = new RationalNumber();
    result.m_denominator = m_denominator * another.m_nominator - m_nominator * another.m_denominator;
    result.m_nominator = m_nominator * another.m_nominator;
    return rnNormalize(result);
}

/*
  Basic arithmetic operation Multiplication for two RationalNumbers.
  returns: the result of this * another as a Rational Number
  */
RationalNumber RationalNumber::mul(RationalNumber another) const{
    RationalNumber result = new RationalNumber();
    result.m_denominator = m_denominator * another.m_denominator;
    result.m_nominator = m_nominator * another.m_nominator;
    return result;
}

/*
  Basic arithmetic operation Division  for two RationalNumbers.
  returns: the result of this / another as a Rational Number
  */
RationalNumber RationalNumber::div(RationalNumber another) const{
    RationalNumber reciprocus = new RationalNumber();
    reciprocus.m_denominator = another.m_nominator;
    reciprocus.m_nominator = another.m_denominator;
    return mul(reciprocus);
}

/*
  Normalizes a RationalNumber
  returns: The normalized RationalNumber
  */
RationalNumber rnNormalize(RationalNumber n){

    int i = 0;

    i = euclid(n.m_denominator, n.m_nominator);
    if((n.m_denominator % i > 0) || (n.m_nominator % i > 0)){
        return n;
    }

    n.m_denominator = n.m_denominator/i;
    n.m_nominator = n.m_nominator/i;

    return n;
}

int euclid(int a, int b){
    if (b == 0) {
        return a;
    } else {
        return euclid(b, a % b);
    }
}
