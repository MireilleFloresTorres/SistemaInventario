#pragma once
#include "Prerequisites.h"

/**
 * @class Producto
 * @brief Clase abstracta que representa un producto genérico.
 * es virtual puro 
 */
class
Producto {
public: 

	/**
	 * @brief Destructor virtual.
	 */
	virtual ~Producto() = default; 
	//destructor virtual si llego a desturir mi objeto
	//con el puntero a prodcuto se llama el destructor derivado

	/**
	 * @brief getters.
	 */
	int getCodigo() const;
	int getCantidad() const;
	double getPrecio() const; 
	std::string getNombre() const;

	/**
	 * @brief Asigna un nombre al producto.
	 * @param nombre Nombre del producto.
	 */
	void setNombre(const std::string& nombre);

	/**
	 * @brief Asigna un precio al producto.
	 * @param precio Nuevo precio del producto.
	 */
	void setPrecio(double precio);

	/**
	 * @brief Asigna la cantidad disponible del producto.
	 * @param cantidad Nueva cantidad del producto.
	 */
	void setCantidad(int cantidad);

	/**
	 * @brief Muestra la información del producto.
	 *
	 * Método virtual puro que debe implementarse en las clases derivadas
	 * para definir cómo se muestra la información del producto.
	 */

	virtual void showInfo() const = 0; 

	/**
	* @brief Constructor protegido.
	*/
protected: 
	Producto(int id, std::string nombre, int cantidad, double precio);
	//todo con el mismo nombre ya basta por favor
	// clases derivadas hagan objetos no externos 

private:
	int Codigo;
	int Cantidad;
	double Precio;
	std::string Nombre; 
};