#pragma once
#include"Producto/Observer/Observer.h"
#include "Prerequisites.h"

/**
 * @class Sujeto
 * @brief Clase base del patrón Observer.
 *	hay una lista de observadores con metodos para 
 * su registro, eliminacion y nitificacion de cmabios 
 */
class
Sujeto {
public: 
	virtual 
	~Sujeto() = default;

	/**
	 * @brief Agrega un observador para ser notificado.
	 * @param observador Puntero al observador a registrar.
	 */
	void 
	addObservador(Observer* observador);

	/**
	 * @brief Elimina un observador
	 * @param observador Puntero al observador a eliminar
	 */
	void 
	deleteObservador(Observer* observador);

	/**
	 * @brief Notifica a todos los observadores registrados.
	 * @param alerta Mensaje o información enviada.
	 */
	void 
	notificar(const std::string& alerta);

private: 
	std::vector<Observer*> observadores; 
};