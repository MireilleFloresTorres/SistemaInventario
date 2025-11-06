#include"Producto/ProductoFactory/ComidaFactory.h"

/**
 * @brief Constructor de ComidaFactory.
 *
 * Inicializa los datos necesarios para crear posteriormente
 * un objeto ProductoComida. Esta fábrica encapsula la configuración
 * del producto para que la creación sea consistente.
 */
ComidaFactory::ComidaFactory(int codigo, std::string nombre, double precio,
	int cantidad, std::string& caducidad) : Codigo(codigo), Nombre(nombre),
	Precio(precio), Cantidad(cantidad), Caducidad(caducidad){}//inicializo atributos 

/**
 * @brief Crea una instancia de ProductoComiida.
 *
 * Implementación del Factory Method. Devuelve un nuevo producto
 * construido con los datos almacenados en la fábrica.
 * retorno un puntero al objeto ProductoComida
 */
Producto* ComidaFactory::crearProducto() const {
	return new ProductoComida(Codigo, Nombre, Precio, Cantidad, Caducidad);
}//creamos objeto comida con los datos de la fabrica 
//mi fabrica tiene los atributos base y hace instancias nuevas 