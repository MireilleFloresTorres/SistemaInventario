#include "Facade/SistemaFacade.h"
#include "Ticket/GenerarTicket.h"
#include "Ticket/CrearTicketGasolina.h"
#include "Ticket/Correo.h"
#include "Strategy/PagoEfectivo.h"
#include "Strategy/PagoDebito.h"
#include "Strategy/PagoCredito.h"
#include "Command/ComandoCarga.h"

SistemaFacade* SistemaFacade::instance = nullptr;

SistemaFacade::SistemaFacade() {
    inventario = Inventario::getInstance();
    gasolinera = Gasolinera::getInstance();
}

SistemaFacade::~SistemaFacade() {}

SistemaFacade* SistemaFacade::getInstance() {
    if (instance == nullptr) {
        instance = new SistemaFacade();
    }
    return instance;
}

Inventario* SistemaFacade::getInventario() {
    return inventario;
}

bool SistemaFacade::procesarVentaFarmacia(int codigoProducto, int cantidad, int metodoPago, const std::string& correo) {
    // 1. Buscar producto
    Producto* producto = inventario->buscarProducto(codigoProducto);
    if (!producto) {
        std::cout << "Producto no encontrado" << std::endl;
        return false;
    }

    // 2. Verificar stock
    if (producto->getCantidad() < cantidad) {
        std::cout << "Stock insuficiente" << std::endl;
        return false;
    }

    // 3. Crear ticket
    int numTicket = GenerarTicket::getNum();
    Ticket ticket(numTicket);

    Fecha fecha;
    fecha.getActual();
    ticket.setFechaHo(fecha.toStringFecha(), fecha.toStringHora());

    // 4. Agregar producto al ticket
    ticket.addProduct(producto->getNombre(), cantidad, producto->getPrecio());

    // 5. Configurar método de pago
    std::string metodo;
    if (metodoPago == 1) metodo = "Efectivo";
    else if (metodoPago == 2) metodo = "Debito";
    else metodo = "Credito";
    ticket.setMetodoPago(metodo);

    // 6. Calcular total
    ticket.calculoTotal();

    // 7. Actualizar inventario
    producto->setCantidad(producto->getCantidad() - cantidad);

    // 8. Generar archivo
    GenerarTicket::generarArchivo(ticket);

    // 9. Enviar por correo si se proporcionó
    if (!correo.empty()) {
        Correo::facturaCorreo(ticket, correo);
    }

    std::cout << "\nVenta procesada exitosamente" << std::endl;
    std::cout << "Total: $" << ticket.getTotal() << std::endl;

    return true;
}

bool SistemaFacade::procesarCargaGasolinera(int tipoCombustible, double litros, int metodoPago, const std::string& correo) {
    // 1. Obtener surtidor
    Proveedor* proveedor = gasolinera->getProveedor();

    // 2. Determinar tipo de combustible
    TipoCombustible tipo;
    std::string nombreTipo;
    if (tipoCombustible == 1) {
        tipo = TipoCombustible::MAGNA;
        nombreTipo = "Magna";
    }
    else if (tipoCombustible == 2) {
        tipo = TipoCombustible::PREMIUM;
        nombreTipo = "Premium";
    }
    else {
        tipo = TipoCombustible::DIESEL;
        nombreTipo = "Diesel";
    }

    // 3. Configurar estrategia de pago
    PagoStrategy* estrategia = nullptr;
    std::string nombreMetodo;
    std::string mesesStr = "1 Exhibicion";

    if (metodoPago == 1) {
        estrategia = new PagoEfectivo();
        nombreMetodo = "Efectivo";
    }
    else if (metodoPago == 2) {
        estrategia = new PagoDebito();
        nombreMetodo = "Debito";
    }
    else {
        estrategia = new PagoCredito();
        nombreMetodo = "Credito";
        std::cout << "Meses sin intereses (3, 6, 12): ";
        int meses;
        std::cin >> meses;
        mesesStr = std::to_string(meses) + " Meses Sin Intereses";
    }

    proveedor->setPagoStrategy(_strategy);

    // 4. Ejecutar carga usando Command
    ComandoCarga comando(proveedor, tipo, litros);
    comando.ejecutar();

    // 5. Crear ticket
    int numTicket = CrearTicketGasolina::getNum();
    TicketGasolinera ticket(numTicket);

    Fecha fecha;
    fecha.getActual();
    ticket.setFechaHora(fecha.toStringFecha(), fecha.toStringHora());

    ticket.setCombustible(nombreTipo, litros, Proveedor->getPrecio(tipo));
    ticket.setMetodoPago(nombreMetodo, mesesStr);

    // 6. Número de autorización si no es efectivo
    if (metodoPago != 1) {
        ticket.setNumeroAutorizacion("AUTH" + std::to_string(rand() % 1000000));
    }

    // 7. Calcular totales
    ticket.calcularTotal();

    // 8. Generar archivo
    CrearTicketGasolina::generarArchivo(ticket);

    // 9. Enviar por correo si se proporcionó
    if (!correo.empty()) {
        ticket.setCorreo(correo);
        std::cout << "Factura enviada a " << correo << std::endl;
    }

    std::cout << "\nLa carga ha sifo procesada" << std::endl;

    return true;
}