#include "Ticket/TicketGasolinera.h"

/**
 * @brief Representa un ticket de compra de gasolina.
 *
 * Guarda datos del combustible, método de pago y totales
 * generados durante la transacción.
 */
TicketGasolinera::TicketGasolinera(int numero)
    : numeroTicket(numero),
    litros(0),
    precioLitro(0),
    subtotal(0),
    iva(0),
    total(0),
    direccion("Av. Rosales, Col. Juarez"),
    rfc("GAS09078PLJ"),
    sucursal("Sucursal 301"),
    regimenFiscal("601 - General de Ley Personas Morales"),
    mesesSinIntereses("1 Exhibicion") {
}


/**
 * @brief Establece fecha y hora del ticket.
 */
void TicketGasolinera::setFechaHora(const std::string& f, const std::string& h) {
    fecha = f;
    hora = h;
}


/**
 * @brief Configura datos generales del establecimiento.
 */
void TicketGasolinera::setDatos(const std::string& dir, const std::string& rfcSuc, const std::string& suc) {
    direccion = dir;
    rfc = rfcSuc;
    sucursal = suc;
}

/**
 * @brief Define el combustible cargado, litros y precio por litro.
 */
void TicketGasolinera::setCombustible(const std::string& tipo, double lts, double precio) {
    tipoCombustible = tipo;
    litros = lts;
    precioLitro = precio;
}

/**
 * @brief Configura método de pago y meses sin intereses.
 */
void TicketGasolinera::setMetodoPago(const std::string& metodo, const std::string& meses) {
    metodoPago = metodo;
    if (!meses.empty()) {
        mesesSinIntereses = meses;
    }
}

/**
 * @brief Establece el número de autorización del pago.
 */
void TicketGasolinera::setNumeroAutorizacion(const std::string& num) {
    numeroAutorizacion = num;
}

/**
 * @brief Guarda el correo para enviar factura.
 */
void TicketGasolinera::setCorreo(const std::string& email) {
    correo = email;
}

/**
 * @brief Calcula subtotal, IVA y total.
 * También genera el código de barras del ticket.
 */
void TicketGasolinera::calcularTotal() { 
    subtotal = litros * precioLitro;
    iva = subtotal * 0.16;
    total = subtotal + iva;
    codigoBarras = generarCodigoBarras();
}

/**
 * @brief Genera un código de barras simple basado en datos del ticket.
 */
std::string TicketGasolinera::generarCodigoBarras() {
    return "||" + std::to_string(numeroTicket) + rfc + std::to_string((int)total) + "||";
}
// Getters
int TicketGasolinera::getNumeroTicket() const {
    return numeroTicket;
}

double TicketGasolinera::getTotal() const {
    return total;
}

std::string TicketGasolinera::getFecha() const {
    return fecha;
}

std::string TicketGasolinera::getHora() const {
    return hora;
}

std::string TicketGasolinera::getTipoCombustible() const {
    return tipoCombustible;
}

double TicketGasolinera::getLitros() const {
    return litros;
}

double TicketGasolinera::getPrecioLitro() const {
    return precioLitro;
}

double TicketGasolinera::getSubtotal() const {
    return subtotal;
}

double TicketGasolinera::getIva() const {
    return iva;
}

std::string TicketGasolinera::getMetodoPago() const {
    return metodoPago;
}

std::string TicketGasolinera::getNumeroAutorizacion() const {
    return numeroAutorizacion;
}

std::string TicketGasolinera::getCodigoBarras() const {
    return codigoBarras;
}

std::string TicketGasolinera::getDireccion() const {
    return direccion;
}

std::string TicketGasolinera::getRFC() const {
    return rfc;
}

std::string TicketGasolinera::getSucursal() const {
    return sucursal;
}

std::string TicketGasolinera::getRegimenFiscal() const {
    return regimenFiscal;
}

std::string TicketGasolinera::getCorreo() const {
    return correo;
}