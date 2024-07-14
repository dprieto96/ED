/*
NOMBRE Y APELLIDOS:

USUARIO DomJudge ASIGNADO:

*/

#ifndef _yomevacuno_H
#define _yomevacuno_H

#include "lista.h"
#include <string>
using namespace std;

class ECentroDuplicado {};  // excepci�n asociada a registra_centro
class ECiudadanoDuplicado {}; // excepci�n asociada a registra_ciudadano
class ECiudadanoInexistente {};  // excepci�n asociada a pide_cita
class EAnioErroneo {};  // excepci�n asociada a pide_cita
class EExisteCita {};  // excepci�n asociada a pide_cita
class EErrorDeAtencion {};  // excepci�n asociada a atiende_solicitudes
class ECentroInexistente {};  // excepci�n asociada a administra_vacuna

typedef unsigned int tIdCentro;  // tipo para el identificador del centro
typedef string tDireccion; // tipo para la direcci�n del centro
typedef unsigned int tIdCiudadano; // tipo para el identificador del ciudadano
typedef unsigned int tNumVacunas; // tipo para el n� de vacunas disponibles
typedef unsigned int tAnio; // tipo para el a�o de nacimiento

// clase para la asignaci�n de centro a ciudadano que ha pedido cita  
class Asignacion {
public:
    void ponCiudadano(tIdCiudadano id) { _ciudadano = id; }
    void ponCentro(tIdCentro id) { _centro = id; }
    void ponDireccion(tDireccion dir) { _direccion = dir; }
    const tIdCiudadano& dameCiudadano() const { return _ciudadano; }
    const tIdCentro& dameCentro() const { return _centro; }
    const tDireccion& dameDireccion() const { return _direccion; }
private:
    tIdCiudadano  _ciudadano;
    tIdCentro _centro;
    tDireccion _direccion;
};


class YoMeVacuno {
public:
   YoMeVacuno(tAnio anio, tNumVacunas n);
   void registra_centro(tIdCentro id, tDireccion dir);
   void registra_ciudadano(tIdCiudadano id, tAnio anio);
   void fija_Anio_NumVacunas(tAnio anio, tNumVacunas n);
   void pide_cita(tIdCiudadano id);
   bool en_espera();
   Lista<Asignacion> atiende_solicitudes();
   bool administra_vacuna(tIdCentro idCentro);
private:  
   // A INCLUIR DETALLES DE REPRESENTACION

};

#endif