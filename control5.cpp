// NOMBRE Y APELLIDOS INTEGRANTE 1:Jos� Mar�a de la Fuente Bah�n
// NOMBRE Y APELLIDOS INTEGRANTE 2:Daniel Prieto Remacha 
// USUARIO DEL JUEZ: B09


#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;



/** INDICA AQU� JUSTIFICADAMENTE LA COMPLEJIDAD DEL ALGORITMO

Dado que el algoritmo realiza un recorrido completo del �rbol binario una sola vez,
su complejidad temporal depende directamente del n�mero de nodos en el �rbol.
Por lo tanto, el coste del algoritmo es O(n), donde n es el n�mero de nodos en el �rbol.
	**/

    
int contarImparColgantes(const Arbin<int>& arbol, int& sumDes, int& sumAnt, int& sol) {
    int sumDesDer = 0, sumDesIz = 0; // Variables para almacenar los descendientes por izquierda y derecha

    // Caso base: si el nodo actual es una hoja
    if (arbol.hijoIz().esVacio() && arbol.hijoDer().esVacio()) {
        return arbol.raiz(); // Devolvemos la ra�z como descendiente del nodo anterior
    }
    else {
        // Actualizamos la suma de ancestros con el valor del nodo actual
        sumAnt += arbol.raiz();

        // Tratamos los descendientes por la izquierda si existen
        if (!arbol.hijoIz().esVacio()) {
            sumDesIz = contarImparColgantes(arbol.hijoIz(), sumDes, sumAnt, sol);
        }
        // Tratamos los descendientes por la derecha si existen
        if (!arbol.hijoDer().esVacio()) {
            sumDesDer = contarImparColgantes(arbol.hijoDer(), sumDes, sumAnt, sol);
        }

        // Si la suma de los descendientes por la derecha es impar, la agregamos a la suma total
        if (sumDesDer % 2 != 0) {
            sumDes += sumDesDer;
        }
        // Si la suma de los descendientes por la izquierda es impar, la agregamos a la suma total
        if (sumDesIz % 2 != 0) {
            sumDes += sumDesIz;
        }

        // Restauramos la suma de ancestros al valor antes de procesar el nodo actual
        sumAnt -= arbol.raiz();

        // Si la suma de los descendientes es mayor que la suma de los ancestros, incrementamos la soluci�n
        if (sumDes > sumAnt) {
            sol++;
        }

        // Devolvemos la suma de los descendientes que ya ten�amos m�s el valor del nodo actual
        return sumDes + arbol.raiz();
    }
}

// Funci�n para calcular el n�mero de nodos impares colgantes en un �rbol binario
// Retorna el n�mero de nodos con valor impar colgantes en el �rbol
unsigned int numImparColgantes(const Arbin<int>& a) {
    int sumAnc = 0; // Variable acumuladora de los nodos ancestros
    int sumDes = 0; // Variable acumuladora de los nodos descendientes
    int sol = 0;    // Variable para almacenar la soluci�n

    // Si el �rbol no es vac�o, llamamos a la funci�n para contar los nodos impares colgantes
    if (!a.esVacio()) {
        contarImparColgantes(a, sumDes, sumAnc, sol);
    }

    return sol;
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