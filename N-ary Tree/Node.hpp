#ifndef _Ntree
#define _Ntree
#include <vector>

using namespace std;

template <class T>
class Node
{
    T value;
    Node<T> *firstChild;
    Node<T> *nextSibling;
    Node<T> *parent;

public:
    Node()
    {
        value = NULL;
        firstChild = NULL;
        nextSibling = NULL;
        parent = NULL;
    }
    Node(T val)
    {
        value = val;
        firstChild = NULL;
        nextSibling = NULL;
        parent = NULL;
    }
    Node<T> *getFirst()
    {
        return firstChild;
    }

    Node<T> *getNext()
    {
        return nextSibling;
    }
    T getFirstVal()
    {
        return firstChild->value;
    }
    T getNextVal()
    {
        return nextSibling->value;
    }
    T getValue()
    {
        return value;
    }
    Node<T> *getParent()
    {
        return parent;
    }
    void setParent(Node<T> *p)
    {
        parent = p;
    }
    bool childEmpty();
    bool siblingEmpty();
    void setValue(T);
    void setChild(Node<T> *);
    void setSibling(Node<T> *);
};

template <class T>
bool Node<T>::childEmpty()
{
    if (firstChild == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool Node<T>::siblingEmpty()
{
    if (nextSibling == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Node<T>::setValue(T val)
{
    value = val;
}

template <class T>
void Node<T>::setChild(Node<T> *c)
{
    firstChild = c;
}

template <class T>
void Node<T>::setSibling(Node<T> *s)
{
    nextSibling = s;
}

#endif /* Ntree*/