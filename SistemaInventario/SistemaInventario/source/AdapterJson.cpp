#include"Prerequisites.h"
#include"AdapterJson.h"
#include"Producto/Producto.h"
#include"Producto/ProductoConcreto/ProductoBebida.h"
#include"Producto/ProductoConcreto/ProductoComida.h"
#include"Producto/ProductoConcreto/ProductoMedicamento.h"

AdapterJson::AdapterJson(const std::string& archivo) : name (archivo) {}

bool AdapterJson::saveProductos(const std::vector<Producto*>& productos) {

}