#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

/*
  Struct representing a Rational Number.
  */
struct RationalNumber {
    int nominator;
    int denominator;
};

/*
  Check whether a given RationalNumber is valid.
  returns: True if the given RationalNumber is valid, False otherwise
  */
bool rnIsValid(RationalNumber n);

/*
  Check whether a given RationalNumber is NaN (Not a Number).
  returns: True if the given RationalNumber is NaN, False otherwise
  */
bool rnIsNaN(RationalNumber n);

/*
  Check whether two given RationalNumbers are equal.
  RationalNumbers are equal when all requirements for arithmetic equalty of RationalNumbers are met.
  returns: True if the given RationalNumbers are equal, False otherwise
  */
bool rnEqual(RationalNumber n, RationalNumber m);

/*
  Check whether the arithmetic value of the given RationalNumber n is less
  than the arithmetic value of the given RationalNumber m.
  returns: True if n < m, False otherwise
  */
bool rnLessThan(RationalNumber n, RationalNumber m);

/*
  Compares two RationalNumbers
  returns:
 -1 if n < m
  0 if n = m
  1 if n > m
  */
int rnCompareTo(RationalNumber n, RationalNumber m);

/*
  Basic arithmetic operation Addition for two given RationalNumbers.
  returns: the result of n + m as a Rational Number
  */
RationalNumber rnAdd(RationalNumber n, RationalNumber m);

/*
  Basic arithmetic operation Subtraction for two given RationalNumbers.
  returns: the result of n - m as a Rational Number
  */
RationalNumber rnSub(RationalNumber n, RationalNumber m);

/*
  Basic arithmetic operation Multiplication for two given RationalNumbers.
  returns: the result of n * m as a Rational Number
  */
RationalNumber rnMul(RationalNumber n, RationalNumber m);

/*
  Basic arithmetic operation Division  for two given RationalNumbers.
  returns: the result of n / m as a Rational Number
  */
RationalNumber rnDiv(RationalNumber n, RationalNumber m);

#endif // RATIONALNUMBER_H
