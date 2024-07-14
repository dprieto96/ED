// INDICA AQUÍ LOS DATOS DEL GRUPO
// NOMBRE Y APELLIDOS DEL PRIMER INTEGRANTE:
// NOMBRE Y APELLIDOS DEL SEGUNDO INTEGRANTE:
// Nº DE GRUPO:


#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;

int hojas_profundas(const Arbin<int>& a, unsigned int k, unsigned int profundidad) {
	if (a.hijoIz().esVacio() && a.hijoDer().esVacio()) { //Si llego a este punto significa que estoy abajo de la hoja
		profundidad++;
		
		if (profundidad > k) {
			return 1;
		}
		else return 0;
	}

	else {//Sigo recorriendo el árbol
		profundidad++;

		int profundas_izq = hojas_profundas(a.hijoIz(), k, profundidad);
		int profundas_der = hojas_profundas(a.hijoDer(), k, profundidad);

		profundidad--;
			
		return profundas_izq + profundas_der;
	}

	
}


/**
  COMPLEJIDAD: Explica aquí justificadamente cuál es la complejidad de 
               esta función
			   ***A COMPLETAR***
*/
unsigned int numero_hojas_mas_profundas_que(const Arbin<int>& a, unsigned int k) {
	// A IMPLEMENTAR
	unsigned int profundidad = 0;//Lo inicializamos a 1, para dar a la ráiz el valor 1
	return hojas_profundas(a, k, profundidad);
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



/**
La entrada al programa consiste de líneas formadas por:
(1) Un árbol de enteros
(2) El valor de k
Los árboles se codifican de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con  
    v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
    con I la codificación del hijo izquierdo,
	v el valor de la raíz, y D la codificación
	del hijo derecho.
Para cada línea leida, escribe en la salida estándar
el número de hojas que están a profundidad mayor que k

	
Ejemplo de entrada:

([2]1([4]3[5])) 0
([2]1([4]3[5])) 1
([2]1([4]3[5])) 2
([2]1([4]3[5])) 3
([2]1([4]3[5])) 4
([2]1([4]3[5])) 100

Salida asociada:

3
3
2
0
0
0

*/


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		Arbin<int> a = lee_arbol(cin);
		int k;
		cin >> k;
		cout << numero_hojas_mas_profundas_que(a,k) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}
