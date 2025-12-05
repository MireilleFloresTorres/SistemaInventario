#pragma once
#include"Prerequisites.h"
#include "Strategy/PagoStrategy.h"

/**
 * @class Proveedor
 * @brief Maneja precios y carga de combustible usando una estrategia de pago.
 */
class
	Proveedor {
public: 
	Proveedor(); 
	~Proveedor(); 

	/** @brief Define la estrategia de pago. */
	void
	setPagoStrategy(PagoStrategy* _strategy);

	/** @brief Precio del combustible según tipo. */
	double
	getPrecio(TipoCombustible tipo); 

	/** @brief Nombre del combustible. */
	std::string getNameGas(TipoCombustible tipo); 

	/** @brief Realiza la carga de combustible. */
	bool 
	cargarCombustible(TipoCombustible tipo, double litros); 

	/** @brief Total acumulado. */
	double
	getsumTotal() const; 

public:
	double precioMagna;
	double precioPremium;
	double precioDiesel; 

	PagoStrategy* _strategy; 
	double sumTotal; 
};