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

    Tree(TreeNode<T,O> root = TreeNode<T,O>()):
        m_root(&root){}

    TreeIterator<T,O>& insert(const T &value){
        if(m_root->m_value){
            m_root = new TreeNode<T,O>(value);
            return TreeIterator<T,O>(m_root, this);
        }

        O lessThan;
        if(lessThan(value, m_root->m_value)){
            Tree<T,O> *tree = new Tree<T,O>( *(m_root->m_left));
            return tree->insert(value);
        } else if(lessThan(m_root->m_value, value)){
            Tree<T,O> *tree = new Tree<T,O>( *(m_root->m_right));
            return tree->insert(value);
        } else {
            TreeNode<T,O> *inserted = new TreeNode<T,O>(value, m_root);
            if(lessThan(value, m_root->m_value)){
                m_root->m_left = inserted;
            } else {
                m_root->m_right = inserted;
            }
            return TreeIterator<T,O>(m_root, this);
        }
    }

    void clear(){
        for(TreeIterator<T,O> i = this->begin(); i != this->end(); ++i){

        }
    }

    TreeIterator<T,O> begin(){
        return first();
    }

    TreeIterator<T,O> end(){
        return last();
    }

    TreeIterator<T,O> first(){
        TreeNode<T,O> *node = new TreeNode<T,O>();
        node->findFirst();
        return TreeIterator<T,O>(node, this);
    }

    TreeIterator<T,O> last(){
        TreeNode<T,O> *node = new TreeNode<T,O>();
        node->findLast();
        return TreeIterator<T,O>(node, this);
    }

    TreeIterator<T,O> find(const T &value){
        TreeNode<T,O> *node = new TreeNode<T,O>(value);
        node->find(value);
        return TreeIterator<T,O>(node, this);
    }
};


#endif // TREE_H
