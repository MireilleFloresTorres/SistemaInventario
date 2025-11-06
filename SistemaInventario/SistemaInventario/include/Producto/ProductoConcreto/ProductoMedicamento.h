#pragma once
/**
 * @file ProductoMedicmanto.h
 * @brief Declaración de la clase ProdcutoMedicamento
 * tiene elemnto especifico  (aministracion)
 * se refiere al la via ade adaministracion
 */
#include "Producto/Producto.h"

class
	ProductoMedicamento : public Producto {
public:

	/**
	 * @brief Constructor de ProductoComida.
	 * @param codigo Código del producto.
	 * @param nombre Nombre del producto.
	 * @param precio Precio del producto.
	 * @param cantidad Cantidad en inventario.
	 * @param caducidad Fecha de caducidad.
	 */
	ProductoMedicamento(int codigo, std::string nombre, double precio,
		int cantidad, std::string administracion);
	~ProductoMedicamento() override = default;

	/**
	* @brief Obtiene la fecha de caducidad.
	*/
	std::string getAdministracion() const; 

	/**
	 * @brief Establece la via de administracion
	 */
	void
	setAdministracion(const std:: string& administracion); 

	/**
	 * @brief se sobreescribe el metodo para mostrar infomracion
	 Muestra la información del producto.
	 */
	void
	showInfo() const override; 

	/**
	 * @brief Devuelve el tipo de producto ("Comida").
	 */
	std::string getTipo() const override;

private:
	/**
	* Decaración de la administracion
	*/
	std::string Administracion;
};