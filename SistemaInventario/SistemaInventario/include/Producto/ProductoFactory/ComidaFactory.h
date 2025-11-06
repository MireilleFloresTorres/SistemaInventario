#pragma once
#include"Producto/ProductoFactory/ProductoFactory.h"
#include"Producto/ProductoConcreto/ProductoComida.h"

/**
 * @class ComidaFactory
 * @brief Fábrica para crear objetos ProductoComida.
 */
class
	ComidaFactory : public ProductoFactory {
public:
	/**
	 * @brief Constructor de la fábrica.
	 * @param codigo Código del producto.
	 * @param nombre Nombre del producto.
	 * @param precio Precio del producto.
	 * @param cantidad Cantidad en inventario.
	 * @param caducidad Fecha de caducidad.
	 */
	ComidaFactory(int codigo, std::string nombre, double precio,
		int cantidad, std::string& caducidad);
	/**
	* destructor sobreescrito 
	*/
	~ComidaFactory() override = default;

	/**
	 * @brief Crea un producto de tipo comida.
	 * @return Puntero a ProductoComida.
	 */
	Producto* crearProducto() const override;
private:
	int Codigo;
	int Cantidad;
	double Precio;
	std::string Nombre;
	std::string Caducidad; 
};