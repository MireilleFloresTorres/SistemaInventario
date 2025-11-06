#pragma once
#pragma once
#include"Producto/ProductoFactory/ProductoFactory.h"
#include"Producto/ProductoConcreto/ProductoBebida.h"

/**
 * @class BenbidaFactory
 * @brief Fábrica para crear objetos ProductoBebida.
 */
class
	BebidaFactory : public ProductoFactory {
public:
	/**
	 * @brief Constructor de la fábrica.
	 * @param codigo Código del producto.
	 * @param nombre Nombre del producto.
	 * @param precio Precio del producto.
	 * @param cantidad Cantidad en inventario.
	 * @param caducidad Fecha de caducidad.
	 */
	BebidaFactory(int codigo, std::string nombre, double precio,
		int cantidad,int azucares);
	/**
	* destructor sobreescrito
	*/
	~BebidaFactory() override = default;
	/**
	 * @brief Crea un producto de tipo bebida.
	 * @return Puntero a ProductoBebida.
	 */
	Producto* crearProducto() const override;
private:
	int Codigo;
	int Cantidad;
	double Precio;
	std::string Nombre;
	int Azucares;
};