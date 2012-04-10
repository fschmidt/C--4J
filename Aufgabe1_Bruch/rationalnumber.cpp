#include "rationalnumber.h";

RationalNumber rnNormalize(RationalNumber n);
int euclid(int a, int b);

bool rnIsValid(RationalNumber n){
    return n.denominator != 0;
}

bool rnIsNaN(RationalNumber n){
    return n.denominator==0;
}

bool rnEqual(RationalNumber n, RationalNumber m){
    RationalNumber a = rnNormalize(n);
    RationalNumber b = rnNormalize(m);
    return (a.denominator == b.denominator && a.nominator == b.nominator);
}

/*
  Compares two RationalNumbers and returns:
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

RationalNumber rnAdd(RationalNumber n, RationalNumber m){
    RationalNumber result = new RationalNumber();
    result.nominator = n.nominator * m.denominator + n.denominator * m.nominator;
    result.denominator = n.denominator * m.denominator;
    return rnNormalize(result);
}

RationalNumber rnSub(RationalNumber n, RationalNumber m){
    RationalNumber result = new RationalNumber();
    result.nominator = n.nominator * m.denominator - n.denominator * m.nominator;
    result.denominator = n.denominator * m.denominator;
    return rnNormalize(result);
}

RationalNumber rnMul(RationalNumber n, RationalNumber m){
    RationalNumber result = new RationalNumber();
    result.nominator = n.nominator*m.nominator;
    result.denominator = n.denominator*m.denominator;
    return result;
}

RationalNumber rnDiv(RationalNumber n, RationalNumber m) {
    RationalNumber reciprocus = new RationalNumber();
    reciprocus.nominator = m.denominator;
    reciprocus.denominator = m.nominator;
    return rnMul(n, reciprocus);
}

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
