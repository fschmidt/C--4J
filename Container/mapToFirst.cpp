#ifndef PAIR_CPP
#define PAIR_CPP

#include "mapToFirst.h"
#include "pair.h"

template < typename K, typename V, typename Op >
bool MapToFirst<K, V>::operator () (const Pair<K, V> &lhs, const Pair<K, V> &rhs){
    return m_order(lhs.key(), rhs.key());
}

#endif
