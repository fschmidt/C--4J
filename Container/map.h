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

    /*
     search a key into the map if not found inserts the key
     returns the value mapped to the given key
     */
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

    /*
     insert a node in the map
     return a TreeIteraor with the insertet node
     */
    iterator insert(const Pair<K, V> &pair){
        return this->m_tree.insert(pair);
    }

    /*
     Saerch a value into the map
     return A TreeNode Object if found the value else a null pointer
     */
    iterator find(const K& key){
        return this->m_tree.find(key);
    }

    /*
     give return the root of the map
     return root node
     */
    iterator begin(){
        return this->m_tree.begin();
    }

    /*
     give return a iterator with a null pointer as note
     return null node
     */
    iterator end(){
        return this->m_tree.end();
    }

    /*
     find the lowest left node
     return the lowest left node
     */
    iterator first(){
        return this->m_tree.first();
    }

    /*
     find the lowest right node
     return the lowest right node
     */
    iterator last(){
        return this->m_tree.last();
    }

    /*
     find the lowest left node
     return the key of the lowest left node
     */
    const K& min(){
        return (this->first()->key());
    }

    /*
     find the lowest right node
     return the key of the lowest right node
     */
    const K& max(){
        return (this->last()->key());
    }

    /*
     clear the map
     */
    void clear(){
        this->m_tree.clear();
    }

};
}

#endif // MAP_H
