#pragma once
#include "Prerequisites.h"

class
Producto {
public: 

	virtual void showInfo() const = 0;
	virtual ~Producto() = default; 
};