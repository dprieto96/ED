// NOMBRE Y APELLIDOS:
// USUARIO DEL JUEZ:


#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/*
Determinar justificadamente la complejidad del algoritmo:

*/
int num_correctivos_aux(const Arbin<int>& a,int &suma, int &nodos) {
	if (a.esVacio()) {
		nodos = 0;
		suma = 0;
		return 0;
	}
	else {
		int izq_nodos,der_nodos;
		int  der_suma,izq_suma;
		int correctivos=0;

		int izq_correctivos = num_correctivos_aux(a.hijoIz(), izq_suma, izq_nodos);
		int der_correctivos = num_correctivos_aux(a.hijoDer(),der_suma,der_nodos);

		//cout << "Para el nodo: " << a.raiz() << "su suma es: " << der_suma << " y nodos izq: " << izq_nodos << endl;
		

		if (!a.hijoDer().esVacio()) {
			if (a.raiz() == der_suma - izq_nodos) {
				correctivos = 1;
			}
			else correctivos= 0;

		}

		suma = a.raiz() + der_suma+izq_suma;
		nodos = 1 + izq_nodos+der_nodos;

		return correctivos + izq_correctivos + der_correctivos;

	
	}

}


int num_correctivos(const Arbin<int>& a) {
	// A IMPLEMENTAR
	int suma, nodos;
	return num_correctivos_aux(a, suma, nodos);

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
		cout << num_correctivos(a) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}
