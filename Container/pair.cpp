#ifndef PAIR_CPP
#define PAIR_CPP

#include "pair.h"


template<typename K, typename V>
K Pair<K,V>::key() {
    return m_key;
}

template<typename K, typename V>
K Pair<K,V>::key() const{
    return m_key;
}

template<typename K, typename V>
V Pair<K,V>::value() {
    return m_value;
}

template<typename K, typename V>
V Pair<K,V>::value() const {
    return m_value;
}

template<typename K, typename V>
std::ostream& operator << (std::ostream& lhs, const Pair<K, V> &rhs) {
    lhs << "<" << rhs.key() << ", " << rhs.value() << ">";
    return lhs;
}

#endif
