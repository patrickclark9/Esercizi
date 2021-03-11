#ifndef _NTREE
#define _NTREE
#include "Node.hpp"
#include "coda.hpp"
#include <iostream>
using namespace std;

template <class T>
class Ntree
{
    Node<T> *root;

public:
    Ntree();
    ~Ntree();
    void insertRoot(T);
    void insertChild(T, T);
    void insertSibling(T, T);
    void deleteTree(T);

    bool isLeaf(Node<T> *node) const
    {
        if (node->getFirst() == NULL && node->getNext() == NULL)
        {
            return true;
        }
        return false;
    }

    Node<T> *getRoot() const
    {
        return root;
    }

    Node<T> *search(T val) const // searches for a node in the whole tree;returns NULL if tree empty, the searched node if found
    {
        if (root == NULL)
        {
            return NULL;
        }
        // to substitute with my queue data structure
        Coda<Node<T> *> q;
        Node<T> *out = NULL;
        q.inCoda(root);

        while (q.codaVuota() == false)
        {
            Node<T> *temp = q.getFront();
            q.fuoriCoda();

            if (temp->getValue() == val)
            {
                out = temp;
            }
            if (temp->getNext() != NULL)
            {
                q.inCoda(temp->getNext());
            }
            if (temp->getFirst() != NULL)
            {
                q.inCoda(temp->getFirst());
            }
        }
        return out;
    }

    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        return false;
    }

    bool lastSibling(Node<T> *node) const
    {
        if (node->getNext() == NULL)
        {
            return true;
        }

        return false;
    }
};

// default
template <class T>
Ntree<T>::Ntree()
{
    root = NULL;
}

template <class T>
Ntree<T>::~Ntree()
{
    deleteTree(root->getValue());
    delete root;
}

template <class T>
void Ntree<T>::insertRoot(T val)
{
    if (root == NULL)
    {
        Node<T> *node = new Node<T>(val);
        root = node;
        root->setParent(NULL);
    }
    else
    {
        cout << "root is not empty" << endl;
    }
}

template <class T>
void Ntree<T>::insertChild(T val, T pos)
{
    Node<T> *temp = search(pos);

    if (temp != NULL)
    {
        Node<T> *newNode = new Node<T>(val);
        if (temp->childEmpty() == true)
        {
            temp->setChild(newNode);
            newNode->setParent(temp);
        }
        else
        {
            cout << "child already exists";
        }
    }
    else
    {
        cout << "node not found";
    }
}

template <class T>
void Ntree<T>::insertSibling(T val, T pos)
{
    Node<T> *temp = search(pos);

    if (temp != NULL)
    {
        Node<T> *newNode = new Node<T>(val);

        if (temp->siblingEmpty() == true)
        {
            temp->setSibling(newNode);
            newNode->setParent(temp->getParent());
        }
        else
        {
            cout << "sibling already exists" << endl;
        }
    }
    else
    {
        cout << "node not found" << endl;
    }
}

template <class T>
void Ntree<T>::deleteTree(T pos)
{
    Node<T> *temp = search(pos);
    if (temp == NULL)
    {
        cout << "node not found" << endl;
        return;
    }

    if (temp->getFirst() != NULL)
    {
        deleteTree(temp->getFirstVal());
    }
    if (temp->getNext() != NULL)
    {
        deleteTree(temp->getNextVal());
    }

    temp->setValue(NULL);
}
#endif /* NTREE */
