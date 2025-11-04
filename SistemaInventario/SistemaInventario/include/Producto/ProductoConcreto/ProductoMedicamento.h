#pragma once
#include "Producto/Producto.h"

class
	ProductoMedicamento : public Producto {
public:
	ProductoMedicamento(int codigo, std::string nombre, double precio,
		int cantidad, std::string administracion);
	~ProductoMedicamento() override = default;

	std::string getAdministracion() const; 

	void
	setAdministracion(const std:: string& administracion); 

	void
	showInfo() const override; 
	std::string getTipo() const override;

private:
	std::string Administracion;
};