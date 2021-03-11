#ifndef _HASHNODE
#define _HASHNODE
#include <iostream>

template <class K, class V>
class HashNode
{
private:
    K key;
    V value;
    HashNode *next;
    // disallow copy and assignment
    HashNode(const HashNode &);
    HashNode &operator=(const HashNode &);

public:
    HashNode(const K &k, const V &val)
    {
        key = k;
        value = val;
        next = NULL; // pointer to next bucket with same key
    }

    K getKey() const
    {
        return key;
    }
    V getValue() const
    {
        return value;
    }
    void setValue(V val)
    {
        value = val;
    }
    HashNode *getNext() const
    {
        return next;
    }
    void setNext(HashNode *n)
    {
        next = n;
    }
};

#endif /* HASH NODE */
