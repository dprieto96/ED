// NOMBRE Y APELLIDOS:
// USUARIO DEL JUEZ:


#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


/*
Determinar justificadamente la complejidad del algoritmo:

*/
int num_correctivos_aux(const Arbin<int>& a, int &suma, int &nodos) {
	if (a.esVacio()) {
		nodos = 0;
		suma = 0;
		return 0;
	}
	else {

		int suma_izq, suma_der;
		int nodo_izq, nodo_der;
		int correctivos = 0;

		int izq_correctivos = num_correctivos_aux(a.hijoIz(), suma_izq, nodo_izq);
		int der_correctivos = num_correctivos_aux(a.hijoDer(), suma_der, nodo_der);

		//cout << "Para el nodo: " << a.raiz() << "SUMA DER: " << suma_der << " # IZQ: " << nodo_izq << endl;

		if ((suma_der - nodo_izq )== a.raiz())correctivos = 1;

		suma = a.raiz()+suma_izq + suma_der;
		nodos = 1+nodo_izq + nodo_der;

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
