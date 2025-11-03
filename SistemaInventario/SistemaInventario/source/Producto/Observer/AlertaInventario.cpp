#include"Producto/Observer/AlertaInventario.h"

void AlertaInventario::actualizar(const std::string& alerta) {
	std::cout << " Queda muy poco stock en el invantario " << std::endl;
	std::cout << alerta << std::endl; 
}