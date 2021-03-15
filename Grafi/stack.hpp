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

#endif /* STACK_H */