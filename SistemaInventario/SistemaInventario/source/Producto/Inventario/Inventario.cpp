#include "Prerequisites.h"
#include "Producto/Inventario/Inventario.h"
#include "AdapterJson.h"

Inventario* Inventario::intancia = nullptr;
int Inventario::nextId = 1;

Inventario::Inventario() {}

Inventario::~Inventario() {
    for (auto producto : productos) {
        delete producto;
    }
}

Inventario* Inventario::getInstance() {
    if (intancia == nullptr) {
        intancia = new Inventario();
    }
    return intancia;
}

int Inventario::getNextId() {
    return nextId++;
}

void Inventario::StockBajo(Producto* producto) {
    if (producto->getCantidad() < 10) {
        std::string mensaje = "El producto '" + producto->getNombre() +
            "' (Codigo: " + std::to_string(producto->getCodigo()) +
            ") tiene stock bajo: " + std::to_string(producto->getCantidad()) + " unidades";
        notificar(mensaje);
    }
}

void Inventario::addProducto(Producto* producto) {
    productos.push_back(producto);
    std::cout << "Producto agregado" << std::endl;
    StockBajo(producto);
}

bool Inventario::deleteProducto(int Codigo) {
    for (size_t i = 0; i < productos.size(); i++) {
        if (productos[i]->getCodigo() == Codigo) {
            delete productos[i];
            productos[i] = productos.back();
            productos.pop_back();
            std::cout << "Producto eliminado exitosamente" << std::endl;
            return true;
        }
    }
    std::cout << "Producto no encontrado." << std::endl;
    return false;
}

bool Inventario::editarProducto(int Codigo) {
    Producto* producto = buscarProducto(Codigo);
    if (!producto) {
        std::cout << "Producto no encontrado" << std::endl;
        return false;
    }

    producto->showInfo();

    std::string nuevoNombre;
    double nuevoPrecio;
    int nuevaCantidad;

    std::cout << "Nuevo nombre : " << producto->getNombre() << "): ";
    std::cin.ignore();
    std::getline(std::cin, nuevoNombre);

    std::cout << "Nuevo precio: " << producto->getPrecio() << "): ";
    std::cin >> nuevoPrecio;

    std::cout << "Nueva cantidad: " << producto->getCantidad() << "): ";
    std::cin >> nuevaCantidad;

    producto->setNombre(nuevoNombre);
    producto->setPrecio(nuevoPrecio);
    producto->setCantidad(nuevaCantidad);

    std::cout << "Producto editado :)." << std::endl;
    StockBajo(producto);
    return true;
}

bool Inventario::venderProducto(int Codigo, int Cantidad) {
    Producto* producto = buscarProducto(Codigo);
    if (!producto) {
        std::cout << "Producto no encontrado :(" << std::endl;
        return false;
    }

    if (producto->getCantidad() < Cantidad) {
        std::cout << "Stock insuficient el stock disponible: " << producto->getCantidad() << std::endl;
        return false;
    }

    producto->setCantidad(producto->getCantidad() - Cantidad);
    std::cout << "Venta realizada. Stock restante: " << producto->getCantidad() << std::endl;
    StockBajo(producto);
    return true;
}

bool Inventario::comprarProducto(int Codigo, int Cantidad) {
    Producto* producto = buscarProducto(Codigo);
    if (!producto) {
        std::cout << "Producto no encontrado :(" << std::endl;
        return false;
    }

    producto->setCantidad(producto->getCantidad() + Cantidad);
    std::cout << "Compra registrada el nuuevo stock: " << producto->getCantidad() << std::endl;
    return true;
}

Producto* Inventario::buscarProducto(int codigo) {
    for (auto producto : productos) {
        if (producto->getCodigo() == codigo) {
            return producto;
        }
    }
    return nullptr;
}

void Inventario::mostrarTodos() const {
    if (productos.empty()) {
        std::cout << "El inventario esta vacio." << std::endl;
        return;
    }

    std::cout << "INVENTARIO" << std::endl;
    for (const auto& producto : productos) {
        producto->showInfo();
        std::cout << "--------------------------------" << std::endl;
    }

}

const std::vector<Producto*>& Inventario::getProductos() const {
    return productos;
}

bool Inventario::saveJSON(const std::string& name) {
    AdapterJson adapter(name);
    return adapter.saveProductos(productos);
}

void Inventario::cargarJSON(const std::string& name) {
    AdapterJson adapter(name);
    std::vector<Producto*> productosNuevos = adapter.cargarProductos();

    for (auto producto : productosNuevos) {
        productos.push_back(producto);
        StockBajo(producto);
    }

    actualizarNextId();
}

void Inventario::actualizarNextId() {
    int maxID = 0;
    for (const auto& producto : productos) {
        if (producto->getCodigo() > maxID) {
            maxID = producto->getCodigo();
        }
    }
    nextId = maxID + 1;
}
