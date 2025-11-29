#include"Ticket/Proveedor.h"

Proveedor::Proveedor() : precioMagna(22.50), precioPremium(24.80), precioDiesel(25.10), _strategy(nullptr), sumTotal(0.0) {}

Proveedor::~Proveedor() {
    if (_strategy) {
        delete _strategy;
    }
}

void Proveedor::setPagoStrategy(PagoStrategy* s) {
    if (_strategy) {
        delete _strategy;
    }
    _strategy = s;
}

double Proveedor::getPrecio(TipoCombustible tipo) {
    switch (tipo) {
    case TipoCombustible::MAGNA: return precioMagna;
    case TipoCombustible::PREMIUM: return precioPremium;
    case TipoCombustible::DIESEL: return precioDiesel;
    default: return 0.0;
    }
}

std::string Proveedor::getNameGas(TipoCombustible tipo) {
    switch (tipo) {
    case TipoCombustible::MAGNA: return "Magna";
    case TipoCombustible::PREMIUM: return "Premium";
    case TipoCombustible::DIESEL: return "Diesel";
    default: return "Desconocido";
    }
}

double Proveedor::getsumTotal() const {
    return sumTotal;
}

bool Proveedor::cargarCombustible(TipoCombustible tipo, double litros) {
    if (litros <= 0) {
        std::cout << "Cantidad invalida" << std::endl;
        return false;
    }

    double precio = getPrecio(tipo);
    double total = litros * precio;

    std::cout << "\nLitros: " << litros << std::endl;
    std::cout << "Precio por litro: " << precio << std::endl;
    std::cout << "Total a pagar: " << total << std::endl;

    if (!_strategy) {
        std::cout << "Metodo de pago no configurado" << std::endl;
        return false;
    }

    std::cout << "\nProcesando pago..." << std::endl;
    if (_strategy->gestionarPago(total)) {
        sumTotal = total;
        std::cout << "\nCarga completada" << std::endl;
        return true;
    }

    std::cout << "Pago rechazado" << std::endl;
    return false;
}