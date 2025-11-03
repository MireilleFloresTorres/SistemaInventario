#pragma once
#include"Producto/Observer/Observer.h"
#include"Prerequisites.h"

class
	AlertaInventario : public Observer {
public: 
	void actualizar(const std::string& alerta) override; 
};