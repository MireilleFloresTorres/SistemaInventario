#pragma once
#include"Producto/Producto.h"

class
	FabricaProducto {
public:
	virtual~FabricaProducto() = default;
	vitual Producto* crearProducto() const = 0; 
};