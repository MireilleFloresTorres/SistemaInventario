#pragma once
#include "Prerequisites.h"
#include "Producto/Producto.h"
#include "Producto/Observer/Sujeto.h"

class Inventario : public Sujeto {
public:
    ~Inventario();
    static Inventario* getInstance();
    static int getNextId();
    void addProducto(Producto* producto);
    bool deleteProducto(int Codigo);
    bool editarProducto(int Codigo);
    bool venderProducto(int Codigo, int Cantidad);
    bool comprarProducto(int Codigo, int Cantidad);
    void mostrarTodos() const;

    // Buscar producto
    Producto* buscarProducto(int codigo);
    const std::vector<Producto*>& getProductos() const;

    bool saveJSON(const std::string& name);
    void cargarJSON(const std::string& name);
    void actualizarNextId();

private:
    std::vector<Producto*> productos;
    static Inventario* intancia;
    static int nextId;

    // Constructor privado (Singleton)
    Inventario();

    // Eliminar constructor de copia y operador de asignación
    Inventario(const Inventario&) = delete;
    Inventario& operator=(const Inventario&) = delete;

    void StockBajo(Producto* producto);
};