#pragma once
#include "Prerequisites.h"

class
Producto {
public: 

	virtual void ShowInfo() const = 0;
	virtual ~Producto() = default; 
};