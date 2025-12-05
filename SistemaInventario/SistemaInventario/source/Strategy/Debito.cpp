#include "Strategy/PagoCredito.h"

/**
 * @brief Solicita número de tarjeta y verifica longitud mínima.
 */
bool PagoCredito::gestionarPago(double monto) {
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

std::string PagoCredito::getTipo() const {
	return "Credito";
}