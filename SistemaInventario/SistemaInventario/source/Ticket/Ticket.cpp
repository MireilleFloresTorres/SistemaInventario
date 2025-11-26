#include"Ticket/Ticket.h"

Ticket::Ticket(int numero) : numTicket(numero), total(0.0), metodoPago("Efectivo") {}
//inicializo en ceroo y ppredefinido

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
void Ticket::addProduct(const std::string& nombre, int cantidad, double precio) {
	Iticket product; 
	product.nameProduct = nombre; 
	product.cantidad = cantidad; 
	product.precioU = precio; 
	product.subtotal = cantidad * precio; 
	products.push_back(product); 
}

int Ticket::getnumTicket() const { return numTicket; }
double Ticket::getTotal() const { return total; }
std::string Ticket::getFecha() const { return fecha; }
std::string Ticket::getHora() const { return hora; }
const std::vector<Iticket>& Ticket::getProducts() const { return products;  }
std::string Ticket::getMetodoPago() const { return metodoPago;}