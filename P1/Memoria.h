/*
Número de grupo: D26

	PRIETO REMACHA,DANIEL
	MAGPALI PESCADOR, MARÍA VICTORIA
	
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
		this->cap = capacidad;
		this->nrOfEl = 0;
		this->arr = new T*[this->cap];
		
		initialize();

	}

	void initialize(){
		for (int i = 0; i < cap; i++)
		{
			this->arr[i] = nullptr;
		}
	}

	/**
	 * Devuelve el valor almacenado en la celda 'd'.
	 * Si 'd' está fuera de rango, levanta EDireccionInvalida.
	 * Si la celda 'd' no está inicializada, levanta ECeldaSinInicializar.
	 */
	const T& valor(unsigned int d) const {
		// A implementar
		if (d<0 || d>=this->cap)throw EDireccionInvalida();
		if (!inicializada(d)) throw ECeldaSinInicializar();
		return *this->arr[d];
	}

	/**
	 * Almacena 'v' en la celda 'd'.
	 * Si 'd' está fuera de rango, levanta EDireccionInvalida.
	 */
	void almacena(unsigned  d, const T& v) {
		// A implementar
		if (d<0 || d>=this->cap)throw EDireccionInvalida();
		this->arr[d] = new T(v);
		nrOfEl++;
	}

	/**
	 * Devuelve 'true' si la celda 'd' está inicializada.
	 * En otro caso devuelve 'false'.
	 * Si 'd' está fuera de rango, levanta EDireccionInvalida.
	 */
	bool inicializada(unsigned int d) const {
		// A implementar 
		if (d<0 || d>=this->cap)throw EDireccionInvalida();
		if (arr[d] == nullptr)return false;
		else return true;
	}

	/* Implementar el resto de operaciones y métodos necesarios
	   para que la implementación funcione */

private:
	/* Declarar los campos necesarios para representar los
	   valores de este TAD, así como las operaciones auxiliares
	   que se consideren oportunas */

	int cap;
	int nrOfEl;
	T **arr;
};


#endif


