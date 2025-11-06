#include"Producto/ProductoConcreto/ProductoMedicamento.h"

/**
 * @brief Constructor de ProductoMedicamen.
 */
ProductoMedicamento::ProductoMedicamento(int codigo, std::string nombre, double precio,
    int cantidad, std::string administracion)
    : Producto(codigo, nombre, cantidad, precio), Administracion(administracion) {
}

/**
 * @brief Obtiene la fecha la via de administracion
 */
std::string
ProductoMedicamento::getAdministracion() const {
    return Administracion;
}

/**
 * @Establece el tipo de administracion
 */
void
ProductoMedicamento::setAdministracion(const std::string& administracion){
    Administracion = administracion;
}

/**
 * @brief Retorna el tipo de producto.
 */
std::string ProductoMedicamento::getTipo() const {
    return "Medicamento";
}

/**
 * @brief Muestra la información completa del producto.
 */
void
ProductoMedicamento::showInfo() const {
    std::cout << "Código: " << getCodigo() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Precio: " << getPrecio() << std::endl;
    std::cout << "Cantidad: " << getCantidad() << std::endl;
    std::cout << "Caducidad: " << getAdministracion() << std::endl;
}