#include"Ticket/Correo.h"
#include"Ticket/Ticket.h"

void Correo::facturaCorreo(const Ticket& ticket, const std::string& correo) {
	std::cout << "La factura ha sido enviada a: " <<correo<< std::endl; 
	std::cout << "Ticket# " << ticket.getnumTicket() << std::endl; 
	std::cout << "Fech : " << ticket.getFecha() << std::endl; 
	std::cout << ticket.getHora() << std::endl; 

	std::cout << "Productos: "<< std::endl; 

	for (const auto& product : product.addProducts()) {

		std::cout << product.nameProduct << product.cantidad << product.subtotal << std::endl; 
	}
}