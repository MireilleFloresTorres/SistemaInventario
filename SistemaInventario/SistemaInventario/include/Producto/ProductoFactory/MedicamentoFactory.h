#pragma once
#include"Producto/ProductoFactory/ProductoFactory.h"
#include"Producto/ProductoConcreto/ProductoMedicamento.h"

class
	MedicamentoFactory : public ProductoFactory {
public:
	MedicamentoFactory(int codigo, std::string nombre, double precio,
		int cantidad, std::string& administracion);
	~MedicamentoFactory() override = default;

	Producto* crearProducto() const override;
private:
	int Codigo;
	int Cantidad;
	double Precio;
	std::string Nombre;
	std::string Administracion;
};