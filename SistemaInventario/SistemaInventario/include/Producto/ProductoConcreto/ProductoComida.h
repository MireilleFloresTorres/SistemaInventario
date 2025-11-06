/**
 * @file ProductoComida.h
 * @brief Declaración de la clase Prodcuto Comida
 * tiene elemnto especifico  (caducidad)
 */
#pragma once
#include "Producto/Producto.h"

class
 ProductoComida: public Producto {
public: 

	/**
	 * @brief Constructor de ProductoComida.
	 * @param codigo Código del producto.
	 * @param nombre Nombre del producto.
	 * @param precio Precio del producto.
	 * @param cantidad Cantidad en inventario.
	 * @param caducidad Fecha de caducidad.
	 */
	ProductoComida(int codigo, std::string nombre, double precio, 
		int cantidad, std::string caducidad);

	~ProductoComida() override = default;

	/**
	* @brief Obtiene la fecha de caducidad.
	*/
	std::string getCaducidad() const; 
	/**
	 * @brief Establece la fecha de caducidad.
	 */
	void 
	setCaducidad(const std::string& fecha);

	/**
	 * @brief se sobreescribe el metodo para mostrar infomracion
	 Muestra la información del producto.
	 */
	void 
	showInfo() const override;   

	/**
	 * @brief Devuelve el tipo de producto ("Comida").
	 */
	std::string 
	getTipo() const override;

private: 
	/**
	* Decaración de la caducidad
	*/
	std::string Caducidad; 
};