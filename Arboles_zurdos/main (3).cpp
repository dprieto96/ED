/*
	JAVIER GÓMEZ MORALEDA
	MARIO ALCOLEA ALCOLEA
*/


#include "Arbin.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Implementar aquí la funciones auxiliares que se consideren necesarias

/*
	Función auxiliar que calcula la suma de todas las ramas de un árbol, así como su altura, es decir, la rama más "larga"

	Habíamos considerado pasar por parámetros por referencia las alturas, pero nos ha parecido más cómodo que la función
	devuelva la altura máxima del árbol a.
*/

void es_zudo_aux(Arbin<int> a, int& nivel,int& suma,int&altura, bool &zurdo) {
	
	if (a.esVacio()) {
		suma = 0;

		zurdo= false;
	}
	else {
		nivel++;
		if (nivel > altura)altura = nivel;
		bool zurdo_izq, zurdo_der;
		int suma_izq, suma_der;
		if (!zurdo) {
			es_zudo_aux(a.hijoIz(), nivel, suma_izq, altura,zurdo);
			es_zudo_aux(a.hijoDer(), nivel, suma_der, altura,zurdo);

		}
		

		nivel--;

		

		if (nivel != 0) {
			suma = suma_izq + suma_der + a.raiz();
		}

		else {
			//cout << "Nodo:" << a.raiz() << " ALTURA: " << altura << " IZQ: " << suma_izq << " DER: " << suma_der << endl;
			if ((suma_izq - suma_der) >= altura - 1) zurdo= true;
		}

		
	}


}
// Función principal a implementar, que determina si
// el árbol dado como entrada es o no zurdo (devuelve true si es
// zurdo, false en otro caso)
bool es_zurdo(Arbin<int> a) {

	int altura = 0;
	int nivel = 0;
	int suma;
	bool zurdo=false;

	 es_zudo_aux(a, nivel,suma,altura,zurdo);

	 return zurdo;

}


//-----------------------------------------------------------------------
// Código que se encarga de la e/s: no tocar
//

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


/**
La entrada al programa consiste de líneas formadas por árboles de enteros
codificados de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con  
    v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
    con I la codificación del hijo izquierdo,
	v el valor de la raíz, y D la codificación
	del hijo derecho.
Para cada línea leida, escribe en la salida estádar
ZURDO si el árbol es zurdo, y NO_ZURDO en otro caso

Ejemplo de entrada:
#
[5]
([17]5([2]1[3]))
(([2]1[3])5[17])

Salida asociada:
NO_ZURDO
ZURDO
ZURDO
NO_ZURDO


*/

int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		Arbin<int> a = lee_arbol(cin);
		string resto_linea;
		getline(cin, resto_linea);
		if (es_zurdo(a)) cout << "ZURDO";
		else cout << "NO_ZURDO";
		cout << endl;
	}
	return 0;
}
