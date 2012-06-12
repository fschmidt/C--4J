#ifndef MAP_H
#define MAP_H
#include "pair.h"
#include "tree.h"
#include "mapToFirst.h"
namespace myContainer {
template< typename K, typename V, typename O = MapToFirst< K, V > >
class Map{
    Tree< Pair<K, V>, O > m_tree;

public:
    typedef TreeIterator< Pair<K, V>, O > iterator;

    V& operator[](const K& key){
        iterator iterator = this->find(key);
        if(iterator != m_tree.end()){
            Pair<K, V> &pair = *iterator;
            return pair.value();
        } else {
            Pair<K, V> pair(key);
            return this->insert(pair)->value();
        }
    }

    iterator insert(const Pair<K, V> &pair){
        return this->m_tree.insert(pair);
    }

    iterator find(const K& key){
         return this->m_tree.find(key);
    }

    iterator begin(){
        return this->m_tree.begin();
    }

    iterator end(){
        return this->m_tree.end();
    }

    iterator first(){
        return this->m_tree.first();
    }

    iterator last(){
        return this->m_tree.last();
    }

    const K& min(){
        return (this->first()->key());
    }

    const K& max(){
        return (this->last()->key());
    }

    void clear(){
        this->m_tree.clear();
    }

};
}

#endif // MAP_H
