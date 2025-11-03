#pragma once
#include "Producto/Producto.h"

class
 ProductoComida: public Producto {
public: 
	ProductoComida(int codigo, std::string nombre, double precio, 
		int cantidad, std::string caducidad);

	~ProductoComida() override = default;

	std::string getCaducidad() const; 
	void setCaducidad(const std::string& fecha);

	void showInfo() const override;   
private: 
	std::string Caducidad; 
};