#pragma once
#include"Producto/Observer/Observer.h"
#include"Prerequisites.h"

/**
 * @class AlertaInventario
 * @brief Observador que responde a notificaciones de inventario.
 * Las clase recibe las aleertas desde un sejuto
 * entonces actua si hay un bajo nivel se stock muestra un mensaje
 */
class
	AlertaInventario : public Observer {
public: 
	/**
 * @class AlertaInventario
 * @brief Observador que responde a notificaciones de inventario.
 */
	void actualizar(const std::string& alerta) override; 
};