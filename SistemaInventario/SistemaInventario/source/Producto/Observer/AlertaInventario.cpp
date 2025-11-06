#include"Producto/Observer/AlertaInventario.h"

/**
 * @brief Maneja la alerta recibida desde el sujeto.
 * muestra una alerta diciendo que hay bajo invetario 
 */
void AlertaInventario::actualizar(const std::string& alerta) {
	std::cout << " Queda muy poco stock en el invantario " << std::endl;
	std::cout << alerta << std::endl; 
}