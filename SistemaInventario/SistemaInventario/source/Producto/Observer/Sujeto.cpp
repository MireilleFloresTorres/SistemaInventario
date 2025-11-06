#include"Prerequisites.h"
#include"Producto/Observer/Sujeto.h"

/**
 * @brief Registra un observador.
 * cuando se agrega un nuevo objeto se nottifica si
 * ocurre algo (En este caso bajo stock)
 * @Param el observador Puntero al observado a registrar
 */ 
void Sujeto::addObservador(Observer* observador) {
	observadores.push_back(observador);
}

/**
 * @brief Se notifica a los observadores 
 * llama a actualizar de cada observador y env+ia la laerta
 * @Param alerta es la información a comunicar 
 */
void Sujeto::notificar(const std::string& alerta) {
	for (auto observador : observadores)
	{
		observador->actualizar(alerta);
	} 
}

/**
 * @brief Elimina un observador registrado.
 *
 * Busca el observador en la lista y lo remueve si existe.
 * @Param el observaddor que es puntero apunta al que hay
 * que remover
 */
void Sujeto::deleteObservador(Observer* observador) {
	for (size_t i = 0; i < observadores.size(); i++) {
		//cuando se encuentra el observador entra mi if
		if (observadores[i] == observador) {
			observadores[i] = observadores.back();
			//se mueve mi ultimo elemento de lvector a la posicion
			//del que vamos a borrar 
			observadores.pop_back();
			//el obsevaro que se va borrar ya está en la ultima posición
			//enotnces se puede eliminar sin desordnear el resto
			break;
		}
	}
}