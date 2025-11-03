#pragma once
#include "Prerequisites.h"

class
Producto {
public: 

	virtual void showInfo() const = 0;
	virtual ~Producto() = default; 

	int getCodigo() const;
	int getCnatidad() const;
	double getPrecio() const; 

	void setNombre(const std::string& nombre);
	void setPrecio(double precio);
	void setCantidad(int cantidad);

	virtual void showInfo() const = 0; 
protected: 
	Producto(int codigo, int cantidad, double precio, std::string nom);

private:
	int Codigo;
	int Cantidad;
	double precio;
	std::string nombre; 
};