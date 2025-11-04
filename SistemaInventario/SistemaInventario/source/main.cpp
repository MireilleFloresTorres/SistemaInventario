#include"Prerequisites.h"
#include"Producto/Inventario/Inventario.h"
#include"Producto/Observer/AlertaInventario.h"
#include"Producto/ProductoFactory/BebidaFactory.h"
#include"Producto/ProductoFactory/ComidaFactory.h"
#include"Producto/ProductoFactory/MedicamentoFactory.h"

int main() {
    std::ifstream archivo("Inventario.json");

    if (!archivo.is_open()) {
        std::cout << "❌ No se pudo abrir el archivo inventario.json\n";
        std::cout << "Verifica que esté en la misma carpeta que el .exe (por ejemplo, /Debug)\n";
    }
    else {
        std::cout << "✅ Archivo inventario.json encontrado correctamente.\n";
        archivo.close();
    }

    return 0;
}