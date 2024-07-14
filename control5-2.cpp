// NOMBRE Y APELLIDOS INTEGRANTE 1:
// NOMBRE Y APELLIDOS INTEGRANTE 2:
// USUARIO DEL JUEZ:


#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;



/** INDICA AQU� JUSTIFICADAMENTE LA COMPLEJIDAD DEL ALGORITMO

	**/

bool es_impar(int a) {
	bool impar = false;
	if (a % 2 == 0)impar = true;

	return impar;
}


void n_impar_colgantes(Arbin<int> a,int sum,int n_impar) {

	//CB
	if (a.esVacio()) {
		return;
	}

	else {
		


	}
	

}

int numImparColgantes(Arbin<int> a) {
	// IMPLEMENTA AQU� EL SUBPROGRAMA
	if (a.esVacio() )return 0;

	


	return 0;
}



/*
Formato de la entrada
=====================
El formato de cada caso es como sigue:
- Cada l�nea contiene la descripci�n de un �rbol
- Para describir los �rboles se sigue el siguiente convenio:
* Los �rboles vac�os se escriben como #
* Los �rboles simples se escriben como [c], con c el contenido del nodo.
* Los �rboles compuestos se escriben como (IcD), donde:  (i) I es el hijo izquierdo; (ii) c es el contenido de la ra�z; (iii) D es el hijo derecho.


Formato de la salida
====================
Para cada caso el programa imprime el n�mero de nodos impar-colgantes.


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