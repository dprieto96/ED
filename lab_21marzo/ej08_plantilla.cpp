#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/**
SUBPROGRAMA PARA CONSTRUIR UN ARBOL DE ENTEROS A PARTIR DE SU REPRESENTACIÓN EN UNA LÍNEA DE ENTRADA
Los árboles se representan de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con
	v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
	con I la codificación del hijo izquierdo,
	v el valor de la raíz, y D la codificación
	del hijo derecho.

Ejemplos:
#  --> arbol vacío
[1] --> arbol hoja
([1]2[3])  --> arbol con raiz 2, hijo derecho 3 e hijo izdo 1
([1]2([3]4#)) --> arbol con raiz 2, hijo derecho (raíz = 4; sin hijo derecho; hijo izdo 3) e hijo izdo 1

**/

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



// 8.I

void existeCamino_aux(const Arbin<int>& a, int &suma, int valor_dado,bool & encontrado) {

	if (a.esVacio()) {
		if (suma == valor_dado)encontrado =true;
	}
	else {
		suma += a.raiz();
		existeCamino_aux(a.hijoIz(),suma,valor_dado,encontrado);
		existeCamino_aux(a.hijoDer(), suma, valor_dado,encontrado);

		cout << "PARA EL NODO: " << a.raiz() << " la suma es: " << suma << endl;
		
		suma -= a.raiz();
	
	}
}

bool existeCamino(const Arbin<int>& a, int suma) {
	
	int suma_nodos=0;
	bool encontrado = false;
	existeCamino_aux(a, suma_nodos, suma, encontrado);
	
	return encontrado;
}


// 8.II

void numCaminos(const Arbin<int>& a, int suma, int& nCaminos) {
	
}


// main para 8.I
int main() {
	Arbin<int> arbol;
	int suma = 3;  // MODIFICAR PARA HACER PRUEBAS
	while (cin.peek() != EOF) {
		Arbin<int> a = lee_arbol(cin);
		if (existeCamino(a, suma)) 
			cout << "SI" << endl;
		else
			cout << "NO" << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}

// main para 8.II
//int main() {
//	Arbin<int> arbol;
//	int suma = 3;  // MODIFICAR PARA HACER PRUEBAS
//	int numC;
//	while (cin.peek() != EOF) {
//		Arbin<int> a = lee_arbol(cin);
//		numCaminos(a, suma, numC);
//		cout << numC << endl;
//		string resto_linea;
//		getline(cin, resto_linea);
//	}
//	return 0;
//}
