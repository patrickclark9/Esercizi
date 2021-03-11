#ifndef CODA_H
#define CODA_H
#include <iostream>
using namespace std;
template <class T>
class Coda
{
    typedef T tipoelem;

public:
    Coda();
    void creaCoda();
    Coda(int);
    ~Coda();
    bool codaVuota();
    void fuoriCoda();
    void inCoda(tipoelem);
    tipoelem getFront();
    tipoelem getRear();
    void flushQueue();
    void print()
    {
        if (!codaVuota())
        {
            cout << "[";
            int i = front;
            for (; i < lunghezza; i++)
            {
                cout << elementi[i] << endl;
            }
            cout << "]" << endl;
        }
        else
        {
            cout << "queue is empty" << endl;
        }
    }

    int getSize()
    {
        return size;
    }

private:
    tipoelem *elementi;
    int rear;
    int front;
    int lunghezza;
    int size;
};

template <class T>
void Coda<T>::flushQueue()
{
    while (codaVuota() == false)
    {
        fuoriCoda();
    }
}

template <class T>
Coda<T>::Coda()
{
    lunghezza = 20;
    creaCoda();
}
template <class T>
Coda<T>::Coda(int n)
{
    lunghezza = n;
    creaCoda();
}
template <class T>
void Coda<T>::creaCoda()
{
    elementi = new tipoelem[lunghezza];
    front = 0;
    rear = -1;
    size = 0;
}
template <class T>
bool Coda<T>::codaVuota()
{
    if (size == 0)
    {
        return true;
    }
    return false;
}
template <class T>
Coda<T>::~Coda()
{
    if (codaVuota() == false)
    {
        delete[] elementi;
    }
}
template <class T>
void Coda<T>::fuoriCoda()
{
    typedef T tipoelem;
    if (!codaVuota())
    {
        front = (front + 1) % lunghezza;
        size--;
    }
}

template <class T>
typename Coda<T>::tipoelem
Coda<T>::getFront()
{
    return elementi[front];
}

template <class T>
typename Coda<T>::tipoelem
Coda<T>::getRear()
{
    return elementi[rear];
}

template <class T>
void Coda<T>::inCoda(tipoelem e)
{
    if (size != lunghezza)
    {
        rear = (rear + 1) % lunghezza;
        elementi[rear] = e;
        size++;
    }
}

#endif /*CODA_H*/