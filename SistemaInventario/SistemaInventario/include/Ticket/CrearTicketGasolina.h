#pragma once

#include "Ticket/TicketGasolinera.h"

class CrearTicketGasolinera {
private:
    static int contador;

public:
    static bool generarArchivo(const TicketGasolinera& ticket);
    static int getNum();
    static std::string numeroATexto(double numero);
};