#include "CarnetPorPuntos.h"


/**
Implementa aquí los métodos de las clases adicionales
*/

 
/**
Debes completar la implementación de las operaciones de CarnetPorPuntos,
y justificar la complejidad de las mismas.
*/ 

CarnetPorPuntos::CarnetPorPuntos() {}


/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::nuevo(const string& dni) {
	  // A IMPLEMENTAR
	if (diccionario_DNI.contiene(dni))throw EConductorDuplicado();
	diccionario_DNI.inserta(dni,InfoConductor(15,dni));
	
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::quitar(const string& dni, unsigned int puntos) {
	  // A IMPLEMENTAR
	if (!diccionario_DNI.contiene(dni))throw EConductorNoExiste();
	diccionario_DNI.valorPara(dni);
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::recuperar(const string& dni, unsigned int puntos) {
	  // A IMPLEMENTAR
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
unsigned int CarnetPorPuntos::consultar(const string& dni) const {
	  // A IMPLEMENTAR
	if (!diccionario_DNI.contiene(dni))throw EConductorNoExiste();
	DiccionarioHash<string, InfoConductor>::ConstIterator iterador = diccionario_DNI.cbegin();
	if (iterador == diccionario_DNI.cend())throw EConductorNoExiste();

	return iterador.valor().num_puntos();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
unsigned int CarnetPorPuntos::cuantos_con_puntos(unsigned int puntos) const {
	  // A IMPLEMENTAR
	return 0;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
const Lista<string>& CarnetPorPuntos::lista_por_puntos(unsigned int puntos) const {
	  // A IMPLEMENTAR
	Lista <string> lista;
	return lista;
	
}

InfoConductor::InfoConductor(int puntos, string dni)
{
	_puntos = puntos;
	_dni = dni;

}



int InfoConductor::num_puntos() const
{
	return _puntos;
	
}

string InfoConductor::obtener_dni() const
{
	return _dni;
}

void ajustar( int puntos, int dni) {
	
}