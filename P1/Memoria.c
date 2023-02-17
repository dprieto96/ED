/*
Número de grupo: 

Nombre y apellidos de los autores de la práctica (si alguno de los miembros del grupo
no hay realizado la práctica, no debe incluirse su nombre):


*/

using namespace std;

#ifndef _MEMORIA_H_
#define _MEMORIA_H_

/// Excepción de direccion invalida
class EDireccionInvalida {};

/// Excepción de celda sin inicializar
class ECeldaSinInicializar {};

template<class T>
class Memoria {

public:
	/**
	 * crea una memoria con 'capacidad' celdas.
	 */
	Memoria(unsigned int capacidad) {
		// A implementar
		_tam = capacidad;
		_nElems = 0;
		_vector = new ptr [_tam];

		for (int i = 0; i < _tam; i++) ptr[i] = nullptr;

	}

	/**
	 * Devuelve el valor almacenado en la celda 'd'.
	 * Si 'd' está fuera de rango, levanta EDireccionInvalida.
	 * Si la celda 'd' no está inicializada, levanta ECeldaSinInicializar.
	 */
	const T& valor(unsigned int d) const {
		// A implementar
		if (d<0 || d>_nElems)throw EDireccionInvalida();
		if (_vector[d] == nullptr) throw ECeldaSinInicializar();
		return _vector[d];
	}

	/**
	 * Almacena 'v' en la celda 'd'.
	 * Si 'd' está fuera de rango, levanta EDireccionInvalida.
	 */
	void almacena(unsigned  d, const T& v) {
		// A implementar
		if (d<0 || d>_nElems)throw EDireccionInvalida();
		_vector[d] = v;
		_nElems++;
	}

	/**
	 * Devuelve 'true' si la celda 'd' está inicializada.
	 * En otro caso devuelve 'false'.
	 * Si 'd' está fuera de rango, levanta EDireccionInvalida.
	 */
	bool inicializada(unsigned int d) const {
		// A implementar 
		if (d<0 || d>_nElems)throw EDireccionInvalida();
		if (_vector[d] == nullptr)return false;
		else return true;
	}
	
	/* Implementar el resto de operaciones y métodos necesarios
	   para que la implementación funcione */

private:
    /* Declarar los campos necesarios para representar los
	   valores de este TAD, así como las operaciones auxiliares
	   que se consideren oportunas */

	int _tam;
	int _nElems;

	T** _vector;

};


#endif


