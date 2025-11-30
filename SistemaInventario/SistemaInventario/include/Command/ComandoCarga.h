#pragma once
#include"Prerequisites.h"
#include "Command/Command.h"
#include "Ticket/Proveedor.h"

class ComandoCarga : public Command {

public:
    ComandoCarga(Proveedor* prov, TipoCombustible tip, double litos);
    void ejecutar() override;

private:
    Proveedor* m_proveedor;
    TipoCombustible m_tipo;
    double m_litros;

};