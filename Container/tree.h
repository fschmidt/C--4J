#ifndef TREE_H
#define TREE_H

#include "less.h"
#include "treeNode.h"
#include "treeIterator.h"

typedef TreeIterator<T,O> iterator;
typedef TreeNode<T,O> node;

template< typename T, typename O = Less<T> >
class Tree{
private:
    TreeNode<T,O> m_root;

public:
    Tree( TreeNode root = TreeNode() ): m_root(root){}

    iterator insert(const T& value){
        O lessThan;
        if(lessThan(value, m_root.m_value)){

        }
    }

    void clear();
    iterator begin();
    iterator end();
    iterator first();
    iterator last();
    iterator find(const T& value);


}


#endif // TREE_H
