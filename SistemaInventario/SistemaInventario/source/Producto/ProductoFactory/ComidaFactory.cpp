#include"Producto/ProductoFactory/ComidaFactory.h"

ComidaFactory::ComidaFactory(int codigo, std::string nombre, double precio,
	int cantidad, std::string& caducidad) : Codigo(codigo), Nombre(nombre),
	Precio(precio), Cantidad(cantidad), Caducidad(caducidad){}//inicializo atributos 

Producto* ComidaFactory::crearProducto() const {
	return new ProductoComida(Codigo, Nombre, Precio, Cantidad, Caducidad);
}//creamos objeto comida con los datos de la fabrica 
//mi fabrica tiene los atributos base y hace instancias nuevas 