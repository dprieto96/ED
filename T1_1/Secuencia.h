#ifndef _SECUENCIA_H_
#define _SECUENCIA_H_

/// Excepción de elemento inexistente
class ElementoInvalido {};


template<class T>
class Secuencia {
public:
	Secuencia() {
		// A IMPLEMENTAR
		v = new T[TAM_INICIAL]; tam = TAM_INICIAL; numElems = 0;
	}


	void pon(const T& e) {
		// A IMPLEMENTAR
		v[numElems] = e; // colocamos en 1er hueco
		numElems++; // aumentamos el contador
		if (numElems == tam) { // ampliamos el vector si lo hemos llenado
			T* viejo = v;
			tam *= 2; //(*)
			v = new T[tam];
			for (unsigned int i = 0; i < numElems; ++i)
				v[i] = viejo[i];
			delete[]viejo;
		}

		
	}

	const T& elem(int i) {
		// A IMPLEMENTAR
		if (i<0 || i>numElems)throw ElementoInvalido();
		 return v[i];

	}

	int num_elems() const {
		// A IMPLEMENTAR
		return numElems;
	}

     // DEBEN INCLUIRSE E IMPLEMENTARSE 
	 // LAS OPERACIONES ADICIONALES
	 // NECESARIAS PARA GARANTIZAR EL CORRECTO
	 // FUNCIONAMIENTO DEL TAD


private:
  // INCLUIR DETALLES DE REPRESENTACION Y OPERACIONES AUXILIARES
	const static int TAM_INICIAL = 2;
	int tam;
	unsigned int numElems;
	T *v;
};


#endif


