#ifndef TREENODE_H
#define TREENODE_H

#include "less.h"

namespace myContainer {
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
            if(m_right){
                return m_right->find(value);
            }
            return 0;
        } else if( lessThan(value, m_value) ){
            if(m_left){
                return m_left->find(value);
            }
            return 0;
        } else {
            return this;
        }
    }

    TreeNode<T,O>* findFirst(){
        if( this && m_left ){
            return m_left->findFirst();
        } else {
           return this;
        }
    }

    TreeNode<T,O>* findLast(){
        if( this && m_right ){
            return m_right->findLast();
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
}

#endif // TREENODE_H
