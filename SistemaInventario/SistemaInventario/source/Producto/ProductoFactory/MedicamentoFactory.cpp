#include"Producto/ProductoFactory/MedicamentoFactory.h"

/**
 * @brief Constructor de MedicamentoFactory.
 *
 * Inicializa los datos necesarios para crear posteriormente
 * un objeto ProductoMedicamento. Esta fábrica encapsula la configuración
 * del producto para que la creación sea consistente.
 */
MedicamentoFactory::MedicamentoFactory(int codigo, std::string nombre, double precio,
	int cantidad, std::string& administracion) : Codigo(codigo), Nombre(nombre),
	Precio(precio), Cantidad(cantidad), Administracion(administracion) {
}//inicializo atributos 

/**
 * @brief Crea una instancia de ProductoMedicamento.
 *
 * Implementación del Factory Method. Devuelve un nuevo producto
 * construido con los datos almacenados en la fábrica.
 * retorno un puntero al objeto ProductoMedicamento
 */
Producto* MedicamentoFactory::crearProducto() const {
	return new ProductoMedicamento(Codigo, Nombre, Precio, Cantidad, Administracion);
}