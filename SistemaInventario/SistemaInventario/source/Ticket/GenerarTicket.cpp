#include "Prerequisites.h"
#include "Ticket/GenerarTicket.h"

int 
GenerarTicket::contadorTickets = 1; 

int 
GenerarTicket::getNum() {
	return contadorTickets++; 
}

bool 
GenerarTicket::generarArchivo(const Ticket& ticket) {
    std::string nombreArchivo = "ticket_" + std::to_string(ticket.getnumTicket()) + ".txt";

    std::ofstream archivo(nombreArchivo);
    //segun escribimos un archivo con esto
    //creamos un archivo 
    //ifstream deberíamos leerlo
    if (!archivo.is_open()) {
        std::cout << " Ha ocurrido un error al crear un ticket" << std::endl;
        return false;
    }

    archivo << " FARMACIA GUADALAJARA\n";
    archivo << "Ticket: " << ticket.getnumTicket()<< "\n";

    archivo << "Fecha: " << ticket.getFecha() << " " << ticket.getHora() << "\n";

    for (const auto& product : ticket.getProducts()) {
        archivo << product.nameProduct<< "\n";
        archivo <<"Cantidad: "<<product.cantidad<< product.precioU << "\n";
        archivo <<"Subtoal: "<<product.subtotal<< "\n";
    }

    archivo << "Total: " << ticket.getTotal() << "\n";
    archivo << "Pago: " << ticket.getMetodoPago() << "\n";

    archivo.close();
    //esto es para cerrar el txt que ojala sisirva 
    //guarda todo
    std::cout << "Ticket generado: " << nombreArchivo << std::endl;
    return true;
}