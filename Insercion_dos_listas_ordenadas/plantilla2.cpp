// Problema El regreso de los enanos

// IMPORTANTE

// Nombre y apellidos del alumno
// Usuario del juez de clase
// Usuario que has utilizado en esta prueba


#include <iostream>
#include <fstream>
#include <string>
#include "bintree_eda.h"

// Explicación del algoritmo



// Coste de la función. Para justificar el coste se debe indicar la recurrencia utilizada para calcularlo. Indicar el coste para árboles equilibrados y para árboles degenerados




// Aqui las funciones del alumno

int enanos_sobreviven(bintree<std::string> const& a, int& enanos) {
    if (a.empty()) {
       // enanos = 1;
       return 1; // Si el árbol está vacío, se considera que hay un enano que sobrevive.
    }
    else {
        int enanos_izq=0 , enanos_der=0;

        int enanos_sobreviven_izquierda = enanos_sobreviven(a.left(), enanos_izq);
        int enanos_sobreviven_derecha = enanos_sobreviven(a.right(), enanos_der);

        //enanos = enanos_izq + enanos_der;

        // Si el nodo actual es "Sauron", todos los enanos mueren en esta rama.
       
        return enanos_sobreviven_izquierda + enanos_sobreviven_derecha;
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    std::string vacio = ".";
    bintree<std::string> arbol = leerArbol(vacio);
    // LLamada a la función que resuelve el problema
    int enanos;
    int a=enanos_sobreviven(arbol, enanos);
    

    // Escribir los resultados
    
    
    
    
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos; std::cin >> numCasos; std::cin.ignore();
    for (int i = 0; i < numCasos; ++i) {resuelveCaso();}
        
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

