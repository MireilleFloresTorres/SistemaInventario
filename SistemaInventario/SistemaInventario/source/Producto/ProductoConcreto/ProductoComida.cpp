#include"Producto/ProductoConcreto/ProductoComida.h"

/**
 * @brief Constructor de ProductoComida.
 */
ProductoComida::ProductoComida(int codigo, std::string nombre, double precio,
    int cantidad, std::string caducidad)
    : Producto(codigo, nombre, cantidad, precio), Caducidad(caducidad) {
}

/**
 * @brief Obtiene la fecha de caducidad.
 */
std::string ProductoComida::getCaducidad() const {
    return Caducidad;
}

/**
 * @me da el cambio de aducicad
 */
void
ProductoComida::setCaducidad(const std::string& fecha) {
    Caducidad = fecha;
}

/**
 * @brief Retorna el tipo de producto.
 */
std::string ProductoComida::getTipo() const {
    return "Comida";
}

/**
 * @brief Muestra la información completa del producto.
 */
void
ProductoComida::showInfo() const {
    std::cout << "Codigo: " << getCodigo() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Precio: " << getPrecio() << std::endl;
    std::cout << "Cantidad: " << getCantidad() << std::endl;
    std::cout << "Caducidad: " << getCaducidad() << std::endl;
}
