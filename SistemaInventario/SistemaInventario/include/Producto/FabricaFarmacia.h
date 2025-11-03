#pragma once
#include"Producto/FabricaAbstracta.h"
#include "Producto/ProductoBebida.h"
#include "Producto/ProductoComida.h"
#include "Producto/ProductoMedicamento.h"

class 
FabricaFarmacia : public FabricaAbstracta {
public: 
	ProductoComida* crearProductoComida() const override;
	ProductoBebida* crearProductoBebida() const override;
	ProductoMedicamento* crearProductoMedicamento() const override;
};