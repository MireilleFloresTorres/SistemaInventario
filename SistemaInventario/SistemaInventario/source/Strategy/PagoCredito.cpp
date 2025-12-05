#include "Strategy/PagoDebito.h"

/**
 * @brief Gestiona el pago con tarjeta de credito.
 * @param monto Monto a cobrar.
 * @return true si el pago es válido false en caso contrario.
 */
bool PagoDebito::gestionarPago(double monto) {
	std::string numTarjeta;
	double admitido;
	std::cout << "Monto a pagar: " << monto << std::endl;
	std::cout << "Numero de tarjeta:  " << std::endl;
	std::cin >> numTarjeta;

	if (numTarjeta.length() < 4) {
		std::cout << "La tarejta es ivalida" << std::endl;
		return false;
	}
	std::cout << "Pago aprobado" << std::endl;

}

/**
 * @brief Obtiene el tipo de pago.
 * @return Cadena credito
 */
std::string PagoDebito::getTipo() const {
	return "Debito";
}