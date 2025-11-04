#include "Prerequisites.h"
#include "Producto/Inventario/Inventario.h"


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
        string mensaje = "El producto '" + producto->getNombre() +
            "' (Codigo: " + to_string(producto->getCodigo()) +
            ") tiene stock bajo: " + to_string(producto->getCantidad()) + " unidades";
        notificar(mensaje);
    }
}

void Inventario::addProducto(Producto* producto) {
    productos.push_back(producto);
    cout << "Producto agregado exitosamente." << endl;
    StockBajo(producto);
}

bool Inventario::eliminarProducto(int Codigo) {
    for (size_t i = 0; i < productos.size(); i++) {
        if (productos[i]->getCodigo() == Codigo) {
            delete productos[i];
            productos[i] = productos.back();
            productos.pop_back();
            cout << "Producto eliminado exitosamente." << endl;
            return true;
        }
    }
    cout << "Producto no encontrado." << endl;
    return false;
}

bool Inventario::editarProducto(int Codigo) {
    Producto* producto = buscarProducto(Codigo);
    if (!producto) {
        cout << "Producto no encontrado." << endl;
        return false;
    }

    producto->showInfo();

    string nuevoNombre;
    double nuevoPrecio;
    int nuevaCantidad;

    cout << "Nuevo nombre: " << producto->getNombre() << "): ";
    cin.ignore();
    getline(cin, nuevoNombre);

    cout << "Nuevo precio: $" << producto->getPrecio() << "): ";
    cin >> nuevoPrecio;

    cout << "Nueva cantidad: " << producto->getCantidad() << "): ";
    cin >> nuevaCantidad;

    producto->setNombre(nuevoNombre);
    producto->setPrecio(nuevoPrecio);
    producto->setCantidad(nuevaCantidad);

    cout << "Producto editado yeii" << endl;
    StockBajo(producto);
    return true;
}

bool Inventario::venderProducto(int Codigo, int Cantidad) {
    Producto* producto = buscarProducto(Codigo);
    if (!producto) {
        cout << "Producto no encontrado :( " << endl;
        return false;
    }

    if (producto->getCantidad() < Cantidad) {
        cout << "Stock insuficiente. Tu stock disponible: " << producto->getCantidad() << endl;
        return false;
    }

    producto->setCantidad(producto->getCantidad() - Cantidad);
    cout << "Venta realizada :) Stock restante: " << producto->getCantidad() << endl;
    StockBajo(producto);
    return true;
}

bool Inventario::comprarProducto(int Codigo, int Cantidad) {
    Producto* producto = buscarProducto(Codigo);
    if (!producto) {
        cout << "Producto no encontrado :(" << endl;
        return false;
    }

    producto->setCantidad(producto->getCantidad() + Cantidad);
    cout << "Compra registrada el nuevo stock es de: " << producto->getCantidad() << endl;
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
        cout << "El inventario esta vacio." << endl;
        return;
    }

    cout << "INVENTARIO" << endl;
    for (const auto& producto : productos) {
        producto->showInfo();
        cout << "--------------------------------" << endl;
    }
}

const vector<Producto*>& Inventario::getProductos() const {
    return productos;
}

bool Inventario::saveJSON(const string& name) {
    AdapterJson adapter(name);
    return adapter.saveProductos(productos);
}

void Inventario::cargarJSON(const string& name) {
    AdapterJson adapter(name);
    vector<Producto*> productosNuevos = adapter.cargarProductos();

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
