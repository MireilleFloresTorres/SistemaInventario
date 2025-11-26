#pragma once
#include"Ticket.h"

class
GenerarTicket {
public: 
	static bool generarArchivo(const Ticket& ticket);
	static int getNum(); 

private: 
	static int contadorTickets; 
};