#pragma once
#include"Producto/Producto.h"

class
	FabricaProducto {
public:
	virtual~FabricaProducto() = default;
	virtual Producto* crearProducto() const = 0; 
};