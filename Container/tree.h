#ifndef TREE_H
#define TREE_H

#include "less.h"
#include "treeNode.h"
#include "treeIterator.h"

namespace myContainer {
template< typename T, typename O = Less<T> >
class Tree{

private:
    TreeNode<T,O> *m_root;

public:
    typedef TreeIterator<T,O> iterator;
    typedef TreeNode<T,O> node;

    Tree(TreeNode<T,O> *root = 0):
        m_root(root){}

    TreeNode<T,O> *Root(){
        return m_root;
    }

    /*
     insert a node in the tree
     return a TreeIteraor with the insertet node
     */
    TreeIterator<T,O>& insert(const T &value){
        if(!m_root){ // no notes in the tree
            m_root = new TreeNode<T,O>(value);
            TreeIterator<T,O> *iterator = new TreeIterator<T,O>(m_root, this);
            return *iterator;
        }

        O lessThan;
        if(lessThan(value, m_root->m_value)){ //go in the left sube tree
            if((m_root->m_left) ){
                Tree<T,O> *tree = new Tree<T,O>( m_root->m_left);
                return tree->insert(value);
            }
            // insert node
            TreeNode<T,O> *inserted = new TreeNode<T,O>(value, m_root);
            m_root->m_left = inserted;
            TreeIterator<T,O> *iterator = new TreeIterator<T,O>(m_root->m_left, this);
            return *iterator;
        }
        if(lessThan(m_root->m_value, value)){ //go in the right sube tree
            if((m_root->m_right)){
                Tree<T,O> *tree = new Tree<T,O>( m_root->m_right);
                return tree->insert(value);
            }
            // insert node
            TreeNode<T,O> *inserted = new TreeNode<T,O>(value, m_root);
            m_root->m_right = inserted;
            TreeIterator<T,O> *iterator = new TreeIterator<T,O>(m_root, this);
            return *iterator;
        }

        // replace current node
        TreeNode<T,O> *inserted = new TreeNode<T,O>(value, m_root);
        if(lessThan(value, m_root->m_value)){
            m_root->m_left = inserted;
        } else {
            m_root->m_right = inserted;
        }
        TreeIterator<T,O> *iterator = new TreeIterator<T,O>(m_root, this);
        return *iterator;

    }

    /*
     clear the tree
     */
    void clear(){
        if(m_root->m_left){
            Tree leftTree = m_root->m_left;
            leftTree.clear();
            delete m_root->m_left;
        }
        if(m_root->m_right){
            Tree rightTree = m_root->m_right;
            rightTree.clear();
            delete m_root->m_right;
        }
        m_root = 0;
    }

    /*
     give return the root of the tree
     return root node
     */
    TreeIterator<T,O> begin(){
        return TreeIterator<T,O>(m_root, this);
    }

    /*
     give return a iterator with a null pointer as note
     return null node
     */
    TreeIterator<T,O> end(){
        return TreeIterator<T,O>(0, this);
    }

    /*
     find the lowest left node
     return the lowest left node
     */
    TreeIterator<T,O> first(){
        return TreeIterator<T,O>(m_root->findFirst(), this);
    }

    /*
     find the lowest right node
     return the lowest right node
     */
    TreeIterator<T,O> last(){
        return TreeIterator<T,O>(m_root->findLast(), this);
    }

    /*
     Saerch a value into the tree
     return A TreeNode Object if found the value else a null pointer
     */
    TreeIterator<T,O> find(const T &value){
        TreeNode<T,O> *node = this->m_root->find(value);
        if(node != 0){
            return TreeIterator<T,O>(node, this);
        } else {
            return this->end();
        }
    }
};

}


#endif // TREE_H
