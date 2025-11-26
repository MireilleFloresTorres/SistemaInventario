#pragma once
#include"Prerequisites.h"

class
Ticket {
public: 

	Ticket(int numero); //constructor
	//creamos, agreganoos fachas, producto y metodo y calculo

	void
	setFechaHo(const std::string& f, const std::string& h);

	void
	addProduct(const std::string& nombre, int cantidad, double precio); 

	void
	setMetodoPago(const std::string& metodo); 

	void calculoTotal(); 

	int getnumTicket() const; 
	double getTotal() const;
	const std::vector < Iticket >& getProducts() const;
	std::string getMetodoPago() const;
	std::string getFecha() const;
	std::string getHora() const;


//guardamos la fecha y hora del toicket
private:  
	int numTicket; 
	std::string fecha; 
	std::string hora; 
	std::vector<Iticket> products; //no confudirme plox
	double total; 
	std::string metodoPago; 
};

//el producto dentro del ticket 
struct Iticket {
	std::string nameProduct; 
	int cantidad; 
	double precioU; 
	double subtotal; 
};