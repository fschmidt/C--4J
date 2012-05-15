#include "rationalnumber.h"

int euclid(int a, int b);

using namespace rnum;


RationalNumber::RationalNumber(double n):
    m_nominator(static_cast<int>(n*1000000.0+0.5)),
    m_denominator(1000000)
{
    RationalNumber tmp = normalize();
    m_nominator = tmp.m_nominator;
    m_denominator = tmp.m_denominator;
}

/*
  Check whether this RationalNumber is valid.
  returns: True if this RationalNumber is valid, False otherwise
  */
bool RationalNumber::isValid() const{
    return m_denominator != 0;
}

/*
  Check whether this RationalNumber is NaN (Not a Number).
  returns: True if this RationalNumber is NaN, False otherwise
  */
bool RationalNumber::isNaN(){
    return m_denominator==0;
}

/*
  Check whether this RationalNumber is equal to another RationalNumber.
  RationalNumbers are equal when all requirements for arithmetic equalty of RationalNumbers are met.
  returns: True if the given RationalNumbers are equal, False otherwise
  */
bool RationalNumber::equal(const RationalNumber &another) const {
    RationalNumber a = this->normalize();
    RationalNumber b = another.normalize();
    return (a.m_nominator == b.m_nominator && a.m_denominator == b.m_denominator);
}

bool RationalNumber::operator ==(const RationalNumber &another) const {
    return this->equal(another);
}

/*
  Check whether the arithmetic value this RationalNumber is less
  than the arithmetic value of another RationalNumber.
  returns: True if this < another, False otherwise
  */
bool RationalNumber::lessThan(const RationalNumber &another) const{
    if(compareTo(another) == -1){
        return true;
    }
    return false;
}

bool RationalNumber::operator <(const RationalNumber &another) const {
    return this->lessThan(another);
}

bool RationalNumber::operator <=(const RationalNumber &another) const {
    return this->lessThan(another) || this->equal(another);
}

bool RationalNumber::operator >=(const RationalNumber &another) const {
    return another.lessThan(*this) || this->equal(another);
}

bool RationalNumber::operator >(const RationalNumber &another) const {
    return another.lessThan(*this);
}

/*
  Compares two RationalNumbers
  returns:
 -1 if this < another
  0 if this = another
  1 if this > another
  */
int RationalNumber::compareTo(const RationalNumber &another) const{
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
RationalNumber RationalNumber::add(const RationalNumber &another) const{
    int nominator = m_denominator * another.m_nominator + m_nominator * another.m_denominator;
    int denominator = m_denominator * another.m_denominator;
    RationalNumber result(nominator, denominator);
    return result.normalize();
}

RationalNumber RationalNumber::operator+(const RationalNumber &another) const {
    return this->add(another);
}

RationalNumber RationalNumber::operator+=(const RationalNumber &r) {
    RationalNumber tmp = this->add(r);
    m_nominator = tmp.m_nominator;
    m_denominator = tmp.m_denominator;
    return  *this;
}

/*
  Basic arithmetic operation Subtraction for two RationalNumbers.
  returns: the result of this - another as a Rational Number
  */
RationalNumber RationalNumber::sub(const RationalNumber &another) const{
    int nominator = m_nominator * another.m_nominator;
    int denominator = m_denominator * another.m_nominator - m_nominator * another.m_denominator;
    RationalNumber result(nominator, denominator);
    return result.normalize();
}

RationalNumber RationalNumber::operator-(const RationalNumber &another) const {
    return this->sub(another);
}

RationalNumber RationalNumber::operator-=(const RationalNumber &r) {
    RationalNumber tmp = this->sub(r);
    m_nominator = tmp.m_nominator;
    m_denominator = tmp.m_denominator;
    return  *this;
}

RationalNumber RationalNumber::operator -() const {
    return RationalNumber(-m_nominator, m_denominator);

}

/*
  Basic arithmetic operation Multiplication for two RationalNumbers.
  returns: the result of this * another as a Rational Number
  */
RationalNumber RationalNumber::mul(const RationalNumber &another) const{
    int nominator = m_nominator * another.m_nominator;
    int denominator = m_denominator * another.m_denominator;
    RationalNumber result(nominator, denominator);
    return result;
}

RationalNumber RationalNumber::operator*(const RationalNumber &another) const {
    return this->mul(another);
}

RationalNumber RationalNumber::operator*=(const RationalNumber &r) {
    RationalNumber tmp = this->mul(r);
    m_nominator = tmp.m_nominator;
    m_denominator = tmp.m_denominator;
    return  *this;
}

/*
  Basic arithmetic operation Division  for two RationalNumbers.
  returns: the result of this / another as a Rational Number
  */
RationalNumber RationalNumber::div(const RationalNumber &another) const{
    RationalNumber reciprocus (another.m_denominator, another.m_nominator);
    return mul(reciprocus);
}

RationalNumber RationalNumber::operator/(const RationalNumber &another) const {
    return this->div(another);
}

RationalNumber RationalNumber::operator/=(const RationalNumber &r) {
    RationalNumber tmp = this->div(r);
    m_nominator = tmp.m_nominator;
    m_denominator = tmp.m_denominator;
    return  *this;
}

std::ostream& operator<< (std::ostream &lhs, const RationalNumber &rhs) {
    lhs << "RationalNumber: (" << rhs.nominator() << ", " << rhs.denominator() << ")";
    return lhs;
}

rnum::RationalNumber operator +(const int l, const rnum::RationalNumber &r){
    return RationalNumber(l) + r;
}

rnum::RationalNumber operator +(const double l, const rnum::RationalNumber &r){
    return RationalNumber(l) + r;
}

rnum::RationalNumber operator -(const int l, const rnum::RationalNumber &r){
    return RationalNumber(l) - r;
}

rnum::RationalNumber operator -(const double l, const rnum::RationalNumber &r){
    return RationalNumber(l) - r;
}

rnum::RationalNumber operator *(const int l, const rnum::RationalNumber &r){
    return RationalNumber(l) * r;
}

rnum::RationalNumber operator *(const double l, const rnum::RationalNumber &r){
    return RationalNumber(l) * r;
}

rnum::RationalNumber operator /(const int l, const rnum::RationalNumber &r){
    return RationalNumber(l) / r;
}

rnum::RationalNumber operator /(const double l, const rnum::RationalNumber &r){
    return RationalNumber(l) / r;
}


double RationalNumber::doubleValue() const {
    return (double)m_nominator / (double)m_denominator;
}

int RationalNumber::nominator() { return m_nominator; }
int RationalNumber::nominator() const { return m_nominator; }
int RationalNumber::denominator() { return m_denominator; }
int RationalNumber::denominator() const { return m_denominator; }


/*
  Normalizes a RationalNumber
  returns: The normalized RationalNumber
  */
RationalNumber RationalNumber::normalize() const{

    int i = 0;

    RationalNumber result(m_nominator, m_denominator);

    i = euclid(result.m_denominator, result.m_nominator);

    if((result.m_denominator % i > 0) || (result.m_nominator % i > 0)){
        return result;
    }

    result.m_denominator = result.m_denominator/i;
    result.m_nominator = result.m_nominator/i;

    return result;
}

int euclid(int a, int b){
    if (b == 0) {
        return a;
    } else {
        return euclid(b, a % b);
    }
}
