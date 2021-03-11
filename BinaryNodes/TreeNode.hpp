#ifndef NODE
#define NODE
#include <iostream>

template <class V>
class Node
{
    V value;
    int label;
    Node<V> *left;
    Node<V> *right;
    Node<V> *parent;

public:
    Node<V> *getLeft()
    {
        return left;
    }
    Node<V> *getRight()
    {
        return right;
    }
    V getValue()
    {
        return value;
    }
    int getLabel()
    {
        return label;
    }

    void setLabel1()
    {
        label = 1;
    }

    void setLabel0()
    {
        label = 0;
    }

    Node()
    {
        value = NULL;
        left = NULL;
        right = NULL;
        label = 0;
    }
    Node(V);

    void setLeft(Node<V> *);
    void setRight(Node<V> *);
    bool leftEmpty();
    bool rightEmpty();
    void setValue(V);
    void setParent(Node<V> *);
    Node<V> *getParent()
    {
        return parent;
    }
    V getLeftVal()
    {
        return left->value;
    }
    V getRightVal()
    {
        return right->value;
    }
};

template <class V>
Node<V>::Node(V inVal)
{
    value = inVal;
    left = NULL;
    right = NULL;
    label = 0;
}

template <class V>
void Node<V>::setParent(Node<V> *p)
{
    parent = p;
}

template <class V>
void Node<V>::setLeft(Node<V> *l)
{
    left = l;
}

template <class V>
void Node<V>::setRight(Node<V> *r)
{
    right = r;
}

template <class V>
void Node<V>::setValue(V val)
{
    value = val;
}
template <class V>
bool Node<V>::leftEmpty()
{
    if (left == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class V>
bool Node<V>::rightEmpty()
{
    if (right == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif /*TREE NODE*/