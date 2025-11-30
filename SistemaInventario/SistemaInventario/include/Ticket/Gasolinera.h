#pragma once
#include"Ticket/Proveedor.h"

class
  Gasolinera {
public:
    ~Gasolinera();
    static Gasolinera* getInstance(); 
    Proveedor* getProveedor();

private:
    static Gasolinera* instance;

    Proveedor* proveedor; 
    Gasolinera();
    Gasolinera(const Gasolinera&) = delete;
    Gasolinera& operator=(const Gasolinera&) = delete;

   };