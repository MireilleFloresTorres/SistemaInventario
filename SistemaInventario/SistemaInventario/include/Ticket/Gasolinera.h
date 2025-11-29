#pragma once

class
  Gasolinera {
public:
    ~Gasolinera();

private:
    static Gasolinera* instance;


    Gasolinera();
    Gasolinera(const Gasolinera&) = delete;
    Gasolinera& operator=(const Gasolinera&) = delete;

   };