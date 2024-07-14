// estructura de datos mejorada que incorpora el volumen embalsado en un río, para mejorar coste de "embalsado_cuenca"
#include <string>
using namespace std;
#include "tabla dispersa/DiccionarioHash.h"


class ERioDuplicado {};
class ERioNoExiste {};
class EPantanoDuplicado {};
class EPantanoNoExiste{};


class info_pantano {
public:
	/**
	Crea un pantano con una capacidad maxima y un volúmen embalsado inicial.
	@param cmax Capacidad máxima del pantano
	@param vol Volumen inicial embalsado
	*/
	info_pantano(float cmax = 0, float vol = 0) : _cmax(cmax), _vol(vol) {}

	/**
	  Permite consultar la capacidad máxima del pantano
	  @return capacidad máxima del pantano
	*/
	float cmax() const { return _cmax; }

	/**
	  Permite consultar el volumen embalsado en el pantano
	  @return volumen embalsado
	*/
	float vol() const { return _vol; }

	/**
	Actualiza el volumen embalsado en el pantano
	@param vol Nuevo volumen embalsado
	*/
	void pon_vol(float vol) { _vol = vol; }
private:
	float _cmax;
	float _vol;
};


class info_rio {
public:
	info_rio() { _volEmbalsado = 0;};

	void insertar(const string& pantano, float cmax, float vol) {
		if (_pantanos.contiene(pantano)) throw EPantanoDuplicado();
		_pantanos.inserta(pantano, info_pantano(cmax, vol));
		_volEmbalsado += vol;
	}

	float embalsado_rio() const {
		return _volEmbalsado;
	}

	// añadir los métodos que sean necesarios

private:
	float _volEmbalsado;
	DiccionarioHash<string, info_pantano> _pantanos;
};




// clase para representar la confederación hidrográfica: 
// diccionario hash [clave = string = nombre del rio; 
// valor = info_rio = colección de los pantanos que contiene el río 
// (diccionario hash: clave = string = nombre del pantano y valor = info_pantano) + volumen total embalsado]

class ConfederacionHidrografica {
public:
	/**
	  Crea una confederación vacía, sin ríos.
	*/
	ConfederacionHidrografica();

	/**
	  Inserta un nuevo río en la confederación.
	  Si el río ya existe, levanta la excepción ERioDuplicado
	  @param rio El río a insertar
	*/
	void insertar_rio(const string& rio);


	/**
	  Inserta un nuevo pantano en un río.
	  Si el río no existe, levanta la excepción ERioNoExiste.
	  Si el pantano ya existe, levanta la excepción EPantanoDuplicado.
	  @param rio El nombre del río al que se va a añadir del pantano.
	  @param pantano El nombre del pantano a añadir
	  @cmax Capacidad máxima del pantano
	  @vol Volumen inicial embalsado en el pantano
	*/
	void insertar_pantano(const string& rio, const string& pantano,  float cmax,  float vol);


	/**
	  Embalsa un cierto volumen en un pantano de un rio
	  Si el río no existe, se levanta la excepción ERioNoExiste
	  Si el pantano no existe, se levanta la excepción EPantanoNoExiste
	  Si no cabe todo el volumen de agua, el pantano se llena
	  @param rio Nombre del rio
	  @param pantano Nombre del pantano
	  @param vol Volumen a embalsar
	*/
	void embalsar(const string& rio, const string& pantano,  float vol);


	/**
	  Consulta el volumen embalsado en un pantano de un río
	  Si el río no existe, se levanta la excepción ERioNoExiste
	  Si el pantano no existe, se levanta la excepción EPantanoNoExiste
	  @param rio Nombre del rio
	  @param pantano Nombre del pantano
	*/
	float embalsado_pantano(const string& rio, const string& pantano) const;



	/**
	 Consulta el volumen total embalsado en un río
	 Si el río no existe, se levanta la excepción ERioNoExiste
	 @param rio Nombre del rio
	*/
	float embalsado_cuenca(const string& rio) const;


	/**
	 Realiza un transvase de agua entre pantanos
	 Si alguno de los ríos no existe, se levanta la excepción ERioNoExiste
	 Si alguno de los pantanos no existe, se levanta la excepción EPantanoNoExiste
	 Si el volumen a transvasar es negativo, se cambia el sentido del transvase (es decir,
	 se pasa el agua del pantano destino al origen)
	 Solo se trasvasa la cantidad que quepa en el pantano destino, y, como
	 mucho, la cantidad embalsada en el pantano de origen
	 @param rio_origen Nombre del río origen
	 @param pantano_origen Nombre del pantano origen
	 @param rio_destino Nombre del río destino
	 @param pantano_destino Nombre del pantano destino
	 @param vol Volumen a transvasar
	*/
	void trasvasar(const string& rio_origen, const string& pantano_origen,
		const string& rio_destino, const string& pantano_destino,
		float vol);

private:
	DiccionarioHash<string, info_rio> _rios;
};


