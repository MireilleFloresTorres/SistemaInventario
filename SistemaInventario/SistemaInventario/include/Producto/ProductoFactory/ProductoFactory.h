/**
 * @file Producto.h
 * @brief Declaración de la clase ProdcutoFactory
 * Contiene metodos virtuales
 */
#pragma once
#include"Producto/Producto.h"

class
ProductoFactory {
public: 


	virtual ~ProductoFactory() = default; 
	virtual Producto* crearProducto() const = 0;
};