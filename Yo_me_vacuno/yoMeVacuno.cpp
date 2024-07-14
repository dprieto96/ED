/*
NOMBRE Y APELLIDOS:

USUARIO DomJudge ASIGNADO:

*/

#include "yoMeVacuno.h"
#include "lista.h"
#include "diccionario.h"
#include "cola.h"


/*
 DETERMINACION DE LA COMPLEJIDAD
 O(1)
*/
YoMeVacuno::YoMeVacuno(tAnio anio, tNumVacunas n) {
	 // A IMPLEMENTAR
	_anio = anio;
	_numVacunas = n;
}

/*
 DETERMINACION DE LA COMPLEJIDAD
 
*/
void YoMeVacuno::fija_Anio_NumVacunas(tAnio anio, tNumVacunas n) {
	 // A IMPLEMENTAR 
	_anio = anio;
	_numVacunas =_numVacunas+ n;
}

/*
 DETERMINACION DE LA COMPLEJIDAD
 
*/
void YoMeVacuno::registra_centro(tIdCentro id, tDireccion dir) {
 // A IMPLEMENTAR 
	if (_centros.contiene(id)) throw ECentroDuplicado();
	else {
		_centros.inserta(id,DatosCentro(dir));
	}
}

/*
 DETERMINACION DE LA COMPLEJIDAD
 
*/
void YoMeVacuno::registra_ciudadano(tIdCiudadano id, tAnio anio) {
 // A IMPLEMENTAR 
	if (_poblacion.contiene(id)) throw ECiudadanoDuplicado();
	else {
		_poblacion.inserta(id, DatosCiudadano(anio));
	}
}

/*
 DETERMINACION DE LA COMPLEJIDAD
 
*/
void YoMeVacuno::pide_cita(tIdCiudadano id) {
	// A IMPLEMENTAR
}

/*
 DETERMINACION DE LA COMPLEJIDAD
 
*/
bool YoMeVacuno::en_espera() {
	// A IMPLEMENTAR

}

/*
 DETERMINACION DE LA COMPLEJIDAD
 
*/
Lista<Asignacion> YoMeVacuno::atiende_solicitudes() {
	// A IMPLEMENTAR

}

/*
 DETERMINACION DE LA COMPLEJIDAD
 
*/
bool YoMeVacuno::administra_vacuna(tIdCentro idCentro) {
// A IMPLEMENTAR

}
