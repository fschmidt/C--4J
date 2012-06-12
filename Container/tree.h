#ifndef TREE_H
#define TREE_H

#include "less.h"
#include "treeNode.h"
#include "treeIterator.h"

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

    TreeIterator<T,O>& insert(const T &value){
        if(!m_root){
            m_root = new TreeNode<T,O>(value);
            TreeIterator<T,O> *iterator = new TreeIterator<T,O>(m_root, this);
            return *iterator;
        }

        O lessThan;
        if(lessThan(value, m_root->m_value)){
            if((m_root->m_left) ){
                Tree<T,O> *tree = new Tree<T,O>( m_root->m_left);
                return tree->insert(value);
            }
            TreeNode<T,O> *inserted = new TreeNode<T,O>(value, m_root);
            m_root->m_left = inserted;
            TreeIterator<T,O> *iterator = new TreeIterator<T,O>(m_root, this);
            return *iterator;
        }
        if(lessThan(m_root->m_value, value)){
            if((m_root->m_right)){
                Tree<T,O> *tree = new Tree<T,O>( m_root->m_right);
                return tree->insert(value);
            }
            TreeNode<T,O> *inserted = new TreeNode<T,O>(value, m_root);
            m_root->m_right = inserted;
            TreeIterator<T,O> *iterator = new TreeIterator<T,O>(m_root, this);
            return *iterator;
        }

        TreeNode<T,O> *inserted = new TreeNode<T,O>(value, m_root);
        if(lessThan(value, m_root->m_value)){
            m_root->m_left = inserted;
        } else {
            m_root->m_right = inserted;
        }
        TreeIterator<T,O> *iterator = new TreeIterator<T,O>(m_root, this);
        return *iterator;

    }

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

    TreeIterator<T,O> begin(){
        return TreeIterator<T,O>(m_root, this);
    }

    TreeIterator<T,O> end(){
        return TreeIterator<T,O>(0, this);
    }

    TreeIterator<T,O> first(){
        return TreeIterator<T,O>(m_root->findFirst(), this);
    }

    TreeIterator<T,O> last(){
        return TreeIterator<T,O>(m_root->findLast(), this);
    }

    TreeIterator<T,O> find(const T &value){
        TreeNode<T,O> *node = new TreeNode<T,O>(value);
        node->find(value);
        return TreeIterator<T,O>(node, this);
    }
};


#endif // TREE_H
