#include"Prerequisites.h"
#include"Producto/Observer/Sujeto.h"

void Sujeto::addObservador(Observer* observador) {
	observadores.push_back(observador);
}

void Sujeto::notificar(const std::string& alerta) {
	for (auto observador : observadores)
	{
		observador->actualizar(alerta);
	} 
}

void Sujeto::deleteObservador(Observer* observador) {
	for (size_t i = 0; i < observadores.size(); i++) {
		if (observadores[i] == observador) {
			observadores[i] = observadores.back();
			observadores.pop_back();
			break;
		}
	}
}