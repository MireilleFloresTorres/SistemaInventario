#pragma once
#include "Producto/Inventario/Inventario.h"
#include "Ticket/Ticket.h"
#include "Ticket/TicketGasolinera.h"
#include "Ticket/Gasolinera.h"
#include "Strategy/PagoStrategy.h"


class
SistemaFacade {

public:
    ~SistemaFacade();
    static SistemaFacade* getInstance();

    bool 
    procesarVentaFarmacia(int codigoProducto, int cantidad, int metodoPago, const std::string& correo = "");

    bool 
    procesarCargaGasolinera(int tipoCombustible, double litros, int metodoPago, const std::string& correo = "");

    // Acceso al inventario
    Inventario* getInventario();

private:
    static SistemaFacade* instance;
    Inventario* inventario;
    Gasolinera* gasolinera;

    SistemaFacade();
    SistemaFacade(const SistemaFacade&) = delete;
    SistemaFacade& operator=(const SistemaFacade&) = delete;
};