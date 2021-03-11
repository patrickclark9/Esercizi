#ifndef _BINARYTREEC
#define _BINARYTREEC
#include "TreeNode.hpp"
#include "coda.hpp"
#include <iostream>
using namespace std;
template <class V>
class BinaryTree
{
    Node<V> *root;

public:
    BinaryTree(); // constructor

    ~BinaryTree();

    void insertRoot(Node<V> *); // rooted binary tree starting node

    void insertNodeSx(Node<V> *, Node<V> *); // given a node already present in the tree, it inserts a new node as left child of the given node

    void insertNodeDx(Node<V> *, Node<V> *); // given a node already present in the tree, it inserts a new node as right child of the given node

    void deleteTree(Node<V> *); // deletes subtree starting from the given node

    bool isLeaf(Node<V> *node) const // returns true if node is leaf
    {
        if (node->getLeft() == NULL && node->getRight() == NULL)
        {
            return true;
        }
        return false;
    }

    Node<V> *getRoot() const
    {
        return root;
    }

    Node<V> *search(V val) const // searches for a node in the whole tree;returns NULL if tree empty, the searched node if found
    {
        if (root == NULL)
        {
            return NULL;
        }
        // to substitute with my queue data structure
        Coda<Node<V> *> q;
        Node<V> *out = NULL;
        q.inCoda(root);

        while (q.codaVuota() == false)
        {
            Node<V> *temp = q.getFront();
            q.fuoriCoda();

            if (temp->getValue() == val)
            {
                out = temp;
            }
            if (temp->getLeft() != NULL)
            {
                q.inCoda(temp->getLeft());
            }
            if (temp->getRight() != NULL)
            {
                q.inCoda(temp->getRight());
            }
        }
        return out;
    }

    bool isEmpty() const
    {
        if (root == NULL)
        {
            return true;
        }
        return false;
    }
};

// default
template <class V>
BinaryTree<V>::BinaryTree()
{
    root = NULL;
}

template <class V>
BinaryTree<V>::~BinaryTree()
{
    deleteTree(root);
    delete root;
}

template <class V>
void BinaryTree<V>::insertRoot(Node<V> *val)
{
    if (root == NULL)
    {
        root = val;
        root->setParent(NULL);
    }
    else
    {
        cout << "root already inserted" << endl;
    }
}

template <class V>
void BinaryTree<V>::insertNodeSx(Node<V> *val, Node<V> *pos)
{
    if (pos != NULL)
    {
        if (pos->leftEmpty() == true)
        {
            pos->setLeft(val);
            val->setParent(pos);
        }
        else
        {
            cout << "left not empty" << endl;
        }
    }
    else
    {
        cout << "node not found" << endl;
    }
}

template <class V>
void BinaryTree<V>::insertNodeDx(Node<V> *val, Node<V> *pos)
{
    if (pos != NULL)
    {
        if (pos->rightEmpty() == true)
        {
            pos->setRight(val);
            val->setParent(pos);
        }
        else
        {
            cout << "left not empty" << endl;
        }
    }
    else
    {
        cout << "node not found" << endl;
    }
}

template <class V>
void BinaryTree<V>::deleteTree(Node<V> *pos)
{
    if (pos == NULL)
    {
        cout << "node not found" << endl;
        return;
    }

    if (pos->getLeft() != NULL)
    {
        deleteTree(pos->getLeft());
    }
    if (pos->getRight() != NULL)
    {
        deleteTree(pos->getRight());
    }

    pos->setValue(NULL);
}

#endif /* binary tree*/
