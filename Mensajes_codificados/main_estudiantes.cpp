#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
#include "pila.h"
// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS


bool es_vocal(char a) {
	if (a == 'a' || a == 'A')return true;
	else if (a == 'e' || a == 'E')return true;
	else if (a == 'i' || a == 'I')return true;
	else if (a == 'o' || a == 'O')return true;
	else if (a == 'u' || a == 'U')return true;
	else return false;

}


// Reemplaza cada secuencia de caracteres no vocales consecutivos 
// por su inversa. 'mensaje' se deberá modificar con el resultado
// de realizar dicho proceso. 
void codifica(Lista<char> &mensaje) {
	// A IMPLEMENTAR
	Lista <char>::Iterator iterador=mensaje.begin();
	Lista <char>::Iterator codificado = mensaje.begin();

	Pila<char> pila;

	while (iterador!= mensaje.end()) {//Recorro toda la lista
	
		if (es_vocal(iterador.elem())) {
			
			while (!pila.esVacia()) {
				codificado.set(pila.cima());
				pila.desapila();
				codificado.next();
			}
			codificado.next();
			
		}
		else {
			pila.apila(iterador.elem());

		}
		
		iterador.next();
	}

	while (!pila.esVacia()) {
		codificado.set(pila.cima());
		pila.desapila();
		codificado.next();

	}

}

 
// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	Lista<char>::ConstIterator it = l.cbegin();
	while (it != l.cend()) {
		cout << it.elem();
		it.next();
	}
	cout << endl;
}


  // Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for(unsigned int i=0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);  
}

int main() {
	string linea;
	while(getline(cin,linea)) {
	   Lista<char> mensaje;
	   construyeMensaje(linea,mensaje);
       codifica(mensaje);
	   imprime(mensaje);
	}
	return 0;
}	
