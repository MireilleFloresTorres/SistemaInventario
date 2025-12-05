#pragma once
#include"Prerequisites.h"
#include"Ticket/Ticket.h"

/**
 * @class Correo
 * @brief Para simulacion de información por correo.
 */
class
Correo {
public: 

    /**
     * @brief Envía por correo la factura generada a partir de un ticket.
     * @param ticket Ticket del cual se obtiene la información de facturación.
     * @param correo Dirección de correo destino.
     */
	static void facturaCorreo(const Ticket& ticket, const std::string& correo); 
};