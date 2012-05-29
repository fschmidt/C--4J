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

public:
    T& value(){
        return m_value;
    }

    TreeNode<T,O>* find(const T&value);
    TreeNode<T,O>* findFirst();
    TreeNode<T,O>* findLast();


}

#endif // TREENODE_H
