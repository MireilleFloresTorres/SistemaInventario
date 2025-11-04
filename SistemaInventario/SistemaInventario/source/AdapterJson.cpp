#include"Prerequisites.h"
#include"AdapterJson.h"
#include"Producto/Producto.h"
#include"Producto/ProductoConcreto/ProductoBebida.h"
#include"Producto/ProductoConcreto/ProductoComida.h"
#include"Producto/ProductoConcreto/ProductoMedicamento.h"

AdapterJson::AdapterJson(const std::string& archivo) : name(archivo) {}

bool AdapterJson::saveProductos(const std::vector<Producto*>& productos) {
    json j;
    j["productos"] = json::array();

    for (const auto& producto : productos) {
        json productoJson;
        productoJson["codigo"] = producto->getCodigo();
        productoJson["nombre"] = producto->getNombre();
        productoJson["precio"] = producto->getPrecio();
        productoJson["cantidad"] = producto->getCantidad();
        productoJson["tipo"] = producto->getTipo();

        // Datos específicos según el tipo
        if (producto->getTipo() == "Comida") {
            ProductoComida* comida = dynamic_cast<ProductoComida*>(producto);
            if (comida) {
                productoJson["caducidad"] = comida->getCaducidad();
            }
        }
        else if (producto->getTipo() == "Bebida") {
            ProductoBebida* bebida = dynamic_cast<ProductoBebida*>(producto);
            if (bebida) {
                productoJson["azucares"] = bebida->getAzucares();
            }
        }
        else if (producto->getTipo() == "Medicamento") {
            ProductoMedicamento* medicamento = dynamic_cast<ProductoMedicamento*>(producto);
            if (medicamento) {
                productoJson["administracion"] = medicamento->getAdministracion();
            }
        }

        j["productos"].push_back(productoJson);
    }

    // Guardar en archivo
    std::ofstream archivo(name);
    if (!archivo.is_open()) {
        std::cout << "Error: No se pudo abrir el archivo para guardar." << std::endl;
        return false;
    }

    archivo << j.dump(4); // Formato con indentación de 4 espacios
    archivo.close();

    std::cout << "Inventario guardado exitosamente en " << name << std::endl;
    return true;
}

std::vector<Producto*> AdapterJson::cargarProductos() {
    std::vector<Producto*> productos;

    std::ifstream archivo(name);
    if (!archivo.is_open()) {
        std::cout << "No se encontró el archivo " << name << ". Iniciando con inventario vacío." << std::endl;
        return productos;
    }

    json j;
    try {
        archivo >> j;

        if (j.contains("productos") && j["productos"].is_array()) {
            for (const auto& item : j["productos"]) {
                std::string tipo = item["tipo"];
                int codigo = item["codigo"];
                std::string nombre = item["nombre"];
                double precio = item["precio"];
                int cantidad = item["cantidad"];

                Producto* producto = nullptr;

                if (tipo == "Comida") {
                    std::string Caducidad = item["caducidad"];
                    producto = new ProductoComida(codigo, nombre, precio, cantidad, Caducidad);
                }
                else if (tipo == "Bebida") {
                    int Azucares = item["azucares"];
                    producto = new ProductoBebida(codigo, nombre, precio, cantidad, Azucares);
                }
                else if (tipo == "Medicamento") {
                    std::string Administracion = item["administracion"];
                    producto = new ProductoMedicamento(codigo, nombre, precio, cantidad, Administracion);
                }

                if (producto) {
                    productos.push_back(producto);
                }
            }

            std::cout << "Inventario cargado exitosamente desde " << name << std::endl;
            std::cout << "Total de productos cargados: " << productos.size() << std::endl;
        }
    }
    catch (const json::exception& e) {
        std::cout << "Error al leer el archivo JSON: " << e.what() << std::endl;
    }

    archivo.close();
    return productos;
}