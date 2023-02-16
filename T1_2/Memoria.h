/*
NOMBRE Y APELLIDOS DE LOS COMPONENTES DEL GRUPO QUE HAN 
REALIZADO LA PRÁCTICA:

	DANIEL PRIETO REMACHA


(si algún componente no ha realizado la práctica,
no debe aparecer)

*/
using namespace std;

#ifndef _MEMORIA_H_
#define _MEMORIA_H_

/// Excepción de direccion invalida
class DireccionInvalida {};


template<class T>
class Memoria {
public:
	/**
	 * crea una memoria
	 * @param defecto valor por defecto de las celdas
	 */
	Memoria(const T& defecto) {
		 // A IMPLEMENTAR
		_tam = TAM_INICIAL;
		_nElems = 0;
		_vector = new T[TAM_INICIAL];

		_defecto = new T(defecto);
		iniciciaDefault();
		

	}

	void iniciciaDefault() {
		for (int i = 0; i < _tam; i++) {
			_vector[i] = _defecto[0];
		}
	}


	/**
	 * Devuelve el contenido de una celda
	 * @param d dirección de la celda
	 */
	const T& fetch(int d) const {
		 // A IMPLEMENTAR
		if (d < 0) throw DireccionInvalida();
		if (d >= _tam) return _defecto[0];
		return _vector[d];
	}

	/**
	 * Almacena un valor en una celda
	 * @param d dirección de la celda
	 * @param v valor a almacenar
	 */
	void load(int d, const T& v) {
		 // A IMPLEMENTAR
		if (d < 0) throw DireccionInvalida();
		if (d >= _tam) {
			int oldtam=_tam;
			
			_nElems=d+1; // aumentamos el contador
				T* viejo = _vector;
				_tam =d+1 ; //(*)
				_vector = new T[_tam];
				for (unsigned int i = 0; i < _nElems; ++i)
					_vector[i] = viejo[i];
				for (oldtam; oldtam < _tam;oldtam++) {
					_vector[oldtam] = _defecto[0];
				}
				delete[]viejo;
		
		}
		_vector[d] = v;
		_nElems++;
	}
	
	
     // DEBEN INCLUIRSE E IMPLEMENTARSE 
	 // LAS OPERACIONES ADICIONALES
	 // NECESARIAS PARA GARANTIZAR EL CORRECTO
	 // FUNCIONAMIENTO DEL TAD
	

private:
  // INCLUIR DETALLES DE REPRESENTACION Y OPERACIONES AUXILIARES
	static const int TAM_INICIAL = 2;

	int _tam;
	int _nElems;

	T* _vector;	
	T* _defecto;
};


#endif


