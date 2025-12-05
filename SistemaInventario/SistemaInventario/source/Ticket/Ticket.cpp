#include"Ticket/Ticket.h"

/**
 * @brief Constructor de Ticket.
 * @param numero Número identificador del ticket.
 */
Ticket::Ticket(int numero) : numTicket(numero), total(0.0), metodoPago("Efectivo") {}
//inicializo en ceroo y ppredefinido

/**
 * @brief Establece la fecha y hora del ticket.
 * @param f Fecha en formato cadena.
 * @param h Hora en formato cadena.
 */
void
Ticket::setFechaHo(const std::string& f, const std::string& h) {
	fecha = f; 
	hora = h; 
}

void Ticket::setMetodoPago(const std::string& metodo) {
	metodoPago = metodo; 
}

void Ticket::calculoTotal() {
	total = 0.0; 
	for (const auto& product : products) {
		total += product.subtotal; 
	}
}

/**
 * @brief Añade un producto al ticket.
 * @param nombre Nombre del producto.
 * @param cantidad Cantidad vendida.
 * @param precio Precio unitario.
 *
 * Rellena un registro Iticket (nameProduct, cantidad, precioU, subtotal)
 * y lo añade al vector interno `products`.
 */
void Ticket::addProduct(const std::string& nombre, int cantidad, double precio) {
	Iticket product; 
	product.nameProduct = nombre; 
	product.cantidad = cantidad; 
	product.precioU = precio; 
	product.subtotal = cantidad * precio; 
	products.push_back(product); 
}

/** @brief Devuelve el número del ticket. */
int Ticket::getnumTicket() const { return numTicket; }

/** @brief Devuelve el total calculado del ticket. */
double Ticket::getTotal() const { return total; }
std::string Ticket::getFecha() const { return fecha; }

/** @brief Devuelve la hora del ticket. */
std::string Ticket::getHora() const { return hora; }

/**
 * @brief Devuelve la lista de productos del ticket.
 * @return Referencia constante al vector con los Iticket del ticket.
 */
const std::vector<Iticket>& Ticket::getProducts() const { return products; }//algo está mal y no sé que

std::string Ticket::getMetodoPago() const { return metodoPago;}