#pragma once
#include"PagoStrategy.h"

/**
 * @class PagoCredito
 * @brief Interfaz para estrategias de pago.
 */
class PagoCredito : public PagoStrategy {
public:
	/** @brief Procesa el pago por el monto dado. */
	bool gestionarPago(double monto) override;

	/** @brief Devuelve el tipo de pago ("Efectivo"). */
	std::string getTipo() const override;
};