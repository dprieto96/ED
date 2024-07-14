// NOMBRE Y APELLIDOS:
// USUARIO DEL JUEZ:


#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;


int num_correctivos_aux(const Arbin<int>& a, int& sumatorio, int& nodos) {
	if (a.esVacio()) {//CB
		sumatorio = 0;
		nodos = 0;
		return 0;
	}

	else {
		int sumatorio_izq, sumatorio_der;
		int nodos_izq, nodos_der;
		int correctivos = 0;

		int correctivos_izq=num_correctivos_aux(a.hijoIz(),sumatorio_izq,nodos_izq);
		int correctivos_der = num_correctivos_aux(a.hijoDer(),sumatorio_der,nodos_der);

		if (!a.hijoDer().esVacio() && a.raiz() == sumatorio_der - nodos_izq) correctivos = 1;

		sumatorio = sumatorio_izq + sumatorio_der + a.raiz();
		nodos = nodos_izq + nodos_der + 1;

		return correctivos + correctivos_izq + correctivos_der;
	
	}

}


/*
Determinar justificadamente la complejidad del algoritmo:

*/
int num_correctivos(const Arbin<int>& a) {
	// A IMPLEMENTAR
	int sum, nodos;
	return num_correctivos_aux(a,sum,nodos);
	
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
