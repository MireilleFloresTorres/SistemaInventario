#pragma once
#include"Producto/Observer/Observer.h"
#include "Prerequisites.h"

class
Sujeto {
public: 
	virtual ~Sujeto() = default;
	void addObservador(Observer* observador);
	void deleteObservador(Observer* observador);
	void notificar(const std::string& alerta);

private: 
	std::vector<Observer*> observadores; 
};