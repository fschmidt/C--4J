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

    /*
      return a reference to the current node
     */
    T& operator*() {
       return (m_node->m_value);
    }

    /*
      return a pointer to the current node
     */
    T* operator->() {
        return &(m_node->m_value);
    }

    /*
      Go to the next node.
      The process to the iteration is: root -> left node -> right node
      return the next node
     */
    TreeIterator<T,O>& operator++() {
        if( !m_node ){ // no notes in the tree
            return *this;
        } if(m_node->m_left){ //go to the left node
            this->m_node = this->m_node->m_left;
            return *this;
        } else if(m_node->m_right){ // go to the right node
            this->m_node = this->m_node->m_right;
            return *this;
        } else { // go to the next right tree part and go in root node of this tree
            return toNextRight(m_node);
        }

    }

    /*
      Go to the previous node.
      The process to the iteration is: right node -> left node -> root
      return the previous node
     */
    TreeIterator<T,O>& operator--() {
        if( !m_node ){ // the node is the end node
            this->m_node = this->m_tree->last().m_node;
            return findFirstRightTree(this->m_node); // this is magic, do not touch !!
        } else if(m_node->m_up && m_node->m_up->m_left &&  m_node->m_up->m_left != m_node){ //go to the left node from the up node of the current node, when the left note different the current node
            return toNextLeft(m_node->m_up->m_left);
        } else if(m_node->m_up){ // go to the up node
            this->m_node = this->m_node->m_up;
            return *this;
        } else { // the node is the root of the tree
            return *this;
        }
    }

    /*
     return true when the pointer to the tree and the pointer to the node are equals
            else false
     */
    bool operator == (const TreeIterator<T,O> &rhs){
        return (this->m_tree == rhs.m_tree && this->m_node == rhs.m_node);
    }

    /*
     return true when the pointer to the tree or the pointer to the node are different
            else false
     */
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
