#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

struct RationalNumber {
    int nominator;
    int denominator;
};

bool rnIsValid(RationalNumber n);
bool rnIsNaN(RationalNumber n);
bool rnEqual(RationalNumber n, RationalNumber m);
bool rnLessThan(RationalNumber n, RationalNumber m);

/*
  Compares two RationalNumbers and returns:
 -1 if n < m
  0 if n = m
  1 if n > m
  */
int rnCompareTo(RationalNumber n, RationalNumber m);
RationalNumber rnAdd(RationalNumber n, RationalNumber m);
RationalNumber rnSub(RationalNumber n, RationalNumber m);
RationalNumber rnMul(RationalNumber n, RationalNumber m);
RationalNumber rnDiv(RationalNumber n, RationalNumber m);

#endif // RATIONALNUMBER_H
