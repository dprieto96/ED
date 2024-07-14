#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool es_interseccion(char a) {
    
    if (a == 'X')return true;
    else return false;
}

int tiempoAyudaAux(const Arbin<char> a, int& distancia)
{
    if (a.esVacio()) {
        return 0;
    }
    else {
        distancia++;

        int tiempo_total=0;
        int tiempo_izq = tiempoAyudaAux(a.hijoIz(),distancia);
        int tiempo_der = tiempoAyudaAux(a.hijoDer(), distancia);
        
        distancia--;

        if (es_interseccion(a.raiz())) {
            //cout << "La profundidad es: " << tiempo_total << " IZQ " << tiempo_izq <<"DER"<<tiempo_der<< endl;
            tiempo_total += distancia;
        }
        

        

        return tiempo_total+tiempo_izq+tiempo_der;

    }

}

int tiempoAyuda(const Arbin<char> &a)
{
    // A IMPLEMENTAR
    int distancia = 0;
    return 2 * (tiempoAyudaAux(a, distancia));

    
}

Arbin<char> leeArbol(istream &in)
{
    char c;
    in >> c;
    switch (c)
    {
    case '#':
        return Arbin<char>();
    case '[':
    {
        char raiz;
        in >> raiz;
        in >> c;
        return Arbin<char>(raiz);
    }
    case '(':
    {
        Arbin<char> iz = leeArbol(in);
        char raiz;
        in >> raiz;
        Arbin<char> dr = leeArbol(in);
        in >> c;
        return Arbin<char>(iz, raiz, dr);
    }
    default:
        return Arbin<char>();
    }
}

int main()
{
    Arbin<char> falda;
    while (cin.peek() != EOF)
    {
        cout << tiempoAyuda(leeArbol(cin));
        string restoLinea;
        getline(cin, restoLinea);
        if (cin.peek() != EOF)
            cout << endl;
    }
    return 0;
}
