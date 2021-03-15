#include <iostream>
#include "stack.hpp"

using namespace std;

template <class T>
void Stack<T>::Pila()
{
	creaPila();
}

template <class T>
void Stack<T>::deletePila()
{
	delete elementi;
}

template <class T>
void Stack<T>::creaPila()
{
	elementi = new tipoelem[MAX];
	testa = 0;
}
template <class T>
bool Stack<T>::pilaVuota() const
{
	if (testa == 0)
	{
		return true;
	}

	return false;
}
template <class T>
Stack<T>::tipoelem
Stack<T>::leggiPila() const
{
	return (elementi[testa - 1]);
}
template <class T>
void Stack<T>::fuoriPila()
{
	if (!pilaVuota())
	{
		testa = testa - 1;
	}
}

template <class T>
void Stack<T>::inPila(tipoelem t)
{
	if (testa != MAX)
	{
		this->elementi[testa] = t;
		testa++;
	}
}

template <class T>
void Stack<T>::stampaPila()
{
	testa = testa - 1;
	for (; testa >= 0; testa--)
	{
		cout << " " << elementi[testa] << endl;
	}
}

template <class T>
Stack<T>::tipoelem
Stack<T>::Pop()
{
	T elemento = leggiPila();
	fuoriPila();
	return elemento;
}
