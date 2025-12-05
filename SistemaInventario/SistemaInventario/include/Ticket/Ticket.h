#pragma once
#include"Prerequisites.h"

/**
 * @class Ticket
 * @brief Representa un ticket de compra con fecha, productos y método de pago.
 */
class
Ticket {
public: 

	Ticket(int numero); //constructor
	//creamos, agreganoos fachas, producto y metodo y calculo

	/**
	 * @brief Establece la fecha y hora del ticket.
	 */
	void
	setFechaHo(const std::string& f, const std::string& h);

	/**
	 * @brief Agrega un producto al ticket.
	 */
	void
	addProduct(const std::string& nombre, int cantidad, double precio); 

	/**
	* @brief Define el método de pago utilizado.
	* @param metodo Nombre del método de pago.
	*/
	void
	setMetodoPago(const std::string& metodo); 

	/**
	 * @brief Calcula el total a pagar basándose en los productos agregados.
	 */
	void calculoTotal(); 

	/**
	 * @brief Obtiene el número del ticket.
	 * Están los getters.
	 */
	int getnumTicket() const; 
	double getTotal() const;
	const std::vector<Iticket>& getProducts() const;
	std::string getMetodoPago() const;
	std::string getFecha() const;
	std::string getHora() const;

/**
* @brief variables privatizadas
*/
//guardamos la fecha y hora del toicket
private:  
	int numTicket; 
	std::string fecha; 
	std::string hora; 
	std::vector<Iticket> products; //no confudirme plox
	double total; 
	std::string metodoPago; 
};
