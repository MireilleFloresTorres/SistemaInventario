#pragma once
#include "Prerequisites.h"

class TicketGasolinera {
public:
    TicketGasolinera(int numero);

    // Setters
    void setFechaHora(const std::string& f, const std::string& h);
    void setDatos(const std::string& dir, const std::string& rfcSuc, const std::string& suc);
    void setCombustible(const std::string& tipo, double lts, double precio);
    void setMetodoPago(const std::string& metodo, const std::string& meses = "");
    void setNumeroAutorizacion(const std::string& num);
    void setCorreo(const std::string& email);

    // Operaciones
    void calcularTotal();
    std::string generarCodigoBarras();

    // Getters
    int getNumeroTicket() const;
    double getTotal() const;
    std::string getFecha() const;
    std::string getHora() const;
    std::string getTipoCombustible() const;
    double getLitros() const;
    double getPrecioLitro() const;
    double getSubtotal() const;
    double getIva() const;
    std::string getMetodoPago() const;
    std::string getNumeroAutorizacion() const;
    std::string getCodigoBarras() const;
    std::string getDireccion() const;
    std::string getRFC() const;
    std::string getSucursal() const;
    std::string getRegimenFiscal() const;
    std::string getCorreo() const;

private:
    int numeroTicket;
    std::string fecha;
    std::string hora;
    std::string direccion;
    std::string rfc;
    std::string sucursal;
    std::string tipoCombustible;
    double litros;
    double precioLitro;
    double subtotal;
    double iva;
    double total;
    std::string metodoPago;
    std::string mesesSinIntereses;
    std::string numeroAutorizacion;
    std::string codigoBarras;
    std::string regimenFiscal;
    std::string correo;


};