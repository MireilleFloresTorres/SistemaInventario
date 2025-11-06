#include"Prerequisites.h"
#include "Producto\Producto.h"

/**
 * @brief Constructor base de Producto.
 *
 * @param codigo Código identificador.
 * @param nombre Nombre del producto.
 * @param cantidad Cantidad disponible.
 * @param precio Precio unitario.
 */
Producto::Producto(int codigo, std::string nombre, int cantidad, double precio)
	: Codigo(codigo), Nombre(nombre), Precio(precio), Cantidad(cantidad) {
}

/**
 * @brief Obtiene el código del producto.
 */
int 
Producto::getCodigo() const {
	return Codigo; 
}

/**
 * @brief Obtiene la cantidad del producto.
 */
int
Producto::getCantidad() const {
	return Cantidad;
}

/**
 * @brief Obtiene el precio del producto.
 */
double
Producto::getPrecio() const {
	return Precio;
}

/**
 * @brief Obtiene el nombre del producto.
 */
std::string Producto::getNombre() const {
	return Nombre;
}

/**
 * @brief Cambia el nombre del producto.
 */
void Producto::setNombre(const std::string& nombre) {
	Nombre = nombre; 
}

/**
 * @brief Cambia elprecio del producto.
 */
void Producto::setPrecio(double precio) {
	Precio = precio;
}

/**
 * @brief Cambia la cantidad del producto.
 */
void Producto::setCantidad(int cantidad) {
	Cantidad = cantidad;
}