#pragma once
#include "Prerequisites.h"

/**
 * @class Observer
 * @brief Interfaz del patrón Observer.
 */
class
Observer {
public: 
	/**
	* Destructor virtual
	*/
	virtual ~Observer() = default; 
	virtual void actualizar(const std::string& alerta) = 0; 
};