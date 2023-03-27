#pragma warning(disable : 4996)
#include "Cotizacion.h"

#include <iostream>
#include <sstream>
#include "ctime"

Cotizacion::Cotizacion() 
{

}

void Cotizacion::SetFecha() 
{
    time_t t;
    t = time(NULL);
    tm* f;
    f = localtime(&t);
    Fecha aux;
    aux.Day = f->tm_mday;
    aux.Month = f->tm_mon + 1;
    aux.Year = f->tm_year + 1900;
    aux.hour = f->tm_hour;
    aux.Minute = f->tm_min;
    FechaDeCotizacion = ParseString(aux.Day) + "/" + ParseString(aux.Month) + "/" + ParseString(aux.Year) + "  " + ParseString(aux.hour) + ":" + ParseString(aux.Minute);
}

std::string Cotizacion::GetFechaCotizacion() const
{
    return FechaDeCotizacion;
}

std::string Cotizacion::ParseString(int Valor) 
{
    std::ostringstream aux;
    aux << Valor;
    return aux.str();
}

long long int Cotizacion::getNumeroId() 
{
    return NumeroId;
}

void Cotizacion::SetNumeroId()
{
    time_t t;
    t = time(NULL);
    NumeroId = t;
}

Prenda* Cotizacion::getPrendaCotizada() const 
{
    return PrendaCotizada;
}

void Cotizacion::setPrendaCotizada(Prenda* prendaCotizada) 
{
    PrendaCotizada = prendaCotizada;
}

int Cotizacion::GetCantidadDeUnidades() const
{
    return CantidadDeUnidadesCotizadas;
}

void Cotizacion::SetCantidadDeUnidades(int cantidaddeunidades)
{
    CantidadDeUnidadesCotizadas = cantidaddeunidades;
}

float Cotizacion::getPrecioUnitario() const
{
    return PrecioUnitario;
}

void Cotizacion::setPrecioUnitario(float precioUnitario)
{
    PrecioUnitario = precioUnitario;
}

float Cotizacion::getPrecioFinal() const
{
    return PrecioFinal;
}

void Cotizacion::setPrecioFinal(float precioFinal)
{
    PrecioFinal = precioFinal;
}


