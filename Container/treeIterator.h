#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "less.h"
#include "tree.h"
#include "treeNode.h"

template< typename T, typename O = Less<T> >
class TreeIterator {
private:
    Tree<T,O> *m_tree;
    TreeNode<T,O> *m_node;

public:
    TreeIterator(TreeNode<T,O> &node):m_node(node){}
    TreeIterator(TreeNode<T,O> *node, Tree<T,O> *tree):
        m_tree(tree),
        m_node(node){}

    T& operator*() {
       return m_node.m_value;
    }

    T* operator->() {
        return &(m_node.m_value);
    }

    TreeIterator<T,O>& operator++() {
        if(m_node.m_right) {
            return getLeftIterator(m_node);
        } else {
            return TreeIterator(m_node.m_up);
        }
    }

    TreeIterator<T,O>& operator--() {
        if(m_node.m_left) {
            return getRightIterator(m_node);
        } else {
            return TreeIterator(m_node.m_up);
        }
    }

    bool operator == (const TreeIterator<T,O> &rhs){
        return (this->m_tree == rhs.m_tree && this->m_node == rhs.m_node);
    }

    bool operator != (const TreeIterator<T,O> &rhs){
        return !(this->m_tree == rhs.m_tree && this->m_node == rhs.m_node);
    }

private:

    TreeIterator<T,O>& getLeftIterator(TreeNode<T,O> &node) {
        if(!node.m_left) {
            return TreeIterator(node);
        } else {
            return getLeftIterator(node.m_left);
        }
    }

    TreeIterator<T,O>& getRightIterator(TreeNode<T,O> &node) {
        if(!node.m_right) {
            return TreeIterator(node);
        } else {
            return getLeftIterator(node.m_right);
        }
    }
};

#endif // TREEITERATOR_H
