/**
  NOMBRE Y APELLIDOS:
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#include "Arbin.h"
#include <iostream>
#include <string>
using namespace std;


/*
* COMPLEJIDAD: Determina justificadamente la complejidad de este algoritmo.
*
*/


bool es_peculiar_aux(const Arbin<int>& a, int& min, int& max) {
	if (a.esVacio()) {
		min = INT_MAX;
		max = INT_MIN;
		return true;
	}
	else {
		int min_izq = INT_MAX, min_der = INT_MAX;
		int max_izq = INT_MIN, max_der = INT_MIN;

		bool peculiar_izq = es_peculiar_aux(a.hijoIz(), min_izq, max_izq);
		bool peculiar_der = es_peculiar_aux(a.hijoDer(), min_der, max_der);

		if (!a.hijoIz().esVacio()) {
			min = std::min(min_izq, a.raiz());
		}
		else {
			min = a.raiz();
		}

		if (!a.hijoDer().esVacio()) {
			max = std::max(max_der, a.raiz());
		}
		else {
			max = a.raiz();
		}

		// Imprimir los valores para el nodo actual
		cout << "Para el nodo: " << a.raiz() << " su MAX en la derecha: " << max << " y MIN en la izquierda: " << min << endl;

		return true; // Devuelve true siempre ya que no se necesita una lógica específica aquí
	}
}


bool es_peculiar(const Arbin<int>& a) {
	// A IMPLEMENTAR
	int min, max, suma;
	es_peculiar_aux(a, min, max);
	return true;
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

void muestra_solucion(bool rebuscado) {
  if (rebuscado) {
	 cout << "SI" << endl; 
  }	
  else {
	 cout << "NO" << endl; 
  }
}

int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		Arbin<int> a = lee_arbol(cin);
		muestra_solucion(es_peculiar(a));
		string resto_linea;
		getline(cin, resto_linea);
	}
    return 0;       
}