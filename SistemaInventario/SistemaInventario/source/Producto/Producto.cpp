#include"Prerequisites.h"
#include "Producto\Producto.h"

Producto::Producto(int codigo, std::string nombre, int cantidad, double precio)
	: Codigo(codigo), Nombre(nombre), Precio(precio), Cantidad(cantidad) {
}
int 
Producto::getCodigo() const {
	return Codigo; 
}

int
Producto::getCantidad() const {
	return Cantidad;
}

double
Producto::getPrecio() const {
	return Precio;
}

std::string Producto::getNombre() const {
	return Nombre;
}

void Producto::setNombre(const std::string& nombre) {
	Nombre = nombre; 
}

void Producto::setPrecio(double precio) {
	Precio = precio;
}

void Producto::setCantidad(int cantidad) {
	Cantidad = cantidad;
}