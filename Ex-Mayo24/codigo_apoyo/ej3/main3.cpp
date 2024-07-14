// NO MODIFIQUES NADA DE LO QUE APARECE EN ESTE FICHERO

#include "RedPelis.h"

#include <iostream>
#include <string>
using namespace std;


void registra_usuario(RedPelis& red_pelis) {
	tUsuario usuario;
	cin >> usuario;
	tTarjeta tarjeta;
	cin >> tarjeta;
	try {
		red_pelis.registra_usuario(usuario, tarjeta);
		cout << "OK" << endl;
	}
	catch (EUsuarioDuplicado) {
		cout << "ERROR_USUARIO_DUPLICADO" << endl;
   	}
}

void registra_pelicula(RedPelis& red_pelis) {
	tPelicula pelicula;
	tRegistro registro;
	cin >> pelicula >> registro;
	try {
		red_pelis.registra_pelicula(pelicula,registro);
		cout << "OK" << endl;
	}
	catch (EPeliculaDuplicada) {
		cout << "ERROR_PELICULA_DUPLICADA" << endl;
	}
}

void mira(RedPelis& red_pelis) {
	tUsuario usuario;
	cin >> usuario;
	tPelicula pelicula;
	cin >> pelicula;
	int minutos;
	cin >> minutos;
	try {
		red_pelis.mira(usuario,pelicula,minutos);
		cout << "OK" << endl;
	}
	catch (EPeliculaNoExiste) {
		cout << "ERROR_MIRA" << endl;
	}
	catch (EUsuarioNoExiste) {
		cout << "ERROR_MIRA" << endl;
	}
}

void factura(const RedPelis& red_pelis) {
	tUsuario usuario;
	cin >> usuario;
	try {
		InfoFactura factura = red_pelis.factura(usuario);
		cout << "usuario:" << factura.usuario << " tarjeta:" << factura.tarjeta << " total:"
		     << factura.cantidad << endl;
	}
	catch (EUsuarioNoExiste) {
		cout << "ERROR_USUARIO_NO_EXISTE" << endl;
	}
}

void hits(const RedPelis& red_pelis) {
	int k;
	cin >> k;
	Lista<tPelicula> hits = red_pelis.hits(k);
	for (int i = 0; i < hits.longitud(); i++) {
		cout << hits.elem(i) << " ";
	}
	cout << endl;
}


int main() {
	int cuota, extra;
	cin >> cuota >> extra;
	RedPelis red_pelis(cuota,extra);
	string comando;

	while (cin >> comando) {
		if (comando == "registra_usuario") registra_usuario(red_pelis);
		else if (comando == "registra_pelicula") registra_pelicula(red_pelis);
		else if (comando == "mira") mira(red_pelis);
		else if (comando == "factura") factura(red_pelis);
		else if (comando == "hits") hits(red_pelis);
	}
	return 0;
}