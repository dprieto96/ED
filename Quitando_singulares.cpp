/**
Este programa lee �rboles de la entrada est�ndar,
codificados de acuerdo con las siguientes reglas:
(1) El �rbol vac�o se codifica como #
(2) Los �rboles simples se codifican como [v], con
	v el valor del nodo
(3) Los �rboles complejos se codifican como (IvD),
	con I la codificaci�n del hijo izquierdo,
	v el valor de la ra�z, y D la codificaci�n
	del hijo derecho.
Para cada �rbol le�do, escribe en la salida est�ndar
el n�mero de nodos singulares de dicho �rbol.

Algunos casos representativos:

#
[0]
[5]
(([4]3[-3])1[-4])

-El primero representa el �rbol vac�o. Al no tener nodos,
un �rbol vac�o tiene 0 nodos sigulares.
-El segundo representa un �rbol con un �nico nodo, cuyo valor
es 0. Dicho nodo es singular, ya que: (i) como no tiene
ascestros, la suma de los ancestros es 0, (ii) como no
tiene descendientes, la suma de los descendientes es 0.
-El tercero representa otro �rbol con un �nico nodo, cuyo
valor es 5. Por la misma raz�n que en el segundo ejemplo,
este nodo es singular.
-El cuarto representa el siguiente �rbol:

		   1
		  /  \
		  3  -4
		 / \
		4  -3

Este �rbol tiene 2 nodos sigulares: la ra�z, y la ra�z del hijo
izquierdo.

Por tanto, la salida del programa para estos casos ser�:

0
1
1
2

*/
#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/**
  COMPLEJIDAD: Explica aqu� justificadamente cu�l es la complejidad de
			   esta funci�n
			   ***A COMPLETAR***
*/
unsigned int nodos_singulares(const Arbin<int>& a, int &ancestros, int &descendientes) {

	if (a.esVacio()) {
		descendientes = 0;
		
		return 0;
	}
	else {
		int desc_izq, desc_der;
		int n_singulares = 0;

		ancestros+=a.raiz();

		int n_singulares_izq = nodos_singulares(a.hijoIz(), ancestros, desc_izq);
		int n_singulares_der = nodos_singulares(a.hijoDer(), ancestros, desc_der);

		ancestros-=a.raiz();
		descendientes = desc_izq + desc_der;
		//cout << "Para el nodo: " << a.raiz() << "sus descendientes son: " << descendientes
		//	<< " y ancestros: " << ancestros << endl;


		if (ancestros == descendientes) {
			n_singulares = 1;
		}
		else {
			n_singulares = 0;
		}

		descendientes += a.raiz();


		return n_singulares + n_singulares_izq + n_singulares_der;
		
	}


}

unsigned int numero_singulares(const Arbin<int>& a) {
	// A IMPLEMENTAR
	int ancestros = 0;
	int descendientes;

	return nodos_singulares(a,ancestros, descendientes);

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
	while (cin.peek() != EOF) {
		cout << numero_singulares(lee_arbol(cin));
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}
