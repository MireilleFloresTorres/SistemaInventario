#include "Prerequisites.h"
#include "Ticket/GenerarTicket.h"

/**
 * @brief Genera y administra números de ticket.
 */
int 
GenerarTicket::contadorTickets = 1; 

/**
 * @brief Obtiene el siguiente número de ticket.
 * @return Número de ticket incremental.
 */
int 
GenerarTicket::getNum() {
	return contadorTickets++; 
}

/**
 * @brief Genera un archivo de texto con la información del ticket.
 * @param ticket Ticket con los datos a escribir.
 * @return true si el archivo se generó correctamente, false en caso contrario.
 */
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

    archivo << " SUPERMARKET \n";
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