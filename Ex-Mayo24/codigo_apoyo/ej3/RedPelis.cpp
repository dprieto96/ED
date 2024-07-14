/*
NOMBRE Y APELLIDOS:

USUARIO JUEZ ASIGNADO PARA EL EXAMEN:

*/

#include "RedPelis.h"


/*
 DETERMINACION JUSTIFICADA DE LA COMPLEJIDAD:
 
*/
RedPelis::RedPelis(int cuota, int extra_minuto) {
   /* A IMPLEMENTAR */	
}

/*
 DETERMINACION JUSTIFICADA DE LA COMPLEJIDAD:
 
*/
void RedPelis::registra_usuario(const tUsuario& usuario, const tTarjeta& tarjeta) {
   /* A IMPLEMENTAR */	
}

/*
 DETERMINACION JUSTIFICADA DE LA COMPLEJIDAD:
 
*/
void RedPelis::registra_pelicula(const tPelicula& pelicula,const tRegistro& registro) {
   /* A IMPLEMENTAR */	
}

/*
 DETERMINACION JUSTIFICADA DE LA COMPLEJIDAD:
 
*/
void RedPelis::mira(const tUsuario& usuario, const tPelicula& pelicula, int minutos) {
   /* A IMPLEMENTAR */	
}

/*
 DETERMINACION JUSTIFICADA DE LA COMPLEJIDAD:
 
*/
InfoFactura RedPelis::factura(const tUsuario& usuario) const {
   /* A IMPLEMENTAR */	
}


/*
 DETERMINACION JUSTIFICADA DE LA COMPLEJIDAD:
 
*/
Lista<tPelicula> RedPelis::hits(int k) const {
   /* A IMPLEMENTAR */	
}