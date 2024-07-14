#ifndef _CARNET_POR_PUNTOS_H
#define _CARNET_POR_PUNTOS_H

#include "lista.h"
#include "DiccionarioHash.h"
#include <string>
using namespace std;

class EConductorDuplicado {};
class EConductorNoExiste {};
class EPuntosNoValidos {};

typedef Lista <string>::Iterator PosicionConductor;

class InfoConductor {
public:
	InfoConductor(int puntos, string DNI);
	int num_puntos()const;
	string obtener_dni()const ;
private:
	string _dni;
	int _puntos;
};

class CarnetPorPuntos {
public:
   CarnetPorPuntos();
   void nuevo(const string& dni);
   void quitar(const string& dni, unsigned int puntos);
   void recuperar(const string& dni, unsigned int puntos);
   unsigned int consultar(const string& dni) const;
   unsigned int cuantos_con_puntos(unsigned int puntos) const;
   const Lista<string>& lista_por_puntos(unsigned int puntos) const;
private:
   // A COMPLETAR
	DiccionarioHash<string, InfoConductor>diccionario_DNI;

};

#endif