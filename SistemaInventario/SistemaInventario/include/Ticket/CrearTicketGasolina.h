#pragma once
#include "Ticket/TicketGasolinera.h"

/**
 * @class CrearTicketGasolinera
 * @brief Genera archivos de tickets de gasolinera y administra un contador.
 */
class CrearTicketGasolinera {
private:
    static int contador;

public:
    /** @brief Genera un archivo a partir del ticket. */
    static bool generarArchivo(const TicketGasolinera& ticket);

    /** @brief Obtiene el número actual del contador. */
    static int getNum();

    /** @brief Convierte un número a texto. */
    static std::string numeroATexto(double numero);
};