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

    void insertRoot(V); // rooted binary tree starting node

    void insertNodeSx(V, V); // given a node already present in the tree, it inserts a new node as left child of the given node

    void insertNodeDx(V, V); // given a node already present in the tree, it inserts a new node as right child of the given node

    void deleteTree(V); // deletes subtree starting from the given node

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
    deleteTree(root->getValue());
    delete root;
}

template <class V>
void BinaryTree<V>::insertRoot(V val)
{
    if (root == NULL)
    {
        Node<V> *node = new Node<V>(val);
        root = node;
        root->setParent(NULL);
    }
    else
    {
        cout << "root already inserted" << endl;
    }
}

template <class V>
void BinaryTree<V>::insertNodeSx(V val, V pos)
{
    Node<V> *temp = search(pos);

    if (temp != NULL)
    {
        Node<V> *newNode = new Node<V>(val);
        if (temp->leftEmpty() == true)
        {
            temp->setLeft(newNode);
            newNode->setParent(temp);
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
void BinaryTree<V>::insertNodeDx(V val, V pos)
{
    Node<V> *temp = search(pos);

    if (temp != NULL)
    {
        Node<V> *newNode = new Node<V>(val);
        if (temp->rightEmpty() == true)
        {
            temp->setRight(newNode);
            newNode->setParent(temp);
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
void BinaryTree<V>::deleteTree(V pos)
{
    Node<V> *temp = search(pos);
    if (temp == NULL)
    {
        cout << "node not found" << endl;
        return;
    }

    if (temp->getLeft() != NULL)
    {
        deleteTree(temp->getLeftVal());
    }
    if (temp->getRight() != NULL)
    {
        deleteTree(temp->getRightVal());
    }

    temp->setValue(NULL);
}

#endif /* binary tree*/
