#include"Prerequisites.h"
#include "Producto\Producto.h"

Producto::Producto(int id, std:: string nombre, int cantidad, double precio):
	Codigo(codigo), Nombre(nombre), Precio(precio), Cantidad(cantidad) {}

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


