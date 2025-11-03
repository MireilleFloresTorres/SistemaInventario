#pragma once
#include"Producto/Producto.h"

class
ProductoFactory {
public: 
	virtual ~ProductoFactory() = default; 
	virtual Producto* crearProducto() const = 0;
};