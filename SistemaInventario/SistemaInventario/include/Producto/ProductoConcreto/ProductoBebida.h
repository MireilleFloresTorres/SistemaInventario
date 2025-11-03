#pragma once
#include "Producto/Producto.h"

class
	ProductoBebida : public Producto {
public:
	ProductoBebida(int codigo, std::string nombre, double precio,
		int cantidad, int azucares);
	~ProductoBebida() override = default;

	int 
	getAzucares() const; 

	void
	setAzucares(int azucares);

	void showInfo() const override;
private:
	int Azucares; 
};