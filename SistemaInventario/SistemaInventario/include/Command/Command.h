#pragma once

/**
 * @class Command
 * @brief Interfaz base del patrón Command.
 *
 * Define la operación que deben implementar todos los comandos.
 */
class 
 Command {
public:

    //destructor
    virtual ~Command() = default;

    /**
    * @brief Ejecuta la acción del comando.
    */
    virtual void ejecutar() = 0;
};