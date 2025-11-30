#include"Ticket/Gasolinera.h"

Gasolinera* Gasolinera::instance = nullptr;

Gasolinera::Gasolinera() {
   proveedor = new Proveedor();
}

Gasolinera::~Gasolinera() {
    delete proveedor;
}

Gasolinera* Gasolinera::getInstance() {
    if (instance == nullptr) {
        instance = new Gasolinera();
    }
    return instance;
}

Proveedor* Gasolinera::getProveedor() {
    return proveedor;
}