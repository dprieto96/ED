
// NOMBRE Y APELLIDOS: David Ferreras Díaz
// USUARIO DEL JUEZ:


#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;

/*
Determinar justificadamente la complejidad del algoritmo:
	La complejidad de la función es O(n) donde n es el número de nodos que presenta el árbol ya que para saber la cantidad de nodos correctivos hay que mirar todos una vez.
*/
int num_correctivos_aux(const Arbin<int>& a, int& suma, int& n_nodos) {
	if (a.esVacio()) {
		suma = 0;
		n_nodos = 0;
		return 0;
	}
	else {
		int suma_iz, n_nodos_iz, suma_der, n_nodos_der;
		int nodos_correctivos = 0;

		// Recursivamente obtener la suma y el número de nodos de los subárboles izquierdo y derecho
		int correctivos_iz = num_correctivos_aux(a.hijoIz(), suma_iz, n_nodos_iz);
		int correctivos_der = num_correctivos_aux(a.hijoDer(), suma_der, n_nodos_der);

		// Calcular suma y número de nodos del subárbol actual
		suma = a.raiz() + suma_iz + suma_der;
		n_nodos = 1 + n_nodos_iz + n_nodos_der;

		// Verificar si el nodo actual es correctivo
		if (!a.hijoDer().esVacio() && a.raiz() == (suma_der - n_nodos_iz)) {
			nodos_correctivos = 1;
		}

		return nodos_correctivos + correctivos_iz + correctivos_der;
	}
}

int num_correctivos(const Arbin<int>& a) {
	int suma = 0, n_nodos = 0;
	return num_correctivos_aux(a, suma, n_nodos);
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
		Arbin<int> a = lee_arbol(cin);
		cout << num_correctivos(a) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}


