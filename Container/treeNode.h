#ifndef TREENODE_H
#define TREENODE_H

#include "less.h"
//#include "tree.h"
//#include "treeIterator.h"

template <typename T, typename O> class Tree;
template <typename T, typename O> class TreeIterator;

template< typename T, typename O = Less<T> >
class TreeNode{
    friend class Tree<T,O>;
    friend class TreeIterator<T,O>;

protected:
    TreeNode<T,O> *m_left;
    TreeNode<T,O> *m_right;
    TreeNode<T,O> *m_up;
    T m_value;

//private:
    T& value(){
        return m_value;
    }

    TreeNode<T,O>* find(const T &value){
        O lessThan;
        if( lessThan(m_value, value) ){
            return m_right->find(value);
        } else if( lessThan(value, m_value) ){
            return m_left->find(value);
        } else {
            return this;
        }
    }

    TreeNode<T,O>* findFirst(){
        if( this && m_left ){
            return m_left->findFirst();
        } else if( m_right ){
            return m_right->findFirst();
        } else {
           return this;
        }
    }

    TreeNode<T,O>* findLast(){
        if( this && m_right ){
            return m_right->findLast();
        } else if( m_left ){
            return m_left->findLast();
        } else {
            return this;
        }
    }

public:
    TreeNode(const T &value = T(), TreeNode<T,O> *up = 0):
        m_up(up),
        m_value(value){
        m_left = 0;
        m_right = 0;
    }
};

#endif // TREENODE_H
