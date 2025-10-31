#pragma once
#include "Prerequisites.h"
#include "Producto/Producto.h"

class
ProductoComida : public Producto {
public: 

	ProductoComida(int id, int cantidad, double precio, const std::string& nombre);

private: 
	int id;
	int cantidad;
	double precio; 
	std::string nombre; 
	std::string caducidad; 
};