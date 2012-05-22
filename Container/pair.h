#ifndef PAIR_H
#define PAIR_H

#include <iostream>

template<typename K, typename V>
class Pair {
    K m_key;
    V m_value;

public:
    Pair( K key = K(), V value = V() ):
        m_key(key),
        m_value(value){}

    K key();

    K key() const;

    V value();

    V value() const;

private:


};

template<typename K, typename V>
std::ostream& operator<< (std::ostream& lhs, const Pair<K, V> &rhs);

#include "pair.cpp"

#endif // PAIR_H
