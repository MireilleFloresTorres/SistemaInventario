#pragma once
#include "Prerequisites.h"

class
Observer {
public: 
	virtual ~Observer() = default; 
	virtual void actualizar(const std::string& alerta) = 0; 
};