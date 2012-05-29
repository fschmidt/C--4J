#ifndef MAPTOFIRST_H
#define MAPTOFIRST_H

#include "less.h"
#include "pair.h"

template < typename K, typename V, template <typename K> class Op = Less >
class MapToFirst {
private:
    Op<K> m_order;

public:
    bool operator () (const Pair<K, V> &lhs, const Pair<K, V> &rhs){
        return m_order(lhs.key(), rhs.key());
    }

};

#endif // MAPTOFIRST_H
