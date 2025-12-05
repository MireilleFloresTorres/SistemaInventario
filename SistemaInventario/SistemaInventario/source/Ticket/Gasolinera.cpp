#include"Ticket/Gasolinera.h"

/**
 * @brief Implementación Singleton de la gasolinera.
 * @details Gestiona y expone un único proveedor de combustible.
 */
Gasolinera* Gasolinera::instance = nullptr;

Gasolinera::Gasolinera() {
   proveedor = new Proveedor();
}

Gasolinera::~Gasolinera() {
    delete proveedor;
}

/**
 * @brief Obtiene la instancia única de Gasolinera.
 * @return Instancia del Singleton.
 */
Gasolinera* Gasolinera::getInstance() {
    if (instance == nullptr) {
        instance = new Gasolinera();
    }
    return instance;
}

/**
 * @brief Devuelve el proveedor de combustible.
 * @return Puntero al proveedor.
 */
Proveedor* Gasolinera::getProveedor() {
    return proveedor;
}