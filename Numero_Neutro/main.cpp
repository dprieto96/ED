#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/** Indica aquí, razonadamente, la complejidad de numero_neutros

*/
/*
unsigned int neutro(const Arbin<int>& a, int &nodos_neutros) {
	if (a.esVacio()) {
		
		return 0;
	}
	else {
		
		int nodos_positivos_izq = neutro(a.hijoIz(), nodos_neutros);
		int nodos_positivos_der = neutro(a.hijoDer(), nodos_neutros);

		//cout << "N: " << a.raiz() << " IZQ: " << nodos_positivos_izq << " DER " << nodos_positivos_der << endl;

		if (nodos_positivos_izq == nodos_positivos_der) {
			//cout << "ENTRA" << endl;
			nodos_neutros++;
		}
	
		if (a.raiz() > 0) {
			return nodos_positivos_izq + nodos_positivos_der + 1;
		}
		else return nodos_positivos_izq + nodos_positivos_der;

	}
	
}22:23 -> 24 min
*/
//PREORDER
unsigned int neutros(const Arbin<int>& a, int& nodos) {
	if (a.esVacio()) {
		nodos = 0;
		return 0;
	}
	else {
	
		int nodos_izq, nodos_der;
		int n_neutros=0;

		int neutros_izq = neutros(a.hijoIz(),nodos_izq);
		int neutros_der = neutros(a.hijoDer(),nodos_der);

		cout << "N: " << a.raiz() << " IZQ: " << nodos_izq << " DER " << nodos_der << endl;

		if (nodos_izq == nodos_der) {
			n_neutros = 1;
		}

		if (a.raiz() > 0) {
			nodos = nodos_izq + nodos_der + 1;
		}
		else nodos = nodos_izq + nodos_der;

		return n_neutros + neutros_izq + neutros_der;

	}

}
//INORDER 
unsigned int neutros(const Arbin<int>& a, int& nodos) {
	if (a.esVacio()) {
		nodos = 0;
		return 0;
	}
	else {
		int nodos_izq, nodos_der;
		int n_neutros = 0;

		// Procesar el nodo actual primero
		cout << "N: " << a.raiz() << endl;

		// Calcular el número de nodos
		if (a.raiz() > 0) {
			nodos = 1;
		}
		else {
			nodos = 0;
		}

		// Recorrer el subárbol izquierdo
		int neutros_izq = neutros(a.hijoIz(), nodos_izq);
		nodos += nodos_izq;

		// Recorrer el subárbol derecho
		int neutros_der = neutros(a.hijoDer(), nodos_der);
		nodos += nodos_der;

		if (nodos_izq == nodos_der) {
			n_neutros = 1;
		}

		return n_neutros + neutros_izq + neutros_der;
	}



unsigned int numero_neutros(const Arbin<int>& a) {
	// A IMPLEMENTAR
	/*int nodos = 0;
	neutro(a, nodos);
	return nodos;*/

	int nodos = 0;
	return neutros(a,nodos);

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
