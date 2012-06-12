#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "less.h"
#include "tree.h"
#include "treeNode.h"

namespace myContainer {
template< typename T, typename O = Less<T> >
class TreeIterator {
private:
    Tree<T,O> *m_tree;
    TreeNode<T,O> *m_node;

public:
    TreeIterator(TreeNode<T,O> *node = 0, Tree<T,O> *tree = 0):
        m_tree(tree),
        m_node(node){}

    T& operator*() {
       return (m_node->m_value);
    }

    T* operator->() {
        return &(m_node->m_value);
    }

    TreeIterator<T,O>& operator++() {
        if( !m_node ){
            return *this;
        } if(m_node->m_left){;
            this->m_node = this->m_node->m_left;
            return *this;
        } else if(m_node->m_right){
            this->m_node = this->m_node->m_right;
            return *this;
        } else {
            return toNextRight(m_node);
        }

    }

    TreeIterator<T,O>& operator--() {
        if( !m_node ){
            this->m_node = this->m_tree->last().m_node;
            return findFirstRightTree(this->m_node); // this is magic, do not touch !!
        } else if(m_node->m_up && m_node->m_up->m_left &&  m_node->m_up->m_left != m_node){
            return toNextLeft(m_node->m_up->m_left);
        } else if(m_node->m_up){
            this->m_node = this->m_node->m_up;
            return *this;
        } else {
            return *this;
        }
    }

    bool operator == (const TreeIterator<T,O> &rhs){
        return (this->m_tree == rhs.m_tree && this->m_node == rhs.m_node);
    }

    bool operator != (const TreeIterator<T,O> &rhs){
        return this->m_tree != rhs.m_tree || this->m_node != rhs.m_node;
    }

private:

    TreeIterator<T,O>& toNextRight(TreeNode<T,O> *node){
        if( node->m_up ){
            if(node->m_up->m_right && node->m_up->m_right != node){
                this->m_node = node->m_up->m_right;
                return *this;
            } else {
                return toNextRight(node->m_up);
            }
        } else {
            TreeIterator<T,O> iterator = m_tree->end();
            this->m_node = iterator.m_node;
            return *this;
        }
    }

    TreeIterator<T,O>& toNextLeft(TreeNode<T,O> *node){
        if( node->m_right ){
            return toNextRight(node->m_right);
        } else if (node->m_left){
            return toNextRight(node->m_left);
        } else {
            this->m_node = node;
            return *this;
        }
    }

    TreeIterator<T,O>& findFirstRightTree(TreeNode<T,O> *node){
        if( node->m_right ){
            return findFirstRightTree(node->m_right);
        } else if(node->m_left){
            return findFirstRightTree(node->m_left);
        } else {
            this->m_node = node;
            return *this;
        }
    }
};
}

#endif // TREEITERATOR_H
