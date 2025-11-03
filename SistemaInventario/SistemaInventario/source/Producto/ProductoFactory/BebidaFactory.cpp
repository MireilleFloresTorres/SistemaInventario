#include"Producto/ProductoFactory/BebidaFactory.h"

BebidaFactory::BebidaFactory(int codigo, std::string nombre, double precio,
	int cantidad, int azucares) : Codigo(codigo), Nombre(nombre),
	Precio(precio), Cantidad(cantidad), Azucares(azucares) {
}

Producto* BebidaFactory::crearProducto() const {
	return new ProductoBebida(Codigo, Nombre, Precio, Cantidad, Azucares);
}