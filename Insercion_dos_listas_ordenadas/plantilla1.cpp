// Problema interseccion de dos listas ordenadas

// IMPORTANTE

// Nombre y apellidos del alumno
// Usuario del juez de clase
// Usuario que has utilizado en esta prueba


#include <iostream>               
#include <fstream>               

#include "deque_eda.h"


// Explicación del algoritmo empleado






class InterseccionListas : public deque<int> {
    using Nodo = deque<int>::Nodo;
public:
    void print(std::ostream& o = std::cout) const {
        // rellenar
        InterseccionListas lista_stdout;
        lista_stdout.copia(*this);
        for (int i = 0; i < this->size(); i++) {
            o << lista_stdout.front() << " ";
            lista_stdout.pop_front();
        }

    }
    
    void interseccion(InterseccionListas const& other) {
        // rellenar
        int tam_lista;
        InterseccionListas lista_aux;
        InterseccionListas lista_sol;
        lista_aux = other;
        
        if (this->size() > lista_aux.size()) tam_lista = this->size();
        else tam_lista = lista_aux.size();
        
        
        while(!this->empty() && !lista_aux.empty()){

            if (this->front() == lista_aux.front()) {
                lista_sol.push_back(this->front());
                this->pop_front();
            }
            else if (this->front()>lista_aux.front()) {
                lista_aux.push_back(lista_aux.front());
                lista_aux.pop_front();
            
            }

            else {
                
                this->pop_front();
            }

        }
        this->copia(lista_sol);
    }
};



/////////////////////////////////////////////////////////
// desde aquí NO se puede modificar nada

inline std::ostream& operator<<(std::ostream & o, InterseccionListas const& a) {
    a.print(o);
    return o;
}

InterseccionListas leerLista() {
    InterseccionListas lista;
    int n;
    std::cin >> n;
    while (n != 0) {
        lista.push_back(n);
        std::cin >> n;
    }
    return lista;
}

bool resuelveCaso() {
    InterseccionListas lista1 = leerLista();
    InterseccionListas lista2 = leerLista();
    lista1.interseccion(lista2);
    
    std::cout << lista1 << '\n';
    
    return true;
}


int main() {
    
#ifndef DOMJUDGE
    std::ifstream in("sample1.txt");
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
