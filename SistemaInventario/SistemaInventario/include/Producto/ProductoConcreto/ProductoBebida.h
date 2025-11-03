#pragma once
#include "Producto/Producto.h"

class
	ProductoBebida : public Producto {
public:
	ProductoBebida(int codigo, std::string nombre, double precio, int cantidad, std::string& caducidad);
	~ProductoBebida() override = default;

	int 
	getAzucares() const; 

	void
	setAzucares(int azucares);

	void showInfo() const override;
};