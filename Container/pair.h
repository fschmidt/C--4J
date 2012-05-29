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

    K key(){
        return m_key;
    }

    K key() const{
        return m_key;
    }

    V value(){
        return m_value;
    }

    V value() const{
        return m_value;
    }

private:


};

template<typename K, typename V>
std::ostream& operator << (std::ostream& lhs, const Pair<K, V> &rhs){
    lhs << "<" << rhs.key() << ", " << rhs.value() << ">";
    return lhs;
}

//#include "pair.cpp"

#endif // PAIR_H
