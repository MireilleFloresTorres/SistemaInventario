#include "Prerequisites.h"
#include "Producto/Inventario/Inventario.h"
#include "AdapterJson.h"

/**
 * @class Inventario
 * @brief Implementación del patrón Singleton para gestionar productos.
 *
 * Mantiene un vector de punteros a Producto, permitiendo agregar, eliminar,
 * buscar y editar productos. También notifica cuando el stock está bajo.
 */
Inventario* Inventario::intancia = nullptr;
int Inventario::nextId = 1;

Inventario::Inventario() {}

Inventario::~Inventario() {
    //se recorre el vector con auto qy el vector almacena
    // punteros y eliminamos manualemente  
    for (auto producto : productos) {
        delete producto;
    }
}

/**
 * @brief Obtiene la instancia única del inventario
 */
Inventario* Inventario::getInstance() {
    if (intancia == nullptr) {
        intancia = new Inventario();
    }
    return intancia;
}

/**
 * @brief Suma n nuevo id al nuevo objeto en el inventario
 */
int 
Inventario::getNextId() {
    return nextId++;
}

void Inventario::StockBajo(Producto* producto) {
    if (producto->getCantidad() < 10) {
        std::string alerta = "El producto '" + producto->getNombre() +
            "' (Codigo: " + std::to_string(producto->getCodigo()) +
            ") tiene stock bajo: " 
            + std::to_string(producto->getCantidad()) + " unidades";
        notificar(alerta);
    }
}

/**
 * @brief Agrega un producto al inventario.
 * el push_back inserta al final del vectos ell puntero 
 * copia el puntero no el objeto
 */
void Inventario::addProducto(Producto* producto) {
    productos.push_back(producto);
    std::cout << "Producto agregado" << std::endl;
    StockBajo(producto);
}

/**
 * @brief Elimina un producto por código.
 * se recorre al vectorr comparando los punteros 
 * gracias estrutucura de datos
 * entonces se reemplza por el ultimo y llamamos el 
 * pop_back
 */
bool Inventario::deleteProducto(int Codigo) {
    for (size_t i = 0; i < productos.size(); i++) {
        if (productos[i]->getCodigo() == Codigo) {
            delete productos[i];// aui libero memroria
            productos[i] = productos.back();//SE MUEVE EL ULTIMO A LA POSICIOn eliminadda
            productos.pop_back();
            std::cout << "Producto eliminado" << std::endl;
            return true;
        }
    }
    std::cout << "Producto no encontrado." << std::endl;
    return false;
}

/**
 * Realiza la venta de un producto restando stock.
 * Retorna false si no existe el producto o no hay cantidad suficiente.
 */
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

/**
 * Realiza la venta de un producto restando stock.
 * Retorna false si no existe el producto o no hay cantidad suficiente.
 */
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

/**
 * Incrementa la cantidad en inventario de un producto existente.
 * Retorna false si el producto no fue encontrado.
 * cuando se compra suma la cantidad a la cantidad ya existente 
 */
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

/**
 * Busca un producto por su código y retorna su puntero.
 * Retorna nullptr si no existe.
 */
Producto* Inventario::buscarProducto(int codigo) {
    for (auto producto : productos) {
        if (producto->getCodigo() == codigo) {
            return producto;
        }
    }
    return nullptr;
}

/**
 * @brief Muestra todos los productos.
 * Productos.empty() sice si el inventario esta vacio 
 */
void Inventario::mostrarTodos() const {
    if (productos.empty()) {
        std::cout << "El inventario esta vacio." << std::endl;
        return;
    }

    //con el const auto& es para no copiar el objeto 
    std::cout << "INVENTARIO" << std::endl;
    //referencia constante
    for (const auto& producto : productos) {
        producto->showInfo();
        std::cout << "--------------------------------" << std::endl;
    }

}

/**
 * Retorna una referencia constante al vector de productos del inventario.
 * Permite consultar los productos sin permitir modificaciones externas.
 */
const std::vector<Producto*>& Inventario::getProductos() const {
    return productos;
}

/**
 * Guarda los productos en mi archivo json.
 * se usa un adaptador para manejrar el proceso.
 * retorna true si ha salido correctamente
 */
bool Inventario::saveJSON(const std::string& name) {
    AdapterJson adapter(name);
    return adapter.saveProductos(productos);
}

/**
 * Carga desde json y agrega al inventario 
 * entonces envalua los objetos/productos
 * para ver si tiene o no un stock bajo 
 * actualiza el id siguiente posible
 */
void Inventario::cargarJSON(const std::string& name) {
    AdapterJson adapter(name);
    std::vector<Producto*> productosNuevos = adapter.cargarProductos();

    for (auto producto : productosNuevos) {
        productos.push_back(producto);
        StockBajo(producto);
    }

    actualizarNextId();
}

/**
 * Actualiza el valor interno del siguiente ID basado en el ID más alto registrado.
 * Recorre todos los productos para asegurar unicidad.
 * Establece nextId al valor máximo encontrado más uno.
 */
void Inventario::actualizarNextId() {
    int maxID = 0;
    for (const auto& producto : productos) {
        if (producto->getCodigo() > maxID) {
            maxID = producto->getCodigo();
        }
    }
    nextId = maxID + 1;
}
