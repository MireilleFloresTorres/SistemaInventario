#pragma once
/**
*Foward key  de las clases producjtos concretos
*/
class ProductoComida;
class ProductoBebida;
class ProductoMedicamento; 

/**
 * @class Fabrica abstracta
 * @brief Clase abstracta que representa un producto genérico.
 * es virtual puro
 */

class
FabricaAbstracta {
public: 

	/**
	 * @brief metodo virtual para crear obejto del tipo comida
	 * instancia un objeto concreto para a comida
	 */
	virtual
	ProductoComida* crearProductoComida() const = 0; 

	/**
	 * @brief metodo virtual para crear obejto del tipo comida
	 * instancia un objeto concreto para a bebida
	 * @return puntero al objeto Producto Bebida
	 */
	virtual 
	ProductoBebida* crearProductoBebida() const = 0;
	/**
	 * @brief metodo virtual para crear obejto del tipo comida
	 * instancia un objeto concreto para a medicamento
	 * @return puntero al objeto ProductoMedicaemnto
	 */
	virtual 
	ProductoMedicamento* crearProductoMedicamento() const = 0;

	/**
	 * @brief Destructor virtual.
	 */
	virtual
	~FabricaAbstracta() = default; 
};