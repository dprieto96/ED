// E24: Manuel Guerrero Moñús

/*

Complejidad: O(n) ya que hay que recorrer los n nodos del arbol binario.

*/

#include<algorithm>
#include <fstream>
#include <iostream>

#include "Arbin.h"



void resuelveCaso() {

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos;
	std::cin >> casos;

	for (; casos > 0; --casos)

		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	getchar();
#endif

	return 0;

}
