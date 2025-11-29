#pragma once
#include"Prerequisites.h"
#include "Strategy/PagoStrategy.h"

class
	Proveedor {
public: 
	Proveedor(); 
	~Proveedor(); 


	void
	setPagoStrategy(PagoStrategy* _strategy);

	double
	getPrecio(TipoCombustible tipo); 

	std::string getNameGas(TipoCombustible tipo); 

	bool 
	cargarCombustible(TipoCombustible tipo, double litros); 

	double
	getsumTotal() const; 

public:
	double precioMagna;
	double precioPremium;
	double precioDiesel; 

	PagoStrategy* _strategy; 
	double sumTotal; 
};