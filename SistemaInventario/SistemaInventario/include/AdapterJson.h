#pragma once
#include"Prerequisites.h"
#include"Producto/Producto.h"

class
AdapterJson {
public: AdapterJson(const std::string& archivo); 
	  //recibe nombre del archivo
	  bool saveProductos(const std::vector<Producto*>& productos);
	  //guarda la lista de productos 
	  //vector de puteros a producto 
	  std::vector<Producto*> cargarProductos();
	  //carga los productos desde mi json
private:
	std::string name; //OSEA NAME
};