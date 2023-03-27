#include "Prenda.h"

Prenda::Prenda() 
{

    CalidadDePrenda = ECalidad::Defa;
    Nombre = "";
}

ECalidad Prenda::getCalidadDePrenda() const 
{
    return CalidadDePrenda;
}

void Prenda::setCalidadDePrenda(ECalidad calidadDePrenda) 
{
    CalidadDePrenda = calidadDePrenda;
    if (CalidadDePrenda == ECalidad::Premium)
    {
        Calidad = "Premium";
    }
    if (CalidadDePrenda == ECalidad::Standard)
    {
        Calidad = "Standard";
    }
}

const std::string& Prenda::getCalidad() const 
{
    return Calidad;
}

const std::string& Prenda::getNombre() const 
{
    return Nombre;
}


