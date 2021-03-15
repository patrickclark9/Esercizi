#ifndef STACK_H
#define STACK_H
#include <iostream>
#define MAX 100

template<class T>
class Stack
{
public:
    typedef T tipoelem;
	void Pila(); //costruttori
	void deletePila(); // distruttore
	void creaPila(); //operatori
	bool pilaVuota() const;
	tipoelem leggiPila() const;
	void fuoriPila();
	void inPila(tipoelem);
	void stampaPila();
	tipoelem Pop();
private:
	tipoelem *elementi;
	int testa;
};

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
typename Stack<T>::tipoelem
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
		std::cout << " " << elementi[testa] << std::endl;
	}
}

template <class T>
typename Stack<T>::tipoelem
Stack<T>::Pop()
{
	T elemento = leggiPila();
	fuoriPila();
	return elemento;
}


#endif /* STACK_H */