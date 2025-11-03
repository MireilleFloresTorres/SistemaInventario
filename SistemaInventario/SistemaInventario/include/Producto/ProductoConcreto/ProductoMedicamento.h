#pragma once
#include "Producto/Producto.h"

class
	ProductoMedicamento : public Producto {
public:
	ProductoMedicamento(int codigo, std::string nombre, double precio, int cantidad, std::string& caducidad);
	~ProductoMedicamento() override = default;

	std::string getAdministracion;

	void
	setAdministracion(const std:: string& administacion); 

private:
	std::string administracion;
};