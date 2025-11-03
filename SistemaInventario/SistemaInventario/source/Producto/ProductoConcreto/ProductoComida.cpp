#include"Producto/ProductoConcreto/ProductoComida.h"

ProductoComida::ProductoComida(int codigo, std::string nombre, double precio,
    int cantidad, std::string& caducidad)
    : Producto(codigo, nombre, precio, cantidad), Caducidad(caducidad) {
}

std::string ProductoComida::getCaducidad() const {
    return Caducidad; 
}

 void
 ProductoComida::setCaducidad(const std::string& fecha) {
    Caducidad = fecha; 
}

 void
     ProductoComida::showInfo() const {
     std::cout << "Código: " << getCodigo <<std:: endl; 
     std::cout << "Nombre: " << getNombre<< std::endl;
     std::cout << "Precio: " << getPrecio << std::endl;
     std::cout << "Cantidad: " << getCantidad << std::endl;
     std::cout << "Caducidad: " << getCaducidad << std::endl;
 }
