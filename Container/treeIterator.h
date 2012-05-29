#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "less.h"
#include "tree.h"
#include "treeNode.h"

template< typename T, typename O = Less<T> >
class TreeIterator{
private:
    Tree<T,O> m_tree;
    TreeNode<T,O> m_note;

public:
    TreeIterator(TreeNode<T,O> node);
    T& operator*();
    T* operator->();
    TreeIterator<T,O>& operator++();
    TreeIterator<T,O>& operator--();
    bool operator==(const TreeIterator<T,O> &rhs);
    bool operator!=(const TreeIterator<T,O> &rhs);


}

#endif // TREEITERATOR_H
