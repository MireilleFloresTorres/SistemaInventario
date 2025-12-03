#include "Ticket/CrearTicketGasolina.h"


int CrearTicketGasolinera::contador = 1000;

int CrearTicketGasolinera::getNum() {
    return contador++;
}

std::string CrearTicketGasolinera::numeroATexto(double numero) {
    int entero = (int)numero;
    int centavos = (int)((numero - entero) * 100);
    return std::to_string(entero) + " Pesos " + std::to_string(centavos) + "100";
}

bool CrearTicketGasolinera::generarArchivo(const TicketGasolinera& ticket) {
    std::string nombre = "ticket_gas_" + std::to_string(ticket.getNumeroTicket()) + ".txt";
    std::ofstream archivo(nombre);

    if (!archivo.is_open()) {
        std::cout << "Error al crear ticket" << std::endl;
        return false;
    }

    archivo << "SUPERMARKET\n";
    archivo << ticket.getDireccion() << "\n";
    archivo << "RFC: " << ticket.getRFC() << "\n";
    archivo << ticket.getSucursal() << "\n";
    archivo << "----------------------------------------\n";
    archivo << "Ticket: " << ticket.getNumeroTicket() << "\n";
    archivo << "Fecha: " << ticket.getFecha() << "\n";
    archivo << "Hora: " << ticket.getHora() << "\n";

    archivo << "Producto: " << ticket.getTipoCombustible() << "\n";
    archivo << "Litros: " << ticket.getLitros() << "\n";
    archivo << "Precio/Litro: " << ticket.getPrecioLitro() << "\n\n";

    archivo << "Subtotal: " << ticket.getSubtotal() << "\n";
    archivo << "IVA (16%): " << ticket.getIva() << "\n";
    archivo << "----------------------------------------\n";
    archivo << "TOTALL: " << ticket.getTotal() << "\n";
    archivo << "En texto: " << numeroATexto(ticket.getTotal()) << "\n\n";

    archivo << "Metodo de Pago: " << ticket.getMetodoPago() << "\n";

    if (!ticket.getNumeroAutorizacion().empty()) {
        archivo << "No. Autorizacion: " << ticket.getNumeroAutorizacion() << "\n";
    }

    archivo << "\nRegimen Fiscal:\n" << ticket.getRegimenFiscal() << "\n\n";
    archivo << "Codigo de Barras:\n" << ticket.getCodigoBarras() << "\n\n";

    if (!ticket.getCorreo().empty()) {
        archivo << "Factura enviada a: " << ticket.getCorreo() << "\n";
    }
    archivo.close();
    std::cout << "Ticket generado: " << nombre << std::endl;
    return true;
}