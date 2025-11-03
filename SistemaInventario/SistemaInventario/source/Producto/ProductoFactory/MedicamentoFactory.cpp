#include"Producto/ProductoFactory/MedicamentoFactory.h"

MedicamentoFactory::MedicamentoFactory(int codigo, std::string nombre, double precio,
	int cantidad, std::string& administracion) : Codigo(codigo), Nombre(nombre),
	Precio(precio), Cantidad(cantidad), Administracion(administracion) {
}//inicializo atributos 

Producto* MedicamentoFactory::crearProducto() const {
	return new ProductoMedicamento(Codigo, Nombre, Precio, Cantidad, Administracion);
}