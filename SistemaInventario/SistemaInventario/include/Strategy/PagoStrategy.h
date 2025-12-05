#pragma once
#include"Prerequisites.h"

/**
 * @class PagoStrategy
 * @brief Interfaz para estrategias de pago.
 */
class
PagoStrategy {
public: 

	virtual ~PagoStrategy() = default; 

	/** @brief Procesa el pago por el monto dado. */
	virtual bool 
	gestionarPago(double monto) = 0; 

	/** @brief Obtiene el tipo de método de pago. */
	virtual 
	std::string getTipo() const = 0; 
};