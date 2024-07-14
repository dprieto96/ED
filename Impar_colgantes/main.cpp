// NOMBRE Y APELLIDOS INTEGRANTE 1:
// NOMBRE Y APELLIDOS INTEGRANTE 2:
// USUARIO DEL JUEZ:


#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;



/** INDICA AQUÍ JUSTIFICADAMENTE LA COMPLEJIDAD DEL ALGORITMO

	**/

bool esImpar(int a) {

	if (a % 2 != 0) return true;
	else return false;
}

int colgantes(Arbin<int> a,int ancestros, int &descendientes) {
	if(a.esVacio()){
		descendientes = 0;
		return 0;
	}
	else {
		if (esImpar(a.raiz()))ancestros += a.raiz();

		int colgantes_a_devolver;
		int desc_izq, desc_der;

		int colgantes_izq = colgantes(a.hijoIz(),ancestros,desc_izq);
		int colgantes_der = colgantes(a.hijoDer(), ancestros,desc_der);


		
		descendientes = desc_izq + desc_der;
		if (esImpar(a.raiz()))ancestros -= a.raiz();
		if (descendientes > ancestros)colgantes_a_devolver = 1;
		else colgantes_a_devolver = 0;

		if (esImpar(a.raiz())) {
			descendientes += a.raiz();
			
		}
		
		return colgantes_a_devolver+ colgantes_izq+colgantes_der;
	
	}
}

int numImparColgantes(Arbin<int> a) {
	// IMPLEMENTA AQUÍ EL SUBPROGRAMA

	int ancestros = 0;
	int descendientes;
	return colgantes(a,ancestros,descendientes);
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