#ifndef _CODAP
#define _CODAP
#include "assert.h"

template <class T>
class codaP
{
public:
    typedef T tipoelem;
    codaP();
    codaP(int);
    ~codaP();
    void creaPriorCoda();
    void inserisci(tipoelem);
    tipoelem min();
    void cancellaMin();

private:
    int dim;
    tipoelem *heap;
    int ultimo;
    void fixup();
    void fixdown(int, int);
};

template <class T>
codaP<T>::codaP() : dim(100)
{
    heap = new tipoelem[dim];
    creaPriorCoda();
}

template <class T>
codaP<T>::codaP(int max) : dim(max)
{
    heap = new tipoelem[dim];
    creaPriorCoda();
}

template <class T>
codaP<T>::~codaP()
{
    delete[] heap;
}

template <class T>
void codaP<T>::creaPriorCoda()
{
    ultimo = 0;
}

template <class T>
void codaP<T>::inserisci(tipoelem t)
{
    assert(ultimo < dim);
    heap[++ultimo - 1] = t;
    fixup();
}

template <class T>
codaP<T>::tipoelem
codaP<T>::min()
{
    assert(ultimo != 0);
    return (heap[0]);
}

template <class T>
void codaP<T>::cancellaMin()
{
    assert(ultimo != 0);
    heap[0] = heap[ultimo - 1];
    ultimo--;
    fixdown(1, ultimo);
}

template <class T>
void codaP<T>::fixup()
{
    int k = ultimo;

    while (k > 1 && heap[k - 1] < heap[k / 2 - 1])
    {
        tipoelem tmp;
        tmp = heap[k - 1];
        heap[k - 1] = heap[k / 2 - 1];
        heap[k / 2 - 1] = tmp;
        k = k / 2;
    }
}

template <class T>
void codaP<T>::fixdown(int k, int N)
{
    short int scambio = 1;

    while (k <= N / 2 && scambio)
    {
        int j = 2 * k;
        tipoelem tmp;
        if (j < N && heap[j - 1] > heap[j])
        {
            j++;
        }
        if (scambio = (heap[j - 1] < heap[k - 1]))
        {
            tmp = heap[k - 1];
            heap[k - 1] = heap[j - 1];
            heap[j - 1] = tmp;
            k = j;
        }
    }
}
#endif /* CODA */