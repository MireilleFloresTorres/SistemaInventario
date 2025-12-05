#include "Strategy/PagoEfectivo.h"

/**
 * @brief Procesa el pago en efectivo.
 * @param monto Monto total a cobrar.
 * @return true si el pago es aceptado; false si el dinero es insuficiente.
 */
bool PagoEfectivo::gestionarPago(double monto) {
	double admitido;
	std::cout << "Monyo a pagar: " << monto << std::endl;
	std::cout << "Monto recibido en efecrtivo: " << std::endl;
	std::cin >> admitido;

	if (admitido < monto) {
		std::cout << "El dinero es insuficiente" << std::endl;
		return false;
	}

	double cambio = admitido - monto;
	std::cout << "Cmabio: " << cambio << std::endl;

}

std::string PagoEfectivo::getTipo() const {
	return "Efectivo"; 
}