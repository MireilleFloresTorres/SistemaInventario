#pragma once
#include"Prerequisites.h"
#include"Ticket/Ticket.h"

class
Correo {
public: 

	static void facturaCorreo(const Ticket& ticket, const std::string& correo); 
};