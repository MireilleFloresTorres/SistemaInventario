#include"Ticket/Proveedor.h"

/**
 * @class Proveedor
 * @brief Gestiona precios de GASOLINASs y el procesamiento de pagos en una carga.
 */

Proveedor::Proveedor() : precioMagna(22.50), precioPremium(24.80), precioDiesel(25.10), _strategy(nullptr), sumTotal(0.0) {}

Proveedor::~Proveedor() {
    if (_strategy) {
        delete _strategy;
    }
}

/**
 * @brief Establece la estrategia de pago a utilizar.
 * @param s Estrategia de pago.
 */
void Proveedor::setPagoStrategy(PagoStrategy* s) {
    if (_strategy) {
        delete _strategy;
    }
    _strategy = s;
}

/**
 * @brief Obtiene el precio por litro según el tipo de combustible.
 * @param tipo Tipo de combustible solicitado.
 * @return Precio del combustible.
 */
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

/**
 * @brief Obtiene el total cobrado en la última operación.
 */

double Proveedor::getsumTotal() const {
    return sumTotal;
}

/**
 * @brief Ejecuta la carga de combustible y procesa el pago.
 * @return true si la operación fue exitosa; false si falla el pago o la cantidad es inválida.
 */
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