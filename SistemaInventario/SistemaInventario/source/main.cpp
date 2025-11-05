#include "Prerequisites.h"
#include "Producto/Inventario/Inventario.h"
#include "Producto/Observer/AlertaInventario.h"
#include "Producto/ProductoFactory/BebidaFactory.h"
#include "Producto/ProductoFactory/ComidaFactory.h"
#include "Producto/ProductoFactory/MedicamentoFactory.h"

int main() {
    // Singleton
    Inventario* inventario = Inventario::getInstance();

    // Crear observador para alertas de inventario bajo
    AlertaInventario* alertaInventario = new AlertaInventario();
    inventario->addObservador(alertaInventario);

    // Cargar inventari
    std::cout << "Cargando Inventario ..." << std::endl;
    inventario->cargarJSON("inventario.json");

    int opcion;

    do {
        std::cout << "Inventario Farmacia Guadalajara" << std::endl;
        std::cout << "1. Agregue un producto" << std::endl;
        std::cout << "2. Edite un producto" << std::endl;
        std::cout << "3. Eliminar un producto" << std::endl;
        std::cout << "4. vender producto" << std::endl;
        std::cout << "5. Comprar producto" << std::endl;
        std::cout << "6. Mostrar el inventario" <<std::endl;
        std::cout << "7. Guardar el inventario" << std::endl;
        std::cout << "8. Cargar inventario" << std::endl;
        std::cout << "9. Salir" << std::endl;
        std::cout << "Selecciona una opción: ";

        std::cin >> opcion;

        switch (opcion) {
        case 1: {
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

        case 2: { // editar
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

        case 3: { //eliminar
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

        case 4: { // la vendimia
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

        case 5: { // COMPRAR
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

        case 6: { // MOSTRAR
            inventario->mostrarTodos();
            break;
        }

        case 7: { // GUARDAR JSON
            inventario->saveJSON("Inventario.json");
            std::cout << "El inventario ha sido guardado." << std::endl;
            break;
        }

        case 8: { // CARGAR JSON
            inventario->cargarJSON("Inventario.json");
            std::cout << "El inventario ha sido cargado." << std::endl;
            break;
        }

        case 9: {
            std::cout << "\nDeseas guardar el inventario antes de salir? (s/n): ";
            char respuesta;
            std::cin >> respuesta;
            if (respuesta == 's' || respuesta == 'S') {
                //que de igual la mayuscula
                inventario->saveJSON("Inventario.json");
                std::cout << "El inventario ha sido guardado." << std::endl;
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