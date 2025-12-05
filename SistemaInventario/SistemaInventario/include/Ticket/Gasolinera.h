#pragma once
#include"Ticket/Proveedor.h"
/**
 * @class Gasolinera
 * @brief Singleton que administra un proveedor de combustible.
 */
class
  Gasolinera {
public:
    //destructor
    ~Gasolinera();
    /** @brief Devuelve la instancia única de la gasolinera. */
    static Gasolinera* getInstance(); 
    /** @brief Obtiene el proveedor asociado. */
    Proveedor* getProveedor();

private:
    static Gasolinera* instance; ///< Instancia única.
    Proveedor* proveedor;  ///< Proveedor de combustible.
    Gasolinera();
    Gasolinera(const Gasolinera&) = delete;
    Gasolinera& operator=(const Gasolinera&) = delete;

   };