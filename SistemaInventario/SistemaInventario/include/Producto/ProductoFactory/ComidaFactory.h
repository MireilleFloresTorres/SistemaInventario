#pragma once
#include"Producto/ProductoFactory/ProductoFactory.h"
#include"Producto/ProductoConcreto/ProductoComida.h"

class
	ComidaFactory : public ProductoFactory {
public:
	ComidaFactory(int codigo, std::string nombre, double precio,
		int cantidad, std::string& caducidad);
	~ComidaFactory() override = default;

	Producto* crearProducto() const override;
private:
	int Codigo;
	int Cantidad;
	double Precio;
	std::string Nombre;
	std::string Caducidad; 
};