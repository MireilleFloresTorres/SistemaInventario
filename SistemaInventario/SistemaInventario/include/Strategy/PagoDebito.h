#pragma once
#include"PagoStrategy.h"

class PagoDebito : public PagoStrategy {
public:
	bool gestionarPago(double monto) override;
	std::string getTipo() const override;
};