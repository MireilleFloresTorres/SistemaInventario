#pragma once
#include"Ticket.h"

/**
 * @class GenerarTicket
 * @brief Genera archivos de tickets y lleva control interno del conteo.
 */
class
GenerarTicket {
public: 
	/** @brief Genera un archivo a partir del ticket dado. */
	static bool generarArchivo(const Ticket& ticket);

	/** @brief Obtiene el número actual de tickets generados. */
	static int getNum(); 

private: 
	static int contadorTickets; ///< Contador interno.
};