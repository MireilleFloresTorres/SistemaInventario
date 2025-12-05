#pragma once
#include"Prerequisites.h"
#include "Command/Command.h"
#include "Ticket/Proveedor.h"

/**
 * @class ComandoCarga
 * @brief Comando que registra una carga de gasolain a un proveedor.
 */
class ComandoCarga : public Command {

public:
    /**
     * @brief Construye el comando de carga.
     * @param prov Proveedor al que se asignará la carga.
     * @param tip Tipo de combustible a cargar.
     * @param litros Cantidad de litros cargados.
     */
    ComandoCarga(Proveedor* prov, TipoCombustible tip, double litos);

    /**
     * @brief Ejecuta la acción de registrar la carga.
     */
    void ejecutar() override;

private:
    Proveedor* m_proveedor; ///< Proveedor 
    TipoCombustible m_tipo;  ///< Tipo de combustible cargado.
    double m_litros;

};