#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/** Indica aquí, razonadamente, la complejidad de numero_neutros

*/

unsigned int numero_neutros_aux(const Arbin<int>& a,int &nodos) {
	if (a.esVacio()) {
		nodos = 0;
		return 0;
	}
	else {
		int izq_nodos, der_nodos;
		int neutros = 0;
		int izq_neutros = numero_neutros_aux(a.hijoIz(), izq_nodos);
		int der_neutros = numero_neutros_aux(a.hijoDer(),der_nodos);

		//cout << "Para el nodo: " << a.raiz() << " IZQ: " << izq_nodos << " DER: " << der_nodos <<endl;

		if (izq_nodos == der_nodos) {
			neutros = 1;
			//cout << "ENTRA" << endl;
		} 
		
		if (a.raiz() > 0)
			nodos = 1 + izq_nodos + der_nodos;
		else nodos = izq_nodos + der_nodos;


		return neutros+izq_neutros+der_neutros;
		
	}
	//	(([2]2[-2])4(#1[10]))
}

unsigned int numero_neutros(const Arbin<int>& a) {
	// A IMPLEMENTAR
	int nodos;
	return numero_neutros_aux(a,nodos);
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
