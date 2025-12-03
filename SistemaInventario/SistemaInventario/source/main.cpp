#include "Prerequisites.h"
#include "Producto/Inventario/Inventario.h"
#include "Producto/Observer/AlertaInventario.h"
#include "Producto/ProductoFactory/BebidaFactory.h"
#include "Producto/ProductoFactory/ComidaFactory.h"
#include "Producto/ProductoFactory/MedicamentoFactory.h"

#include "Facade/SistemaFacade.h"
#include "Ticket/Ticket.h"
#include "Ticket/GenerarTicket.h"
#include "Ticket/Correo.h"
#include "Ticket/Gasolinera.h"


/**
 * @file main.cpp
 * @file Inventario.h
 * @file AlertaInventario.h
 * @file BebidaFactory.h
 * @file ComidaFactory.h
 * @file MedicamentoFactory.h
 * @brief Sistema de gestión de inventario para Farmacia Guadalajara
 * @details Implementa un menú interactivo para administrar productos (comida, bebida, medicamento)
 */

 /**
  * @brief Entrada del mamin en consola
  * @return código de salida0
  *
  * @details Crea una instancia única del inventario, configura observadores para alertas
  *          de stock bajo, con un menú con las siguientes opciones:
  *          - Agregar productos (comida, bebida, medicamento)
  *          - Editar productos existentes
  *          - Eliminar productos
  *          - Realizar ventas
  *          - Realizar compras
  *          - Mostrar inventario completo
  *          - Guardar datos en JSON
  */
int main() {
    
    Inventario* inventario = Inventario::getInstance();
    SistemaFacade* sistema = SistemaFacade::getInstance();

    // Crear observador para alertas de inventario bajo
    AlertaInventario* alertaInventario = new AlertaInventario();
    inventario->addObservador(alertaInventario);

    // Cargar inventari
    std::cout << "Cargando Inventario ..." << std::endl;
    inventario->cargarJSON("inventario.json");

    int opcion;

    do {
        std::cout << "SUPERMARKET" << std::endl;
        //ya dejo de ser farmacia, ni modo
        std::cout << "1. Agregue un producto" << std::endl;
        std::cout << "2. Edite un producto" << std::endl;
        std::cout << "3. Eliminar un producto" << std::endl;
        std::cout << "4. vender producto" << std::endl;
        std::cout << "5. Comprar producto" << std::endl;
        std::cout << "6. Mostrar el inventario" <<std::endl;
        std::cout << "7. Guardar el inventario" << std::endl;
        std::cout << "8. Cargar inventario" << std::endl;
        std::cout << "9. Venta rapida con ticket "<< std::endl;
        std::cout << "10. Carga gasolinera rapida " << std::endl;
        std::cout << "11. Salir" << std::endl;
        std::cout << "Selecciona una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {/** @brief Agregar nuevo producto al inventario */
            int tipo;
            std::cout << "Tipo de producto:" << std::endl;
            std::cout << "1. Comida" << std::endl;
            std::cout << "2. Bebida" << std::endl;
            std::cout << "3. Medicamento" << std::endl;
            std::cout << "Selecciona: ";
            std::cin >> tipo;

            // coso del id
            int codigo = Inventario::getNextId();
            std::cout << "id asignado: " << codigo << "]" << std::endl;

            std::string nombre;
            double precio;
            int cantidad;

            std::cin.ignore();
            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);
            std::cout << "Precio: ";
            std::cin >> precio;
            std::cout << "Cantidad: ";
            std::cin >> cantidad;

            Producto* producto = nullptr;

            if (tipo == 1) {
                std::string Caducidad;
                std::cout << "Fecha de caducidad (YYYY-MM-DD): ";
                std::cin >> Caducidad;
                ComidaFactory fabrica(codigo, nombre, precio, cantidad, Caducidad);
                producto = fabrica.crearProducto();
            }
            else if (tipo == 2) {
                int Azucares;
                std::cout << "Azucares (gramos): ";
                std::cin >> Azucares;
                BebidaFactory fabrica(codigo, nombre, precio, cantidad, Azucares);
                producto = fabrica.crearProducto();
            }
            else if (tipo == 3) {
                std::string Administracion;
                std::cin.ignore();
                std::cout << "Via de administracion: ";
                std::getline(std::cin, Administracion);
                MedicamentoFactory fabrica(codigo, nombre, precio, cantidad, Administracion);
                producto = fabrica.crearProducto();
            }

            if (producto) {
                inventario->addProducto(producto);
                std::cout << "El producto ha sido agregado." << std::endl;
            }
            else {
                std::cout << "No se pudo agregar el producto." << std::endl;
            }
            break;
        }

        case 2: { /** @brief Editar producto existente por código */
            int codigo;
            std::cout << "Codigo del producto a editar: ";
            std::cin >> codigo;

            if (inventario->editarProducto(codigo)) {
                std::cout << "El producto ha sido editado." << std::endl;
            }
            else {
                std::cout << "No se pudo editar el producto." << std::endl;
            }
            break;
        }

        case 3: { /** @brief Eliminar producto del inventario */
            int codigo;
            std::cout << "Codigo del producto a eliminar: ";
            std::cin >> codigo;

            if (inventario->deleteProducto(codigo)) {
                std::cout << "El producto ha sido eliminado." << std::endl;
            }
            else {
                std::cout << "No se pudo eliminar el producto." << std::endl;
            }
            break;
        }

        case 4: { /** @brief Realizar venta y reducir stock */
            int codigo;
            int cantidad;
            std::cout << "Codigo del producto: ";
            std::cin >> codigo;
            std::cout << "Cantidad a vender: ";
            std::cin >> cantidad;

            if (inventario->venderProducto(codigo, cantidad)) {
                std::cout << "La venta ha sido realizada." << std::endl;
            }
            else {
                std::cout << "No se pudo realizar la venta." << std::endl;
            }
            break;
        }

        case 5: { /** @brief Realizar compra e incrementar stock */
            int codigo;
            int cantidad;
            std::cout << "Codigo del producto: ";
            std::cin >> codigo;
            std::cout << "Cantidad a comprar: ";
            std::cin >> cantidad;

            if (inventario->comprarProducto(codigo, cantidad)) {
                std::cout << "La compra ha sido realizada." << std::endl;
            }
            else {
                std::cout << "No se pudo realizar la compra." << std::endl;
            }
            break;
        }

        case 6: { /** @brief Mostrar todos los productos del inventario */
            inventario->mostrarTodos();
            break;
        }

        case 7: { /** @brief Guardar inventario en archivo JSON */
            inventario->saveJSON("Inventario.json");
            std::cout << "El inventario ha sido guardado." << std::endl;
            break;
        }

        case 8: { /** @brief Cargar inventario desde archivo JSON */
            inventario->cargarJSON("Inventario.json");
            std::cout << "El inventario ha sido cargado." << std::endl;
            break;
        }

        case 9: { // 
            if (inventario->getProductos().empty()) {
                std::cout << "Inventario vacio" << std::endl;
                break;
            }

            int codigo, cantidad, metodo;
            std::string correo;

            std::cout << "\n venta rapida " << std::endl;
            std::cout << "Codigo del producto: ";
            std::cin  >> codigo;
            std::cout << "Cantidad: ";
            std::cin  >> cantidad;

            std::cout << "\nMetodo de pago:" << std::endl;
            std::cout << "1. Efectivo" << std::endl;
            std::cout << "2. Debito" << std::endl;
            std::cout << "3. Credito" << std::endl;
            std::cout << "Elige una opcion: ";
            std::cin  >> metodo;

            std::cout << "Desea una factura por correo? (s/n): ";
            char enviar;
            std::cin  >> enviar;

            if (enviar == 's' || enviar == 'S') {
                std::cout << "Correo: ";
                std::cin  >> correo;
            }

            //mi facade
            sistema->procesarVentaFarmacia(codigo, cantidad, metodo, correo);
            break;
        }

        case 10: { // gasolinara
            int tipo, metodo;
            double litros;
            std::string correo;

            std::cout << "\nCarga de gasolina" << std::endl;
            std::cout << "Tipo de gasonlia:" << std::endl;
            std::cout << "1. Magna $22.50/L" << std::endl;
            std::cout << "2. Premium $24.80/L" << std::endl;
            std::cout << "3. Diesel $25.10/L" << std::endl;
            std::cout << "Selecciona: ";
            std::cin  >> tipo;

            std::cout << "Litros: ";
            std::cin  >> litros;

            std::cout << "\nMetodo de pago:" << std::endl;
            std::cout << "1. Efectivo" << std::endl;
            std::cout << "2. Debito" << std::endl;
            std::cout << "3. Credito" <<std:: endl;
            std::cout << "Selecciona: ";
            std::cin  >> metodo;

            std::cout << "Desea su factura por correo? (s/n): ";
            char enviar;
            std::cin  >> enviar;

            if (enviar == 's' || enviar == 'S') {
                std::cout << "Correo: ";
                std::cin  >> correo;
            }

            sistema->procesarCargaGasolinera(tipo, litros, metodo, correo);
            break;
        }

        case 11: { // SALIR
            std::cout << "\nDeseas guardar el inventario antes de salir? (s/n): ";
            char respuesta;
            std::cin  >> respuesta;
            if (respuesta == 's' || respuesta == 'S') {
                inventario->saveJSON("inventario.json");
            }
            std::cout << "Saliendo del sistema..." << std::endl;
            break;
        }

        default:
            std::cout << "Opcion invalida :(" << std::endl;
        }

    } while (opcion != 9);

    // Limpiar memoria
    delete alertaInventario;
    delete inventario;

    return 0;
}