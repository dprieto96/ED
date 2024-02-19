#include "pila.h"
#include "cola.h"
#include <iostream>
using namespace std;

template <class T>
void invierteN (Pila<T>& pila, int N);


int main() {
	
	Pila<int> pila;
	for (int i = 1; i <= 10; i++)
		pila.apila(i);

	invierteN(pila, 5);

	// incluye aquí código para imprimir la pila tras la inversión
	while (!pila.esVacia()) {
		cout << pila.cima() << " ";
		pila.desapila();
	}

	return 0;
}


template <class T>
void invierteN(Pila<T>& pila, int N){ // asumimos que la pila tiene al menos N elementos
	Cola <int> cola;
	int i = 0;

	while (!pila.esVacia() && (i<N)) {
		cola.pon(pila.cima());
		pila.desapila();
		i++;
	}

	i = 0;
	while (!cola.esVacia() && (i < N)) {
		pila.apila(cola.primero());
		cola.quita();
		i++;
	}
	
}