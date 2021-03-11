#ifndef list_hpp
#define list_hpp

#include <iostream>

template <class V>
class ListNode
{
private:
    V value;
    ListNode<V> *next;
    ListNode<V> *prev;

public:
    void setValue(V val)
    {
        value = val;
    }
    V getValue()
    {
        return value;
    }
    void setNext(ListNode<V> *nxt)
    {
        next = nxt;
    }
    void setPrev(ListNode<V> *prv)
    {
        prev = prv;
    }

    ListNode<V> *getNext()
    {
        return next;
    }
    ListNode<V> *getPrev()
    {
        return prev;
    }
};

template <class V>
class LinkedList
{
private:
    ListNode<V> *head;
    int length;

public:
    LinkedList<V> &operator=(LinkedList<V> &);
    LinkedList()
    {
        head = new ListNode<V>;
        head->setNext(head);
        head->setPrev(head);
        length = 0;
    }

    // copy constructor

    LinkedList(const LinkedList<V> &l)
    {
        ListNode<V> *node = l.last();
        length = l.size();
        head = new ListNode<V>;
        head->setNext(head);
        head->setPrev(head);
        if (!l.empty())
        {
            for (int i = 0; i < l.size(); i++)
            {
                insert(l.read(node), begin());
                node = node->getPrev();
            }
        }
    }

    ~LinkedList()
    {
        while (!empty())
        {
            erase(begin());
        }
        delete head;
    }

    int size() const
    {
        return length;
    }

    bool empty() const
    {
        if (length == 0)
        {
            return true;
        }
        return false;
    }

    ListNode<V> *begin() const
    {
        return head->getNext();
    }

    ListNode<V> *last() const
    {
        return head->getPrev();
    }

    bool isPresent(const LinkedList<V> &L, V val) const
    {
        ListNode<V> *node = new ListNode<V>;
        node = L.begin();

        while (!end(node))
        {
            if (node->getValue() == val)
            {
                std::cout << "element found" << std::endl;
                return true;
            }
            node = node->getNext();
        }
        std::cout << "element not found in list" << std::endl;

        return false;
    }

    ListNode<V> *getNode(const LinkedList<V> &L, V val) const
    {
        ListNode<V> *node = new ListNode<V>;
        node = L.begin();

        while (!end(node))
        {
            if (node->getValue() == val)
            {
                return node;
            }
            node = node->getNext();
        }
        return 0;
    }

    bool end(ListNode<V> *node) const
    {
        if (node == head)
        {
            return true;
        }
        return false;
    }

    void insert(V val, ListNode<V> *node)
    {
        ListNode<V> *newNode = new ListNode<V>;
        newNode->setValue(val);
        newNode->setNext(node);
        newNode->setPrev(node->getPrev());
        node->getPrev()->setNext(newNode);
        node->setPrev(newNode);
        length++;
    }

    V read(ListNode<V> *node) const
    {
        return (node->getValue());
    }

    int getLength() const
    {
        return length;
    }

    void erase(ListNode<V> *node)
    {
        if (!empty())
        {
            node->getNext()->setPrev(node->getPrev());
            node->getPrev()->setNext(node->getNext());
            delete node;
            length--;
        }
    }
};

template <class V>
LinkedList<V> &LinkedList<V>::operator=(LinkedList<V> &L)
{
    if (this != &L)
    {
        length = L.size();
        head = new ListNode<V>;
        head->setNext(head);
        head->setPrev(head);
        std::cout << L.empty();
        std::cout << L.size();

        if (!L.empty())
        {
            ListNode<V> *pos = new ListNode<V>;
            pos = L.last();
            for (int i = 0; i < L.size(); i++)
            {
                std::cout << i, L.read(pos);
                insert(L.read(pos), begin());
                pos = pos->getPrev();
            }
        }
    }
    return *this;
}

template <class V>
std::ostream &operator<<(std::ostream &os, const LinkedList<V> &l)
{
    ListNode<V> *node = new ListNode<V>;
    node = l.begin();
    os << "[";
    while (!l.end(node))
    {
        if (node != l.begin())
        {
            os << ", " << l.read(node);
        }
        else
        {
            os << l.read(node);
        }
        node = node->getNext();
    }
    os << "]" << std::endl;
    return os;
}

#endif /* list_hpp */
