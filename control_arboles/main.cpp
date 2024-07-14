#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/** Indica aquí, razonadamente, la complejidad de numero_neutros


*/

int n_positivos(const Arbin<int>& a) {
	if (a.esVacio())return 0;

	int total=0;
	if (a.raiz() > 0)total = 1;

	int izq=n_positivos(a.hijoIz());

	int der = n_positivos(a.hijoDer());


	return total;
}


// Función principal para contar nodos neutros
unsigned int numero_neutros(const Arbin<int>& a) {
	int izq = 0;
	int der = 0;

	if (a.esVacio())return 0;
	

	izq +=numero_neutros(a.hijoIz());
	der += numero_neutros(a.hijoDer());

	if (a.raiz() > 0) {
		return 1 + izq + der;
	}
	else {
		return izq + der;
	}

	return 0;
}



Arbin<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
  		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		Arbin<int> a = lee_arbol(cin);
		cout << numero_neutros(a) << endl;
		
		
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}
