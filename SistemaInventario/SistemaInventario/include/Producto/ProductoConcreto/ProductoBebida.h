/**
 * @file ProductoBebida.h
 * @brief Declaración de la clase Prodcuto	Bebida 
 * es un objeto de yipo bebida 
 * tiene elemnto especifico  (azucares)
 */
#pragma once
#include "Producto/Producto.h"
 /**
  * Esta clase Hereda de Producto y añade el atributo de azucares 
  * 
  */

class
	ProductoBebida : public Producto {
public:
	/**
	* @brief Constructor de ProductoBebida.
	* @Param codigo para el id
	* @Param nombre pues para el nombre 
	* @Param precio valor de mi prodeucto
	* @Param cantidad para saber fcuántos quedan
	* @Param azucares atributo nuevo cantidad de azucares
	*/
	ProductoBebida(int codigo, std::string nombre, double precio,
		int cantidad, int azucares);

	/**
	* @brief destructor del producto bebida 
	* sobrescrito
	* destru
	*/
	~ProductoBebida() override = default;

	/**
	* getter para azucares 
	* obtenemos la cantidadd de azuares 
	*/
	int 
	getAzucares() const; 

	/**
	* set para azucares
	* se cambia la cantidadd de azuares
	*/
	void
	setAzucares(int azucares);

	/**
	* Se sobreescribe el metodo para mostrar informacion
	*/
	void showInfo() const override;

	/**
	* getter para el tipo de producto
	* obtenemos el tipod de producto
	*/
	std::string getTipo() const override;
private:

	/**
	* Declaración de los azucares
	*/
	int Azucares; 
};