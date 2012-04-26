#include "rationalnumber.h"

RationalNumber rnNormalize(RationalNumber n);

int euclid(int a, int b);

/*
  Check whether a given RationalNumber is valid.
  returns: True if the given RationalNumber is valid, False otherwise
  */
bool rnIsValid(RationalNumber n){
    return n.denominator != 0;
}

/*
  Check whether a given RationalNumber is NaN (Not a Number).
  returns: True if the given RationalNumber is NaN, False otherwise
  */
bool rnIsNaN(RationalNumber n){
    return n.denominator==0;
}

/*
  Check whether two given RationalNumbers are equal.
  RationalNumbers are equal when all requirements for arithmetic equalty of RationalNumbers are met.
  returns: True if the given RationalNumbers are equal, False otherwise
  */
bool rnEqual(RationalNumber n, RationalNumber m){
    RationalNumber a = rnNormalize(n);
    RationalNumber b = rnNormalize(m);
    return (a.denominator == b.denominator && a.nominator == b.nominator);
}

/*
  Check whether the arithmetic value of the given RationalNumber n is less
  than the arithmetic value of the given RationalNumber m.
  returns: True if n < m, False otherwise
  */
bool rnLessThan(RationalNumber n, RationalNumber m){
    if(rnCompareTo(n, m) == -1){
        return true;
    }
    return false;
}

/*
  Compares two RationalNumbers
  returns:
 -1 if n < m
  0 if n = m
  1 if n > m
  */
int rnCompareTo(RationalNumber n, RationalNumber m){
    if (n.nominator / n.denominator > m.nominator / m.denominator){
        return 1;
    }else if (n.nominator / n.denominator < m.nominator / m.denominator){
        return -1;
    } else if (n.nominator % n.denominator > m.nominator % m.denominator){
        return 1;
    }else if (n.nominator % n.denominator < m.nominator % m.denominator){
        return -1;
    } else {
        return 0;
    }
}

/*
  Basic arithmetic operation Addition for two given RationalNumbers.
  returns: the result of n + m as a Rational Number
  */
RationalNumber rnAdd(RationalNumber n, RationalNumber m){
    RationalNumber result;
    result.nominator = n.nominator * m.denominator + n.denominator * m.nominator;
    result.denominator = n.denominator * m.denominator;
    return rnNormalize(result);
}

/*
  Basic arithmetic operation Subtraction for two given RationalNumbers.
  returns: the result of n - m as a Rational Number
  */
RationalNumber rnSub(RationalNumber n, RationalNumber m){
    RationalNumber result;
    result.nominator = n.nominator * m.denominator - n.denominator * m.nominator;
    result.denominator = n.denominator * m.denominator;
    return rnNormalize(result);
}

/*
  Basic arithmetic operation Multiplication for two given RationalNumbers.
  returns: the result of n * m as a Rational Number
  */
RationalNumber rnMul(RationalNumber n, RationalNumber m){
    RationalNumber result;
    result.nominator = n.nominator*m.nominator;
    result.denominator = n.denominator*m.denominator;
    return result;
}

/*
  Basic arithmetic operation Division  for two given RationalNumbers.
  returns: the result of n / m as a Rational Number
  */
RationalNumber rnDiv(RationalNumber n, RationalNumber m) {
    RationalNumber reciprocus;
    reciprocus.nominator = m.denominator;
    reciprocus.denominator = m.nominator;
    return rnMul(n, reciprocus);
}

/*
  Normalizes a RationalNumber
  returns: The normalized RationalNumber
  */
RationalNumber rnNormalize(RationalNumber n){

    int i = 0;

    i = euclid(n.nominator, n.denominator);
    if((n.nominator % i > 0) || (n.denominator % i > 0)){
        return n;
    }

    n.nominator = n.nominator/i;
    n.denominator = n.denominator/i;

    return n;
}

int euclid(int a, int b){
    if (b == 0) {
        return a;
    } else {
        return euclid(b, a % b);
    }
}
