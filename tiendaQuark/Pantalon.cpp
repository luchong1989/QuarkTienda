#include "Pantalon.h"

Pantalon::Pantalon() 
{

    Tipo = ETipo::DefaultMax;
    Nombre = "Pantalon";
}

void Pantalon::setTipo(ETipo tipo) 
{
    Tipo = tipo;
    if (Tipo == ETipo::Chupines)
    {
        this->tipo = "Chupines";
    }
    if (Tipo == ETipo::Comunes)
    {
        this->tipo = "Comunes";
    }
}

const std::string& Pantalon::getTipo() const 
{
    return tipo;
}
