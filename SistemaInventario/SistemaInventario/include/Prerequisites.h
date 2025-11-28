#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include <algorithm>
#include "json.hpp"
using json = nlohmann::json;
#include <ctime>

//el producto dentro del ticket 
struct Iticket {
	std::string nameProduct;
	int cantidad;
	double precioU;
	double subtotal;
};


struct 
Fecha {
	int dia; 
	int mes; 
	int anio; 
	int hora; 
	int minuto; 

	void
		getActual() {
		time_t t = time(0);
		tm now;
		if (localtime_s(&now, &t) == 0) {
			dia = now.tm_mday;
			mes = now.tm_mon + 1;
			anio = now.tm_year + 1900;
			hora = now.tm_hour;
			minuto = now.tm_min;
		}
		else {
			std::cerr << "Ups! Hubo un error con la fecha" << std::endl;
		}
	}

		std::string toStringFecha() const {
			return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
		}

		std::string toStringHora() const {
			std::string h = (hora < 10 ? "0" : "") + std::to_string(hora);
			std::string m = (minuto < 10 ? "0" : "") + std::to_string(minuto);
			return h + ":" + m;
		}
};
