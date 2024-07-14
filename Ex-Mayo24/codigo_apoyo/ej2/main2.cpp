/*
NOMBRE Y APELLIDOS:

USUARIO JUEZ ASIGNADO PARA EL EXAMEN:

*/

#include "Arbin.h"
#include <iostream>
#include <string>
using namespace std;


bool es_vocal(char a) {
	if (a == 'a' || a == 'A') return true;
	else if (a == 'e' || a == 'E') return true;
	else if (a == 'i' || a == 'I') return true;
	else if (a == 'o' || a == 'O') return true;
	else if (a == 'u' || a == 'U') return true;
	else return false;
}


void max_vocalizado_aux(const Arbin<char>& a, int &vocalizado, int &profundidad, int &best_vocalizado, int &best_profundidad,char &mejor) {
	if (!a.esVacio()) {
	
		
		if (es_vocal(a.raiz()))vocalizado++;
		profundidad++;

		
		if (vocalizado >= best_vocalizado) {
			if (profundidad > best_profundidad) {
				best_vocalizado = vocalizado;
				best_profundidad = profundidad;

				mejor = a.raiz();
				//cout << "NODO: " << mejor << " VOC " << vocalizado << " PROF" << profundidad << endl;
			}
		}

		max_vocalizado_aux(a.hijoIz(), vocalizado, profundidad, best_vocalizado,best_profundidad,mejor);
		max_vocalizado_aux(a.hijoDer(), vocalizado, profundidad, best_vocalizado, best_profundidad,mejor);


		if (es_vocal(a.raiz()))vocalizado--;
		profundidad--;

		
	}
	
}



/* DETERMINACION JUSTIFICADA DE LA COMPLEJIDAD:
	
	
	
*/
char max_vocalizado(const Arbin<char>& a) {
	// A IMPLEMENTAR
	int  best_vocalizado = 0, best_profundidad = 0;
	int vocalizado = 0, profundidad = 0;
	char mejor = '?';
	max_vocalizado_aux(a, vocalizado, profundidad, best_vocalizado, best_profundidad,mejor );
	return mejor;
}


/* A PARTIR DE AQUI NO MODIFICAR */

Arbin<char> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<char>();
	case '[': {
		char raiz;
		in >> raiz;
  		in >> c;
		return Arbin<char>(raiz);
	}
	case '(': {
		Arbin<char> iz = lee_arbol(in);
		char raiz;
		in >> raiz;
		Arbin<char> dr = lee_arbol(in);
		in >> c;
		return Arbin<char>(iz, raiz, dr);
	}
	default: return Arbin<char>();
	}
}

int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		Arbin<char> a = lee_arbol(cin);
		cout << max_vocalizado(a) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
    return 0;       
}