#pragma once

#include "Ticket/TicketGasolinera.h"
#include "TicketGasolinera.h"

TicketGasolinera::TicketGasolinera(int numero)
    : numeroTicket(numero),
    litros(0),
    precioLitro(0),
    subtotal(0),
    iva(0),
    total(0),
    direccion("Av. Universidad 456, Col. Centro"),
    rfc("GAS123456ABC"),
    sucursal("Sucursal 301 - Queretaro"),
    regimenFiscal("601 - General de Ley Personas Morales") {
}

void 
TicketGasolinera::setFechaHora(const std::string& f, const std::string& h) {
    fecha = f;
    hora = h;
}

void 
TicketGasolinera::setDatos(const std::string& dir, const std::string& rfcSuc, const std::string& suc) {
    direccion = dir;
    rfc = rfcSuc;
    sucursal = suc;
}

void 
TicketGasolinera::setCombustible(const std::string& tipo, double lts, double precio) {
    tipoCombustible = tipo;
    litros = lts;
    precioLitro = precio;
}

void setMetodoPago(const std::string& metodo);
void 

TicketGasolinera::setNumeroAutorizacion(const std::string& num) {
    numeroAutorizacion = num;
}

void 
TicketGasolinera::setCorreo(const std::string& email) {
    correo = email;
}

void
TicketGasolinera::calcularTotal() {
    subtotal = litros * precioLitro;
    iva = subtotal * 0.16;
    total = subtotal + iva;
    codigoBarras = generarCodigoBarras();
}

std::string TicketGasolinera::generarCodigoBarras() {
    return "||" + std::to_string(numeroTicket) + rfc + std::to_string((int)total) + "||";
}

int TicketGasolinera::getNumeroTicket() const { return numeroTicket; }
double TicketGasolinera::getTotal() const { return total; }
std::string TicketGasolinera::getFecha() const { return fecha; }
std::string TicketGasolinera::getHora() const { return hora; }
std::string TicketGasolinera::getTipoCombustible() const { return tipoCombustible; }
double TicketGasolinera::getLitros() const { return litros; }
double TicketGasolinera::getPrecioLitro() const { return precioLitro; }
double TicketGasolinera::getSubtotal() const { return subtotal; }
double TicketGasolinera::getIva() const { return iva; }
std::string TicketGasolinera::getMetodoPago() const { return metodoPago; }
std::string TicketGasolinera::getNumeroAutorizacion() const { return numeroAutorizacion; }
std::string TicketGasolinera::getCodigoBarras() const { return codigoBarras; }
std::string TicketGasolinera::getDireccion() const { return direccion; }
std::string TicketGasolinera::getRFC() const { return rfc; }
std::string TicketGasolinera::getSucursal() const { return sucursal; }
std::string TicketGasolinera::getRegimenFiscal() const { return regimenFiscal; }
std::string TicketGasolinera::getCorreo() const { return correo; }