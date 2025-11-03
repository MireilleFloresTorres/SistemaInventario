#pragma once
#include "Prerequisites.h"
#include "Producto/ProductoComida.h"

class 
ProductoAtun : public  ProductoComida {
public:
	ProductoAtun(int id, int cantidad, double precio, const std::string& nombre);

	void operacionComida() const  override; 
};
