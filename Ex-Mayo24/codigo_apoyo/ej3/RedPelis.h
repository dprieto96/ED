/*
NOMBRE Y APELLIDOS:

USUARIO JUEZ ASIGNADO PARA EL EXAMEN:

*/
#ifndef _REDPELI_H
#define _REDPELI_H

#include "lista.h"
#include <string>
using namespace std;


/* Clases para las excepciones levantadas por las operaciones */
class EUsuarioDuplicado {};
class EPeliculaDuplicada{};
class EPeliculaNoExiste {};
class EUsuarioNoExiste {};

typedef string tUsuario;     /* Tipo id usuario      */
typedef string tPelicula;    /* Tipo id pelicula     */
typedef string tTarjeta;     /* Tipo tarjeta usuario */
typedef string tRegistro;    /* Tipo num registro    */

/* Clase para los datos de factura devueltos por
   la operacion 'factura' */
class InfoFactura {
   public:
        InfoFactura(const tUsuario& u, const tTarjeta& t, int c):
              usuario(u), tarjeta(t), cantidad(c) {
        }
        tUsuario usuario;  /* id del usuario al que se emite la factura */
        tTarjeta tarjeta;  /* num tarjeta */
        int cantidad;      /* cantidad facturada */
};

class RedPelis {
public:
    RedPelis(int cuota, int extra_minuto);
    void registra_usuario(const tUsuario& usuario, const tTarjeta& tarjeta);
    void registra_pelicula(const tPelicula& pelicula, const tRegistro& num_registro);
    void mira(const tUsuario& usuario, const tPelicula& pelicula, int minutos);
    InfoFactura factura(const tUsuario& usuario) const;
    Lista<tPelicula> hits(int k) const;
private:
  /* A completar con los detalles de la representacion */
  
};

#endif