#pragma once
#include"Prerequisites.h"
#include"Producto/Producto.h"

class
AdapterJson {
public: AdapterJson(const std::string& archivo); 
	  bool saveProductos(const std::vector<Producto*> productos);
	  std::vector<Producto*> cargarProductos();
private:
	std::string name; 
};