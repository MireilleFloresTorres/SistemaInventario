#pragma once
#include"Prerequisites.h"

class
PagoStrategy {
public: 

	virtual ~PagoStrategy() = default; 
	virtual bool 
	gestionarPago(double monto) = 0; 

	virtual 
	std::string getTipo() const = 0; 
};