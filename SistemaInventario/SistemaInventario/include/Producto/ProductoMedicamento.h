#pragma once
#include "Prerequisites.h"
#include "Producto/Producto.h"

class
	ProductoMedicamento {
public:

	ProductoMedicamento(int id, int cantidad, double precio, const std::string& nombre);

	virtual void operacionMedicamento() const = 0;
	virtual ~ProductoMedicamento() = default;

	int getId() const;
	int getCantidad() const;
	double getPrecio() const;
	std::string getNombre() const;

	void setCantidad(int cantidad);
	void setId(int id);
	void setPrecio(double precio);

	void addStock(int _cantidad);
	void reducirStock(int _cantidad);
	void showInfo() const;

private:
	int id;
	int cantidad;
	double precio;
	std::string nombre;
};