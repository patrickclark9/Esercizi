#ifndef _HASHMAP
#define _HASHMAP
#include "HashNode.hpp"
#include <iostream>

using namespace std;

template <class K, class V>
class HashMap
{
private:
    HashNode<K, V> **map;
    int capacity;
    int size;

public:
    HashMap()
    {
        capacity = 50;
        size = 0;
        map = new HashNode<K, V> *[capacity];

        for (int i = 0; i < capacity; i++)
        {
            map[i] = NULL;
        }
    }
    ~HashMap()
    {
        for (int i = 0; i < capacity; i++)
        {
            HashNode<K, V> *entry = map[i];
            while (entry != NULL)
            {
                HashNode<K, V> *prev = entry;
                entry = entry->getNext();
                delete prev;
            }
            map[i] = NULL;
        }
    }

    int hashFunc(K key)
    {
        return key % capacity;
    }

    void insertNode(K key, V value)
    {
        HashNode<K, V> *temp = new HashNode<K, V>(key, value);
        // gets index of key
        int hashIndex = hashFunc(key);
        HashNode<K, V> *prev = NULL;

        HashNode<K, V> *entry = map[hashIndex];

        // find free space
        while (entry != NULL && entry->getKey() != key)
        {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == NULL)
        {
            if (prev == NULL)
            {
                // first bucket
                map[hashIndex] = temp;
                size++;
            }
            else
            {
                // set as next bucket
                prev->setNext(temp);
                size++;
            }
        }
        // just replace values
        else
        {
            temp->setValue(value);
        }
    }

    void remove(K key)
    {
        // gets index of key
        int hashIndex = hashFunc(key);
        HashNode<K, V> *prev = NULL;

        HashNode<K, V> *entry = map[hashIndex];

        // find free space
        while (entry != NULL && entry->getKey() != key)
        {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == NULL)
        {
            cout << "key not found" << endl;
            return;
        }
        else
        {
            if (prev == NULL)
            {
                map[hashIndex] = entry->getNext();
                size--;
            }
            else
            {
                prev->setNext(entry->getNext());
                size--;
            }
            delete entry;
        }
    }

    V getValuefromKey(K key)
    {
        int hashIndex = hashFunc(key);
        int count = 0;
        HashNode<K, V> *temp = map[hashIndex];
        while (temp != NULL)
        {
            if (temp->getKey() == key)
            {
                return temp->getValue();
                cout << "key found" << temp->getValue() << endl;
            }
            temp = temp->getNext();
        }
        return NULL;
        cout << "key not found" << endl;
    }

    int sizeOfMap()
    {
        return size;
    }

    bool mapEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // to check

    void display()
    {

        for (int i = 0; i < capacity; i++)
        {
            HashNode<K, V> *temp = map[i];
            if (temp != NULL)
                cout << "key = " << temp->getKey() << "  value = " << temp->getValue() << endl;
        }
    }
};

#endif /* HASH MAP */