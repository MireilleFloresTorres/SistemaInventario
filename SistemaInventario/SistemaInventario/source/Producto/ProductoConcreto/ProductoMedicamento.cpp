#include"Producto/ProductoConcreto/ProductoMedicamento.h"

ProductoMedicamento::ProductoMedicamento(int codigo, std::string nombre, double precio,
    int cantidad, std::string administracion)
    : Producto(codigo, nombre, precio, cantidad), Administracion(administracion) {
}

std::string
ProductoMedicamento::getAdministracion() const {
    return Administracion;
}

void
ProductoMedicamento::setAdministracion(const std::string& administracion){
    Administracion = administracion;
}
std::string ProductoMedicamento::getTipo() const {
    return "Medicamento";
}
void
ProductoMedicamento::showInfo() const {
    std::cout << "Código: " << getCodigo() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Precio: " << getPrecio() << std::endl;
    std::cout << "Cantidad: " << getCantidad() << std::endl;
    std::cout << "Caducidad: " << getAdministracion() << std::endl;
}