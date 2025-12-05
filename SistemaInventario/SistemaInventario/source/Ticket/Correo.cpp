#include"Ticket/Correo.h"
#include"Ticket/Ticket.h"

/**
 * @brief Envía por consola la información del ticket simulando el envío de una factura por correo.
 * @param ticket Ticket con los datos de compra.
 * @param correo Dirección de correo destino.
 */
void Correo::facturaCorreo(const Ticket& ticket, const std::string& correo) {
	std::cout << "La factura ha sido enviada a: " <<correo<< std::endl; 
	std::cout << "Ticket# " << ticket.getnumTicket() << std::endl; 
	std::cout << "Fech : " << ticket.getFecha() << std::endl; 
	std::cout << ticket.getHora() << std::endl; 

	std::cout << "Productos: "<< std::endl; 

	for (const auto& product : ticket.getProducts()) {
		std::cout << product.nameProduct << product.cantidad << product.subtotal << std::endl; 
	}

	std::cout << "Total: " << ticket.getTotal() << std::endl; 
	std::cout << "Metodo de pago: " << ticket.getMetodoPago()<<std::endl; 
	std::cout << "El correo ha sido jenviado" << std::endl; 
}