#ifndef TREE_H
#define TREE_H

#include "less.h"
#include "treeNode.h"
#include "treeIterator.h"

//typedef TreeIterator<T,O> iterator;
//typedef TreeNode<T,O> node;

template< typename T, typename O = Less<T> >
class Tree{

private:
    TreeNode<T,O> *m_root;

public:
    Tree(TreeNode<T,O> &root = TreeNode<T,O>()):
        m_root(&root){}

    TreeIterator<T,O> insert(const T &value){
        if(m_root->m_value){
            m_root = new TreeNode<T,O>(value);
            return TreeIterator<T,O>(m_root, this);
        }

        O lessThan;
        if(lessThan(value, m_root->m_value)){
            Tree<T,O> *tree = new Tree<T,O>( *(m_root->m_left));
            tree->insert(value);
        } else if(lessThan(m_root->m_value, value)){
            Tree<T,O> *tree = new Tree<T,O>( *(m_root->m_right));
            tree->insert(value);
        } else {
            TreeNode<T,O> *inserted = new TreeNode<T,O>(value, m_root);
            if(lessThan(value, m_root->m_value)){
                m_root->m_left = inserted;
            } else {
                m_root->m_right = inserted;
            }
        }
    }

    void clear();
    TreeIterator<T,O> begin();
    TreeIterator<T,O> end();
    TreeIterator<T,O> first();
    TreeIterator<T,O> last();
    TreeIterator<T,O> find(const T &value);
};


#endif // TREE_H
