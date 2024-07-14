// NOMBRE Y APELLIDOS INTEGRANTE 1:
// NOMBRE Y APELLIDOS INTEGRANTE 2:
// USUARIO DEL JUEZ:


#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;



/** INDICA AQUÍ JUSTIFICADAMENTE LA COMPLEJIDAD DEL ALGORITMO

	**/

int numImparColgantes_aux(Arbin<int> a,int suma_ancestros,int & descentienes) {
	if (a.esVacio()) {//Caso base
		descentienes = 0;
		return 0; //No hay valor para los descendientes
	}
	else {
		
		int n_impar_colgantes = 0;
		int izq_descendientes, der_descendientes, numImparColgantes_der, numImparColgantes_izq;

		if (a.raiz() % 2 != 0) {
			suma_ancestros = suma_ancestros + a.raiz();
		}

		numImparColgantes_izq=numImparColgantes_aux(a.hijoIz(),suma_ancestros,izq_descendientes);
		numImparColgantes_der = numImparColgantes_aux(a.hijoDer(), suma_ancestros,der_descendientes);

		if (a.raiz() % 2 != 0) {
			suma_ancestros = suma_ancestros - a.raiz();
		}

		descentienes =  izq_descendientes + der_descendientes;

		
		cout << "Para el nodo: " << a.raiz() << "los ancestros son: " << suma_ancestros << " y descendientes: " << descentienes << endl;

		if (descentienes > suma_ancestros) {
			
			n_impar_colgantes=1;
		}
		if (a.raiz() % 2 == 0)descentienes += a.raiz();

		return n_impar_colgantes + numImparColgantes_izq + numImparColgantes_der;

	}

}

int numImparColgantes(Arbin<int> a) {
	// IMPLEMENTA AQUÍ EL SUBPROGRAMA
	int suma_ancestros = 0;
	int descendientes;
	return numImparColgantes_aux(a, suma_ancestros,descendientes);
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