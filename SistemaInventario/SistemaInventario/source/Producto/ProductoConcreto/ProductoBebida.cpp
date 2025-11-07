#include"Producto/ProductoConcreto/ProductoBebida.h"

/**
 * @brief Constructor de ProductoComida.
 */
ProductoBebida::ProductoBebida(int codigo, std::string nombre, double precio,
    int cantidad, int azucares)
    : Producto(codigo, nombre, cantidad, precio), Azucares(azucares) {
}

int 
ProductoBebida::getAzucares() const {
    return Azucares;
}

void
ProductoBebida::setAzucares(int azucares) {
    Azucares = azucares;
}
std::string ProductoBebida::getTipo() const {
    return "Bebida";
}
void
ProductoBebida::showInfo() const {
    std::cout << "Código: " << getCodigo() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Precio: " << getPrecio() << std::endl;
    std::cout << "Cantidad: " << getCantidad() << std::endl;
    std::cout << "Azucares: " << getAzucares() << std::endl;
}
