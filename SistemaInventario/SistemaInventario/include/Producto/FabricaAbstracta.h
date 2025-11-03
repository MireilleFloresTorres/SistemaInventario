#pragma once
class ProductoComida;
class ProductoBebida;
class ProductoMedicamento; 

class
FabricaAbstracta {
public: 
	virtual
	ProductoComida* crearProductoComida() const = 0; 

	virtual 
	ProductoBebida* crearProductoBebida() const = 0;

	virtual 
	ProductoMedicamento* crearProductoMedicamento() const = 0;

	virtual
	~FabricaAbstracta() = default; 
};