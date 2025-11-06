#include"Producto/ProductoFactory/BebidaFactory.h"

/**
 * @brief Constructor de BebidaFactory.
 *
 * Inicializa los datos necesarios para crear posteriormente
 * un objeto ProductoBebida. Esta fábrica encapsula la configuración
 * del producto para que la creación sea consistente.
 */
BebidaFactory::BebidaFactory(int codigo, std::string nombre, double precio,
	int cantidad, int azucares) : Codigo(codigo), Nombre(nombre),
	Precio(precio), Cantidad(cantidad), Azucares(azucares) {
}

/**
 * @brief Crea una instancia de ProductoBebida.
 *
 * Implementación del Factory Method. Devuelve un nuevo producto
 * construido con los datos almacenados en la fábrica.
 * retorno un puntero al objeto ProductoBebida 
 */
Producto* BebidaFactory::crearProducto() const {
	return new ProductoBebida(Codigo, Nombre, Precio, Cantidad, Azucares);
}