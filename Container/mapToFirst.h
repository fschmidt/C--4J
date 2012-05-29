#ifndef MAPTOFIRST_H
#define MAPTOFIRST_H

#include "less.h"
#include "pair.h"

template < typename K, typename V, typename Op = Less<K> >
class MapToFirst {
private:
    Op m_order;

public:
    bool operator () (const Pair<K, V> &lhs, const Pair<K, V> &rhs);

};

#include "mapToFirst.cpp"

#endif // MAPTOFIRST_H
