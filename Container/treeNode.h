#ifndef TREENODE_H
#define TREENODE_H

#include "less.h"
#include "tree.h"
#include "treeIterator.h"

template< typename T, typename O = Less<T> >
class TreeNode{
    friend class Tree<T,O>;
    friend class TreeIterator<T,O>;

protected:
    TreeNode<T,O> m_left;
    TreeNode<T,O> m_right;
    TreeNode<T,O> m_up;
    T m_value;

//private:
    T& value(){
        return m_value;
    }

    TreeNode<T,O>* find(const T&value){
        O lessThan;
        if( lessThan(m_value, value) ){
            return m_right.find(value);
        } else if( lessThan(value, m_value) ){
            return m_left.find(value);
        } else {
            return this;
        }
    }

    TreeNode<T,O>* findFirst(){
        if( m_left == 0 ){
            return this;
        } else {
            m_left.findFirst();
        }
    }

    TreeNode<T,O>* findLast(){
        if( m_right == 0 ){
            return this;
        } else {
            m_right.findFirst();
        }
    }

public:
    TreeNode(TreeNode<T,O> up = 0, T value = T()):
        m_up(up),
        m_value(value){}

}

#endif // TREENODE_H
