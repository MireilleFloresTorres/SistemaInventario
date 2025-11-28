#include "Strategy/PagoEfectivo.h"

bool PagoEfectivo::gestionarPago(double monto) {
	double admitido;
	std::cout << "Monyo a pagar: " << monto << std::endl;
	atsd::"Monto recibido en efecrtivo: "std::endl; 
	std::cin >> admitido; 

	if (admitido < monto) {
		std::cout << "El dinero es insuficiente" << std::endl; 
		return false;
	}


}