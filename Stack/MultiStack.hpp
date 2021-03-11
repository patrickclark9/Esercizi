#ifndef MULTISTACK
#define MULTISTACK
#include "stack.hpp"

template<class T>
class MultipleStack
{
    void MultipleStac(unsigned int);
    void ~MultipleStack();
    void pushStack(T&, unsigned int);
    T& popStack(unsigned int);
    void printStack();  

    private:
    int nStack;
    Stack<T> *multiple;
};
template <class T>
void MultipleStack<T>::MultipleStac(unsigned int n)
{
    nStack = n;
    multiple = new Stack<T> [n];

}

template <class T>
 MultipleStack<T>::~MultipleStack()
{
    for(int i = 0; i<= nStack;i++)
    delete multiple[i];
    // delete[] multiple;
}

template <class T>
void MultipleStack<T>::pushStack(T& a, unsigned int n)
{
 multiple[n-1].inPila(a);
}

template <class T>
T& MultipleStack<T>::popStack(unsigned int a)
{
    T elem = multiple[a].leggiPila();
    multiple[a].fuoriPila();
    return elem;
}

template <class T>
void MultipleStack<T>::printStack()
{
    int a = nStack-1;
    for(;a>=0; a --)
    {
        std::cout << " " << multiple[nStack] << endl;

    }
}


#endif /* MULTISTACK*/