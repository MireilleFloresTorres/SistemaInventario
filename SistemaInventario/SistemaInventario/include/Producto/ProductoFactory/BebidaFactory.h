#pragma once
#pragma once
#include"Producto/ProductoFactory/ProductoFactory.h"
#include"Producto/ProductoConcreto/ProductoBebida.h"

class
	BebidaFactory : public ProductoFactory {
public:
	BebidaFactory(int codigo, std::string nombre, double precio,
		int cantidad,int azucares);
	~BebidaFactory() override = default;

	Producto* crearProducto() const override;
private:
	int Codigo;
	int Cantidad;
	double Precio;
	std::string Nombre;
	int Azucares;
};