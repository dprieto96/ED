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
bool es_peculiar(const Arbin<int>& a) {
	// A IMPLEMENTAR
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