#include "Cuenca.h"
#include <string>
#include "tabla dispersa/DiccionarioHash.h"
using namespace std;


ConfederacionHidrografica::ConfederacionHidrografica() {}

void ConfederacionHidrografica::insertar_rio(const string& rio) {
	if (_rios.contiene(rio)) throw ERioDuplicado();
	//_rios.inserta(rio, DiccionarioHash<string,info_pantano>());	// versión 1 cambia a...
	_rios.inserta(rio, info_rio());	// ... esto en la versión 2	
}


void ConfederacionHidrografica::insertar_pantano(const string& rio, const string& pantano,  float cmax,  float vol) {	
	DiccionarioHash<string, /*DiccionarioHash<string, info_pantano>*/ info_rio>::Iterator irio = _rios.busca(rio);  // cambios al pasar a versión 2
	DiccionarioHash<string, /*DiccionarioHash<string, info_pantano>*/ info_rio>::Iterator ifin = _rios.end();  // cambios al pasar a versión 2
	if (irio == ifin) throw ERioNoExiste();

	/*if (irio.valor().contiene(pantano)) throw EPantanoDuplicado();
	irio.valor().inserta(pantano, info_pantano(cmax, vol));*/  // versión 1 cambia a ....
	irio.valor().insertar(pantano, cmax, vol);  // ... esto en la versión 2
}


void ConfederacionHidrografica::embalsar(const string& rio, const string& pantano, float vol) {
	
}


float ConfederacionHidrografica::embalsado_pantano(const string& rio, const string& pantano) const {
	
}

float ConfederacionHidrografica::embalsado_cuenca(const string& rio) const {
	
}

void ConfederacionHidrografica::trasvasar(const string& rio_origen, const string& pantano_origen,
	const string& rio_destino, const string& pantano_destino, float vol) {

}