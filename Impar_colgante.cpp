// NOMBRE Y APELLIDOS INTEGRANTE 1:
// NOMBRE Y APELLIDOS INTEGRANTE 2:
// USUARIO DEL JUEZ:


#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;



/** INDICA AQUÍ JUSTIFICADAMENTE LA COMPLEJIDAD DEL ALGORITMO

	**/

int n_imparColgantes(Arbin<int> a, int &suma_ancestros,int &suma_descendientes) {
	if (a.esVacio()) {
		suma_descendientes = 0;
		return 0;
	}

	else {
		int suma_izq, suma_der;
		int nodos_imparcolgantes = 0;
		
		if (a.raiz() % 2 != 0) suma_ancestros += a.raiz();
		
		int imparcolgantes_izq = n_imparColgantes(a.hijoIz(), suma_ancestros, suma_izq);
		int imparcolgantes_der = n_imparColgantes(a.hijoDer(), suma_ancestros, suma_der);

		if (a.raiz() % 2 != 0) suma_ancestros -= a.raiz();

		suma_descendientes = suma_izq + suma_der;
		
		if (suma_descendientes>suma_ancestros) {
			nodos_imparcolgantes = 1;
		}

		if (a.raiz() % 2 != 0) {
			suma_descendientes += a.raiz() ;
		}

		return nodos_imparcolgantes+imparcolgantes_izq+imparcolgantes_der;
	}


}


int numImparColgantes(Arbin<int> a) {
	// IMPLEMENTA AQUÍ EL SUBPROGRAMA
	int suma_ancestros=0, suma_descendientes;
	return n_imparColgantes(a,suma_ancestros,suma_descendientes);
	
}



/*
Formato de la entrada
=====================
El formato de cada caso es como sigue:
- Cada línea contiene la descripción de un árbol
- Para describir los árboles se sigue el siguiente convenio:
* Los árboles vacíos se escriben como #
* Los árboles simples se escriben como [c], con c el contenido del nodo.
* Los árboles compuestos se escriben como (IcD), donde:  (i) I es el hijo izquierdo; (ii) c es el contenido de la raíz; (iii) D es el hijo derecho.


Formato de la salida
====================
Para cada caso el programa imprime el número de nodos impar-colgantes.


Ejemplo de entrada
==================
#
[11]
([3]1[5])
(([7]8([9]6#))5(#13([15]3[6])))


Salida asociada
===============
0
0
1
4


*/

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



void ejecuta_caso() {
	Arbin<int> a = lee_arbol(cin);
	cout << numImparColgantes(a);
	cout << endl;
}


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF) {
		ejecuta_caso();
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}