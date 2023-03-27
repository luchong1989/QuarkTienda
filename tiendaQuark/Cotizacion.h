#pragma once
#include <string>
#include "Prenda.h"

class Prenda;
struct Fecha 
{
    int Day, Month, Year, hour, Minute;
};

class Cotizacion 
{

public:
    Cotizacion();

    void SetFecha();
    std::string GetFechaCotizacion() const;
    std::string ParseString(int Valor);

    long long int getNumeroId();

    Prenda* getPrendaCotizada() const;

    void setPrendaCotizada(Prenda* prendaCotizada);

    int GetCantidadDeUnidades() const;
    void SetCantidadDeUnidades(int cantidaddeunidades);
    float getPrecioUnitario() const;
    void setPrecioUnitario(float precioUnitario);
    float getPrecioFinal() const;
    void setPrecioFinal(float precioFinal);
    void SetNumeroId();

private:
    long long int NumeroId = 0;
    std::string FechaDeCotizacion;
    Prenda* PrendaCotizada;
    int CantidadDeUnidadesCotizadas = 0;
    float PrecioUnitario = 0.f;
    float PrecioFinal = 0.f;
    
};
