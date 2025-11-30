#include "Command/ComandoCarga.h"

ComandoCarga::ComandoCarga(Proveedor* prov, TipoCombustible tip, double litros)
    : m_proveedor(prov),
    m_tipo(tip),
    m_litros(litros) {
}

void ComandoCarga::ejecutar() {
    if (m_proveedor) {
        m_proveedor->cargarCombustible(m_tipo, m_litros);
    }
}
