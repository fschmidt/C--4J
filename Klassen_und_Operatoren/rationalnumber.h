#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H


/*
  Struct representing a Rational Number.
  */
class RationalNumber {
public:
    RationalNumber(nominator = 0, denominator = 1);

    /*
      Check whether this RationalNumber is valid.
      returns: True if this RationalNumber is valid, False otherwise
      */
    bool isValid() const;

    /*
      Check whether this RationalNumber is NaN (Not a Number).
      returns: True if this RationalNumber is NaN, False otherwise
      */
    bool isNaN();

    /*
      Check whether this RationalNumber is equal to another RationalNumber.
      RationalNumbers are equal when all requirements for arithmetic equalty of RationalNumbers are met.
      returns: True if the given RationalNumbers are equal, False otherwise
      */
    bool equal(RationalNumber another) const;

    /*
      Check whether the arithmetic value this RationalNumber is less
      than the arithmetic value of another RationalNumber.
      returns: True if this < another, False otherwise
      */
    bool lessThan(RationalNumber another) const;

    /*
      Compares two RationalNumbers
      returns:
     -1 if this < another
      0 if this = another
      1 if this > another
      */
    int compareTo(RationalNumber another) const;

    /*
      Basic arithmetic operation Addition for two RationalNumbers.
      returns: the result of this + another as a Rational Number
      */
    RationalNumber add(RationalNumber another) const;

    /*
      Basic arithmetic operation Subtraction for two RationalNumbers.
      returns: the result of this - another as a Rational Number
      */
    RationalNumber sub(RationalNumber another) const;

    /*
      Basic arithmetic operation Multiplication for two RationalNumbers.
      returns: the result of this * another as a Rational Number
      */
    RationalNumber mul(RationalNumber another) const;

    /*
      Basic arithmetic operation Division  for two RationalNumbers.
      returns: the result of this / another as a Rational Number
      */
    RationalNumber div(RationalNumber another) const;

private:
    int m_nominator;
    int m_denominator;

};

#endif // RATIONALNUMBER_H

