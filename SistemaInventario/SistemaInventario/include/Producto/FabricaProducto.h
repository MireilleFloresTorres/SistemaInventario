#pragma once
#include"Producto/Producto.h"

/**
 * @class FabricaProducto
 * @brief Clase abstracta que representa un producto genérico.
 */
class
	FabricaProducto {
public:

	/**
	 * @brief Destructor virtual en default
	 */
	virtual~FabricaProducto() = default;

	/**
	 * metodo virtual para crear un objeto producto
	 */
	virtual Producto* crearProducto() const = 0; 
};